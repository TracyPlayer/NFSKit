//
//  NFSDirectory.swift
//  NFSKit
//
//  Created by alexiscn on 2021/7/18.
//

import Foundation
import nfs

/// NO THREAD-SAFE
final class NFSDirectory: Collection {
    private var context: NFSContext
    private var handle: UnsafeMutablePointer<nfsdir>

    init(_ path: String, on context: NFSContext) throws {
        let (_, handle) = try context.async_await(dataHandler: Parser.toOpaquePointer) { context, cbPtr -> Int32 in
            nfs_opendir_async(context, path, NFSContext.generic_handler, cbPtr)
        }

        self.context = context
        self.handle = UnsafeMutablePointer<nfsdir>(handle)
    }

    deinit {
        let handle = self.handle

        try? context.withThreadSafeContext { context in
            nfs_closedir(context, handle)
        }
    }

    func makeIterator() -> AnyIterator<nfsdirent> {
        let context = context.context
        let handle = handle
        nfs_rewinddir(context, handle)
        return AnyIterator {
            nfs_readdir(context, handle)?.pointee
        }
    }

    var startIndex: Int {
        0
    }

    var endIndex: Int {
        count
    }

    var count: Int {
        let context = context.context
        let handle = handle

        let currentPos = nfs_telldir(context, handle)
        defer {
            nfs_seekdir(context, handle, currentPos)
        }
        nfs_rewinddir(context, handle)
        var i = 0
        while nfs_readdir(context, handle) != nil {
            i += 1
        }
        return i
    }

    subscript(_: Int) -> nfsdirent {
        let context = context.context
        let handle = handle
        let currentPos = nfs_telldir(context, handle)
        nfs_seekdir(context, handle, 0)
        defer {
            nfs_seekdir(context, handle, currentPos)
        }
        return nfs_readdir(context, handle).move()
    }

    func index(after i: Int) -> Int {
        i + 1
    }
}
