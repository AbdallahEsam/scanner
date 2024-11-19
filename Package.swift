// swift-tools-version: 6.0
// The swift-tools-version declares the minimum version of Swift required to build this package.
// swift-tools-version:5.6
import PackageDescription

let package = Package(
    name: "aaPrintScannerFw",
    platforms: [
        .iOS(.v13),  // Specify the minimum platform version
    ],
    products: [
        .library(
            name: "aaPrintScannerFw",
            targets: ["aaPrintScannerFw"]
        ),
    ],
    targets: [
        .binaryTarget(
            name: "aaPrintScannerFw",
            path: "aaPrintScannerFw/aaPrintScannerFw.xcframework"
        )
    ]
)
