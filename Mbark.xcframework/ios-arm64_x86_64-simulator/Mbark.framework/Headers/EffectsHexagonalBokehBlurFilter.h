//
//  EffectsHexagonalBokehBlurFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import "EffectsFilter.h"

@class EffectsMask;

NS_ASSUME_NONNULL_BEGIN

/// An implementation of lens blur (bokeh) based on `Siggraph 2011 - Advances in Real-Time Rendering`
/// https://colinbarrebrisebois.com/2017/04/18/hexagonal-bokeh-blur-revisited/

__attribute__((objc_subclassing_restricted))
@interface EffectsHexagonalBokehBlurFilter : NSObject <EffectsFilter>

@property (nonatomic, strong, nullable) EffectsImage *inputImage;
@property (nonatomic, strong, nullable) EffectsMask *inputMask;

@property (nonatomic) float radius;
@property (nonatomic) float brightness;
@property (nonatomic) float angle;

@end

NS_ASSUME_NONNULL_END
