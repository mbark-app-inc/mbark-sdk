//
//  EffectsImageRenderingContext.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Metal/Metal.h>

@class EffectsImage, EffectsContext;

NS_ASSUME_NONNULL_BEGIN

/*! @brief Rendering context related constant for EffectsContextImageAssociatedValueTableName. */
FOUNDATION_EXPORT NSString * const EffectsContextImagePersistentResolutionHolderTableName;

__attribute__((objc_subclassing_restricted))
@interface EffectsImageRenderingContext : NSObject

@property (nonatomic, strong, readonly) EffectsContext *context;

@property (nonatomic, strong, readonly) id<MTLCommandBuffer> commandBuffer;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

/// Use this method in -[EffectsImagePromise resolveWithContext:error:] to get the resolved dependencies of the promise. The `image` parameter must be one of the resolving promise's dependencies. An exception is thrown when calling this method outside the -[EffectsImagePromise resolveWithContext:error:] method or passing an invalid image.
- (id<MTLTexture>)resolvedTextureForImage:(EffectsImage *)image;

/// Use this method in -[EffectsImagePromise resolveWithContext:error:] to get the sampler state of an image. The `image` parameter must be one of the resolving promise's dependencies. An exception is thrown when calling this method outside the -[EffectsImagePromise resolveWithContext:error:] method or passing an invalid image.
- (id<MTLSamplerState>)resolvedSamplerStateForImage:(EffectsImage *)image;

@end

NS_ASSUME_NONNULL_END

#import <EffectsContext.h>

NS_ASSUME_NONNULL_BEGIN

@interface EffectsContext (RenderedImageBuffer)

- (nullable EffectsImage *)renderedBufferForImage:(EffectsImage *)targetImage;

@end

NS_ASSUME_NONNULL_END
