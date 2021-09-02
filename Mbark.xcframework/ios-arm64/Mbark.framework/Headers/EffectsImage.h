//
//  EffectsImage.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Metal/Metal.h>
#import <MetalKit/MetalKit.h>
#import <CoreImage/CoreImage.h>
#import <EffectsCVPixelBufferRendering.h>
#import <EffectsColor.h>
#import <EffectsAlphaType.h>
#import <EffectsTextureDimensions.h>

NS_ASSUME_NONNULL_BEGIN

@class EffectsSamplerDescriptor, EffectsCIImageRenderingOptions, EffectsCVPixelBufferRenderingOptions, EffectsCGImageLoadingOptions;

typedef NS_ENUM(NSInteger, EffectsImageCachePolicy) {
    EffectsImageCachePolicyTransient,
    EffectsImageCachePolicyPersistent
} NS_SWIFT_NAME(EffectsImage.CachePolicy);

/// A representation of an image to be processed or produced.
__attribute__((objc_subclassing_restricted))
@interface EffectsImage : NSObject <NSCopying>

@property (nonatomic, readonly) EffectsImageCachePolicy cachePolicy;

@property (nonatomic, copy, readonly) EffectsSamplerDescriptor *samplerDescriptor;

@property (nonatomic, readonly) EffectsAlphaType alphaType;

@property (nonatomic, readonly) EffectsTextureDimensions dimensions;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)imageWithSamplerDescriptor:(EffectsSamplerDescriptor *)samplerDescriptor;

- (instancetype)imageWithCachePolicy:(EffectsImageCachePolicy)cachePolicy;

@end

@interface EffectsImage (Dimensions2D)

@property (nonatomic,readonly) CGRect extent;

@property (nonatomic,readonly) CGSize size;

@end

@interface EffectsImage (Creation)

- (instancetype)initWithCVPixelBuffer:(CVPixelBufferRef)pixelBuffer alphaType:(EffectsAlphaType)alphaType;

- (instancetype)initWithCVPixelBuffer:(CVPixelBufferRef)pixelBuffer renderingAPI:(EffectsCVPixelBufferRenderingAPI)renderingAPI alphaType:(EffectsAlphaType)alphaType;

- (instancetype)initWithCVPixelBuffer:(CVPixelBufferRef)pixelBuffer options:(EffectsCVPixelBufferRenderingOptions *)options alphaType:(EffectsAlphaType)alphaType;

- (instancetype)initWithCVPixelBuffer:(CVPixelBufferRef)pixelBuffer planeIndex:(NSUInteger)planeIndex textureDescriptor:(MTLTextureDescriptor *)textureDescriptor alphaType:(EffectsAlphaType)alphaType;

- (instancetype)initWithCGImage:(CGImageRef)cgImage options:(nullable NSDictionary<MTKTextureLoaderOption,id> *)options NS_REFINED_FOR_SWIFT;

- (instancetype)initWithCGImage:(CGImageRef)cgImage options:(nullable NSDictionary<MTKTextureLoaderOption,id> *)options isOpaque:(BOOL)isOpaque NS_REFINED_FOR_SWIFT;

- (instancetype)initWithCGImage:(CGImageRef)cgImage loadingOptions:(nullable EffectsCGImageLoadingOptions *)options NS_REFINED_FOR_SWIFT;

- (instancetype)initWithCGImage:(CGImageRef)cgImage loadingOptions:(nullable EffectsCGImageLoadingOptions *)options isOpaque:(BOOL)isOpaque NS_REFINED_FOR_SWIFT;

- (instancetype)initWithCGImage:(CGImageRef)cgImage orientation:(CGImagePropertyOrientation)orientation loadingOptions:(nullable EffectsCGImageLoadingOptions *)options isOpaque:(BOOL)isOpaque NS_REFINED_FOR_SWIFT;


- (instancetype)initWithTexture:(id<MTLTexture>)texture alphaType:(EffectsAlphaType)alphaType;


- (instancetype)initWithCIImage:(CIImage *)ciImage;

- (instancetype)initWithCIImage:(CIImage *)ciImage isOpaque:(BOOL)isOpaque;

- (instancetype)initWithCIImage:(CIImage *)ciImage isOpaque:(BOOL)isOpaque options:(EffectsCIImageRenderingOptions *)options;

- (instancetype)initWithCIImage:(CIImage *)ciImage bounds:(CGRect)bounds isOpaque:(BOOL)isOpaque options:(EffectsCIImageRenderingOptions *)options;


- (nullable instancetype)initWithContentsOfURL:(NSURL *)URL options:(nullable NSDictionary<MTKTextureLoaderOption,id> *)options NS_REFINED_FOR_SWIFT;

- (nullable instancetype)initWithContentsOfURL:(NSURL *)URL options:(nullable NSDictionary<MTKTextureLoaderOption,id> *)options alphaType:(EffectsAlphaType)alphaType NS_REFINED_FOR_SWIFT;

- (nullable instancetype)initWithContentsOfURL:(NSURL *)URL size:(CGSize)size options:(nullable NSDictionary<MTKTextureLoaderOption,id> *)options alphaType:(EffectsAlphaType)alphaType NS_REFINED_FOR_SWIFT;

- (nullable instancetype)initWithContentsOfURL:(NSURL *)URL loadingOptions:(nullable EffectsCGImageLoadingOptions *)options NS_REFINED_FOR_SWIFT;

- (nullable instancetype)initWithContentsOfURL:(NSURL *)URL loadingOptions:(nullable EffectsCGImageLoadingOptions *)options isOpaque:(BOOL)isOpaque NS_REFINED_FOR_SWIFT;

//EffectsAlphaTypeNonPremultiplied
- (instancetype)initWithColor:(EffectsColor)color sRGB:(BOOL)sRGB size:(CGSize)size;

- (instancetype)initWithBitmapData:(NSData *)data width:(NSUInteger)width height:(NSUInteger)height bytesPerRow:(NSUInteger)bytesPerRow pixelFormat:(MTLPixelFormat)pixelFormat alphaType:(EffectsAlphaType)alphaType;

- (instancetype)initWithName:(NSString *)name
                      bundle:(nullable NSBundle *)bundle
                        size:(CGSize)size
                 scaleFactor:(CGFloat)scaleFactor
                     options:(nullable NSDictionary<MTKTextureLoaderOption, id> *)options
                   alphaType:(EffectsAlphaType)alphaType NS_AVAILABLE(10_12, 10_0) NS_SWIFT_NAME(init(named:in:size:scaleFactor:options:alphaType:));

- (instancetype)initWithMDLTexture:(MDLTexture *)texture
                           options:(nullable NSDictionary<MTKTextureLoaderOption, id> *)options
                         alphaType:(EffectsAlphaType)alphaType NS_AVAILABLE(10_12, 10_0);

/// A 1x1 white image
@property (class, readonly) EffectsImage *whiteImage;

/// A 1x1 black image
@property (class, readonly) EffectsImage *blackImage;

/// A 1x1 transparent image
@property (class, readonly) EffectsImage *transparentImage;

@end


NS_ASSUME_NONNULL_END
