//
//  EffectsMultilayerCompositeKernel.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Metal/Metal.h>
#import <EffectsKernel.h>
#import <EffectsTextureDimensions.h>
#import <EffectsAlphaType.h>

NS_ASSUME_NONNULL_BEGIN

@class EffectsRenderPipeline, EffectsFunctionDescriptor, EffectsContext, EffectsImage, EffectsLayer;

__attribute__((objc_subclassing_restricted))
@interface EffectsMultilayerCompositeKernel : NSObject <EffectsKernel>

- (EffectsImage *)applyToBackgroundImage:(EffectsImage *)image
                              layers:(NSArray<EffectsLayer *> *)layers
                   rasterSampleCount:(NSUInteger)rasterSampleCount
                     outputAlphaType:(EffectsAlphaType)outputAlphaType
             outputTextureDimensions:(EffectsTextureDimensions)outputTextureDimensions
                   outputPixelFormat:(MTLPixelFormat)outputPixelFormat;

@end

@class EffectsRenderGraphNode;

FOUNDATION_EXPORT void EffectsMultilayerCompositingRenderGraphNodeOptimize(EffectsRenderGraphNode *node);

NS_ASSUME_NONNULL_END
