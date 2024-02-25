//
//  Extensions.swift
//  NFSKit
//
//  Created by alexiscn on 2021/7/17.
//

import Foundation
import nfs

extension Optional {
    func unwrap() throws -> Wrapped {
        guard let self else {
            throw POSIXError(.ENODATA, description: "Invalid/Empty data.")
        }
        return self
    }
}

extension Optional where Wrapped: NFSContext {
    func unwrap() throws -> NFSContext {
        guard let self, self.fileDescriptor >= 0 else {
            throw POSIXError(.ENOTCONN, description: "NFS server not connected.")
        }
        return self
    }
}

extension POSIXError {
    static func throwIfError(_ result: some SignedInteger, description: String?) throws {
        guard result < 0 else { return }
        let errno = Int32(-result)
        let errorDesc = description.map { "Error code \(errno): \($0)" }
        throw POSIXError(.init(errno), description: errorDesc)
    }

    init(_ code: POSIXError.Code, description: String?) {
        let userInfo: [String: Any] = description.map { [NSLocalizedFailureReasonErrorKey: $0] } ?? [:]
        self = POSIXError(code, userInfo: userInfo)
    }
}

extension POSIXErrorCode {
    init(_ code: Int32) {
        self = POSIXErrorCode(rawValue: code) ?? .ECANCELED
    }
}

public extension [URLResourceKey: Any] {
    var name: String? {
        self[.nameKey] as? String
    }

    var path: String? {
        self[.pathKey] as? String
    }

    var fileResourceType: URLFileResourceType? {
        self[.fileResourceTypeKey] as? URLFileResourceType
    }

    var isDirectory: Bool {
        self[.isDirectoryKey] as? Bool ?? false
    }

    var isRegularFile: Bool {
        self[.isRegularFileKey] as? Bool ?? false
    }

    var isSymbolicLink: Bool {
        self[.isSymbolicLinkKey] as? Bool ?? false
    }

    var fileSize: Int64? {
        self[.fileSizeKey] as? Int64
    }

    var attributeModificationDate: Date? {
        self[.attributeModificationDateKey] as? Date
    }

    var contentModificationDate: Date? {
        self[.contentModificationDateKey] as? Date
    }

    var contentAccessDate: Date? {
        self[.contentAccessDateKey] as? Date
    }

    var creationDate: Date? {
        self[.creationDateKey] as? Date
    }
}

extension [[URLResourceKey: Any]] {
    func sortedByPath(_ comparison: ComparisonResult) -> [[URLResourceKey: Any]] {
        sorted {
            guard let firstPath = $0.path, let secPath = $1.path else {
                return false
            }
            return firstPath.localizedStandardCompare(secPath) == comparison
        }
    }

    var overallSize: Int64 {
        reduce(0) { result, value -> Int64 in
            guard value.isRegularFile else { return result }
            return result + (value.fileSize ?? 0)
        }
    }
}

extension Date {
    init(_ timespec: timespec) {
        self.init(timeIntervalSince1970: TimeInterval(timespec.tv_sec) + TimeInterval(timespec.tv_nsec / 1000) / TimeInterval(USEC_PER_SEC))
    }
}

extension Data {
    mutating func append(value: some FixedWidthInteger) {
        var value = value.littleEndian
        let bytes = Swift.withUnsafeBytes(of: &value) { Array($0) }
        append(contentsOf: bytes)
    }

    mutating func append(value uuid: UUID) {
        // Microsoft GUID is mixed-endian
        append(contentsOf: [uuid.uuid.3, uuid.uuid.2, uuid.uuid.1, uuid.uuid.0,
                            uuid.uuid.5, uuid.uuid.4, uuid.uuid.7, uuid.uuid.6,
                            uuid.uuid.8, uuid.uuid.9, uuid.uuid.10, uuid.uuid.11,
                            uuid.uuid.12, uuid.uuid.13, uuid.uuid.14, uuid.uuid.15])
    }

    func scanValue<T: FixedWidthInteger>(offset: Int, as _: T.Type) -> T? {
        guard count >= offset + MemoryLayout<T>.size else { return nil }
        return T(littleEndian: withUnsafeBytes { $0.load(fromByteOffset: offset, as: T.self) })
    }

    func scanInt<T: FixedWidthInteger>(offset: Int, as _: T.Type) -> Int? {
        scanValue(offset: offset, as: T.self).map(Int.init)
    }
}

extension String {
    var canonical: String {
        trimmingCharacters(in: .init(charactersIn: "/\\"))
    }
}

extension Stream {
    func withOpenStream(_ handler: () throws -> Void) rethrows {
        let shouldCloseStream = streamStatus == .notOpen
        if streamStatus == .notOpen {
            open()
        }
        defer {
            if shouldCloseStream {
                close()
            }
        }
        try handler()
    }
}

extension InputStream {
    func readData(maxLength length: Int) throws -> Data {
        var buffer = [UInt8](repeating: 0, count: length)
        let result = read(&buffer, maxLength: buffer.count)
        if result < 0 {
            throw streamError ?? POSIXError(.EIO, description: "Unknown stream error.")
        } else {
            return Data(buffer.prefix(result))
        }
    }
}

extension OutputStream {
    func write(_ data: some DataProtocol) throws -> Int {
        var buffer = Array(data)
        let result = write(&buffer, maxLength: buffer.count)
        if result < 0 {
            throw streamError ?? POSIXError(.EIO, description: "Unknown stream error.")
        } else {
            return result
        }
    }
}
