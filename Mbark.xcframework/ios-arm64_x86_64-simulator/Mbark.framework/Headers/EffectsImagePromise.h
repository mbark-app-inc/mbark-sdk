//
//  EffectsImagePromise.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Metal/Metal.h>
#import <MetalKit/MetalKit.h>
#import <simd/simd.h>
#import <CoreImage/CoreImage.h>
#import <ModelIO/ModelIO.h>
#import <EffectsColor.h>
#import <EffectsTextureDimensions.h>
#import <EffectsAlphaType.h>

NS_ASSUME_NONNULL_BEGIN

@class EffectsImage, EffectsImageRenderingContext, EffectsFunctionDescriptor, EffectsTextureDescriptor, EffectsImagePromiseRenderTarget, EffectsImagePromiseDebugInfo, EffectsCIImageRenderingOptions, EffectsImageProperties;

@protocol EffectsImagePromise <NSObject, NSCopying>

@property (nonatomic, readonly) EffectsTextureDimensions dimensions;

@property (nonatomic, readonly, copy) NSArray<EffectsImage *> *dependencies;

@property (nonatomic, readonly) EffectsAlphaType alphaType;

- (nullable EffectsImagePromiseRenderTarget *)resolveWithContext:(EffectsImageRenderingContext *)renderingContext error:(NSError **)error;

- (instancetype)promiseByUpdatingDependencies:(NSArray<EffectsImage *> *)dependencies;

@property (nonatomic, strong, readonly) EffectsImagePromiseDebugInfo *debugInfo;

@end

#pragma mark - Promises

__attribute__((objc_subclassing_restricted))
@interface EffectsImageURLPromise : NSObject <EffectsImagePromise>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (nullable instancetype)initWithContentsOfURL:(NSURL *)URL
                                    dimensions:(EffectsTextureDimensions)dimensions
                                       options:(nullable NSDictionary<MTKTextureLoaderOption, id> *)options
                                     alphaType:(EffectsAlphaType)alphaType;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsLegacyCGImagePromise : NSObject <EffectsImagePromise>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithCGImage:(CGImageRef)cgImage options:(nullable NSDictionary<MTKTextureLoaderOption, id> *)options alphaType:(EffectsAlphaType)alphaType;

@end


__attribute__((objc_subclassing_restricted))
@interface EffectsCGImageLoadingOptions : NSObject <NSCopying>

@property (nonatomic, readonly, nullable) CGColorSpaceRef colorSpace;

@property (nonatomic, readonly) BOOL flipsVertically;

@property (nonatomic, readonly) MTLStorageMode storageMode;
@property (nonatomic, readonly) MTLCPUCacheMode cpuCacheMode;

@property (nonatomic, class, readonly) EffectsCGImageLoadingOptions *defaultOptions;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithColorSpace:(nullable CGColorSpaceRef)colorSpace;

- (instancetype)initWithColorSpace:(nullable CGColorSpaceRef)colorSpace
                   flipsVertically:(BOOL)flipsVertically;

/// Create a `EffectsCGImageLoadingOptions` object. If `colorSpace` is nil, the "Device RGB" color space will be used. The image's color values will be transfered to `colorSpace` when the image is loaded.
- (instancetype)initWithColorSpace:(nullable CGColorSpaceRef)colorSpace
                   flipsVertically:(BOOL)flipsVertically
                       storageMode:(MTLStorageMode)storageMode
                      cpuCacheMode:(MTLCPUCacheMode)cpuCacheMode NS_DESIGNATED_INITIALIZER;

@end


__attribute__((objc_subclassing_restricted))
@interface EffectsCGImagePromise : NSObject <EffectsImagePromise>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithCGImage:(CGImageRef)cgImage orientation:(CGImagePropertyOrientation)orientation options:(nullable EffectsCGImageLoadingOptions *)options isOpaque:(BOOL)isOpaque;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsTexturePromise : NSObject <EffectsImagePromise>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithTexture:(id<MTLTexture>)texture alphaType:(EffectsAlphaType)alphaType;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsCIImagePromise : NSObject <EffectsImagePromise>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithCIImage:(CIImage *)ciImage bounds:(CGRect)bounds isOpaque:(BOOL)isOpaque options:(EffectsCIImageRenderingOptions *)options;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsColorImagePromise: NSObject <EffectsImagePromise>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

@property (nonatomic, readonly) EffectsColor color;

- (instancetype)initWithColor:(EffectsColor)color sRGB:(BOOL)sRGB size:(CGSize)size;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsBitmapDataImagePromise: NSObject <EffectsImagePromise>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithBitmapData:(NSData *)data width:(NSUInteger)width height:(NSUInteger)height bytesPerRow:(NSUInteger)bytesPerRow pixelFormat:(MTLPixelFormat)pixelFormat alphaType:(EffectsAlphaType)alphaType;

@end

__attribute__((objc_subclassing_restricted))
NS_AVAILABLE(10_12, 10_0)
@interface EffectsNamedImagePromise: NSObject <EffectsImagePromise>

@property (nonatomic, copy, readonly) NSString *name;
@property (nonatomic, strong, readonly, nullable) NSBundle *bundle;
@property (nonatomic, readonly) CGFloat scaleFactor;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithName:(NSString *)name
                      bundle:(nullable NSBundle *)bundle
                        size:(CGSize)size
                 scaleFactor:(CGFloat)scaleFactor
                     options:(nullable NSDictionary<MTKTextureLoaderOption, id> *)options
                   alphaType:(EffectsAlphaType)alphaType;

@end

__attribute__((objc_subclassing_restricted))
NS_AVAILABLE(10_12, 10_0)
@interface EffectsMDLTexturePromise: NSObject <EffectsImagePromise>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithMDLTexture:(MDLTexture *)texture
                           options:(nullable NSDictionary<MTKTextureLoaderOption, id> *)options
                         alphaType:(EffectsAlphaType)alphaType;

@end

NS_ASSUME_NONNULL_END
