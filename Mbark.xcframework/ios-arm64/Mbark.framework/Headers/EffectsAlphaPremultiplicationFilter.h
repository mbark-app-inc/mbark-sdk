//
//  EffectsAlphaPremultiplicationFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <EffectsFilter.h>

NS_ASSUME_NONNULL_BEGIN

@class EffectsRenderPipelineKernel;

__attribute__((objc_subclassing_restricted))
@interface EffectsUnpremultiplyAlphaFilter : NSObject <EffectsUnaryFilter>

@property (nonatomic, class, strong, readonly) EffectsRenderPipelineKernel *kernel;

+ (EffectsImage *)imageByProcessingImage:(EffectsImage *)image;

+ (EffectsImage *)imageByProcessingImage:(EffectsImage *)image outputPixelFormat:(MTLPixelFormat)pixelFormat;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsPremultiplyAlphaFilter : NSObject <EffectsUnaryFilter>

@property (nonatomic, class, strong, readonly) EffectsRenderPipelineKernel *kernel;

+ (EffectsImage *)imageByProcessingImage:(EffectsImage *)image;

+ (EffectsImage *)imageByProcessingImage:(EffectsImage *)image outputPixelFormat:(MTLPixelFormat)pixelFormat;

@end

NS_ASSUME_NONNULL_END
