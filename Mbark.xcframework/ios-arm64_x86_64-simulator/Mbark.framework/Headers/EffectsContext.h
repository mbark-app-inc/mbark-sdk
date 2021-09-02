//
//  EffectsContext.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Metal/Metal.h>
#import <MetalKit/MetalKit.h>
#import <CoreImage/CoreImage.h>
#import <CoreVideo/CoreVideo.h>
#import <EffectsMemoryWarningObserver.h>

NS_ASSUME_NONNULL_BEGIN

@class EffectsCVMetalTextureCache;
@protocol EffectsTextureLoader, EffectsTexturePool, EffectsCVMetalTextureBridging;

FOUNDATION_EXPORT NSString * const EffectsContextDefaultLabel;

/// Options for creating a EffectsContext.
__attribute__((objc_subclassing_restricted))
@interface EffectsContextOptions : NSObject

@property (nonatomic, copy, nullable) NSDictionary<CIContextOption,id> *coreImageContextOptions;

/// Default pixel format for intermediate textures.
@property (nonatomic) MTLPixelFormat workingPixelFormat;

/// Whether the render graph optimization is enabled. The default value for this property is NO.
@property (nonatomic) BOOL enablesRenderGraphOptimization;

/// Automatically reclaims resources on memory warning.
@property (nonatomic) BOOL automaticallyReclaimsResources;

/// Whether to enable native support for YCbCr textures. The default value for this property is YES. YCbCr textures can be used when this property is set to YES, and the device supports this feature.
@property (nonatomic) BOOL enablesYCbCrPixelFormatSupport;

/// A string to help identify this object.
@property (nonatomic, copy) NSString *label;

/// The built-in metal library URL.
@property (nonatomic, copy) NSURL *defaultLibraryURL;

/// The texture loader to use. When this property is nil, the context uses `EffectsDefaultTextureLoader`.
@property (nonatomic, nullable) Class<EffectsTextureLoader> textureLoaderClass;

/// The core video - metal texture bridge class to use. Possible values are EffectsCVMetalTextureCache.class (using CVMetalTextureRef), EffectsCVMetalIOSurfaceBridge.class (using IOSurface to convert CVPixelBuffer to metal texture). When this property is nil, the context uses `EffectsCVMetalIOSurfaceBridge` for iOS 11+/macOS 10.11+ and `EffectsCVMetalTextureCache` for operating systems before iOS 11/macOS 10.11.
@property (nonatomic, nullable) Class<EffectsCVMetalTextureBridging> coreVideoMetalTextureBridgeClass;

/// The texture pool class to use. When this property is nil, the context uses `EffectsHeapTexturePool` if possible, and falls back to `EffectsDeviceTexturePool`.
@property (nonatomic, nullable) Class<EffectsTexturePool> texturePoolClass;

@end

FOUNDATION_EXPORT NSURL * _Nullable EffectsDefaultLibraryURLForBundle(NSBundle *bundle);

/// An evaluation context for rendering image processing results.
__attribute__((objc_subclassing_restricted))
@interface EffectsContext : NSObject

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (nullable instancetype)initWithDevice:(id<MTLDevice>)device error:(NSError **)error;

- (nullable instancetype)initWithDevice:(id<MTLDevice>)device options:(EffectsContextOptions *)options error:(NSError **)error NS_DESIGNATED_INITIALIZER;

@property (nonatomic, readonly) MTLPixelFormat workingPixelFormat;

@property (nonatomic, readonly) BOOL isRenderGraphOptimizationEnabled;

@property (nonatomic, copy, readonly) NSString *label;

/// Whether the device supports MetalPerformanceShaders.
@property (nonatomic, readonly) BOOL isMetalPerformanceShadersSupported;

/// Whether the device supports YCbCr pixel formats.
@property (nonatomic, readonly) BOOL isYCbCrPixelFormatSupported;

/// Whether the device supports memoryless texture.
@property (nonatomic, readonly) BOOL isMemorylessTextureSupported;

/// Whether the device supports programmable blending.
@property (nonatomic, readonly) BOOL isProgrammableBlendingSupported;

/// Whether the default library is compiled with programmable blending support.
@property (nonatomic, readonly) BOOL defaultLibrarySupportsProgrammableBlending;

@property (nonatomic, strong, readonly) id<MTLDevice> device;

@property (nonatomic, strong, readonly) id<MTLLibrary> defaultLibrary;

@property (nonatomic, strong, readonly) id<MTLCommandQueue> commandQueue;

@property (nonatomic, strong, readonly) id<EffectsTextureLoader> textureLoader;

@property (nonatomic, strong, readonly) CIContext *coreImageContext;

@property (nonatomic, strong, readonly) id<EffectsCVMetalTextureBridging> coreVideoTextureBridge;

@property (nonatomic, class, readonly) BOOL defaultMetalDeviceSupportsMPS;

- (void)reclaimResources;

@property (nonatomic, readonly) NSUInteger idleResourceSize NS_AVAILABLE(10_13, 11_0);

@property (nonatomic, readonly) NSUInteger idleResourceCount;

+ (void)enumerateAllInstances:(void (^)(EffectsContext *context))enumerator;

/// Whether a device supports memoryless render targets.
+ (BOOL)deviceSupportsMemorylessTexture:(id<MTLDevice>)device;

/// Whether a device supports YCbCr pixel formats.
+ (BOOL)deviceSupportsYCbCrPixelFormat:(id<MTLDevice>)device;

/// Whether a device supports programmable blending.
/// @discussion This only indicates whether the device supports programmable blending. To use programmable blending you need to make sure the metal library is compiled with the supported metal language version. For Mac and MacCatalyst, `MTLLanguageVersion2_3` is required.
+ (BOOL)deviceSupportsProgrammableBlending:(id<MTLDevice>)device;

@end

@interface EffectsContext (MemoryWarningHandling) <EffectsMemoryWarningHandling>

@end

@interface EffectsContext (SimulatorSupport)

/// Whether to render on iOS simulators. The default value is YES. If the value of this property is NO, the `EffectsContext` initialization fails immediately with an error (EffectsErrorFeatureNotAvailableOnSimulator) on Simulators. This property is relevant only during the initialization of an `EffectsContext`.
@property (nonatomic, class) BOOL enablesSimulatorSupport;

@end

NS_ASSUME_NONNULL_END
