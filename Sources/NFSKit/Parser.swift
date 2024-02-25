//
//  Parser.swift
//  NFSKit
//
//  Created by alexiscn on 2021/7/18.
//

import Foundation
import nfs

enum Parser {
    static func toVoid(_: UnsafeMutablePointer<nfs_context>, _: UnsafeMutableRawPointer?) throws {}

    static func toString(_: UnsafeMutablePointer<nfs_context>, _ dataPtr: UnsafeMutableRawPointer?) throws -> String {
        try String(cString: dataPtr.unwrap().assumingMemoryBound(to: Int8.self))
    }

    static func toOpaquePointer(_: UnsafeMutablePointer<nfs_context>, _ dataPtr: UnsafeMutableRawPointer?) throws -> OpaquePointer {
        try OpaquePointer(dataPtr.unwrap())
    }

    static func tostatvfs(_: UnsafeMutablePointer<nfs_context>, _ dataPtr: UnsafeMutableRawPointer?) throws -> statvfs {
        try dataPtr.unwrap().assumingMemoryBound(to: statvfs.self).pointee
    }

    static func tostat64(_: UnsafeMutablePointer<nfs_context>, _ dataPtr: UnsafeMutableRawPointer?) throws -> nfs_stat_64 {
        try dataPtr.unwrap().assumingMemoryBound(to: nfs_stat_64.self).pointee
    }
}
