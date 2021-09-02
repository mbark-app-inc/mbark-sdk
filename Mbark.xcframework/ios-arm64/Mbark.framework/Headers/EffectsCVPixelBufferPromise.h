//
//  EffectsCVPixelBufferPromise.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import "EffectsImagePromise.h"
#import "EffectsCVPixelBufferRendering.h"

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface EffectsCVPixelBufferPromise : NSObject <EffectsImagePromise>

@property (nonatomic, readonly) EffectsCVPixelBufferRenderingAPI renderingAPI;

@property (nonatomic, readonly) BOOL sRGB;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithCVPixelBuffer:(CVPixelBufferRef)pixelBuffer options:(EffectsCVPixelBufferRenderingOptions *)options alphaType:(EffectsAlphaType)alphaType;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsCVPixelBufferDirectBridgePromise : NSObject <EffectsImagePromise>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithCVPixelBuffer:(CVPixelBufferRef)pixelBuffer planeIndex:(NSUInteger)planeIndex textureDescriptor:(MTLTextureDescriptor *)textureDescriptor alphaType:(EffectsAlphaType)alphaType NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
