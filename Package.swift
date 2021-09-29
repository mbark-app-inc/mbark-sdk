//
//  Package.swift
//  
//
//  Created by Nate de Jager on 2021-09-29.
//

// swift-tools-version:5.3
import PackageDescription
let package = Package(name: "Mbark",
                      platforms: [
                        .iOS(.v12)
                      ],
                      products: [
                        .library(name: "Mbark",
                                 targets: ["Mbark"])
                      ],
                      targets: [
                        .binaryTarget(name: "Mbark",
                                      path: "Mbark.xcframework")
                      ])
