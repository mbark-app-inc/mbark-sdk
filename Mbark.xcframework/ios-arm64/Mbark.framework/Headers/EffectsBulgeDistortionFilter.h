//
//  EffectsBulgeDistortionFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//


#import <simd/simd.h>
#import "EffectsUnaryImageRenderingFilter.h"

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface EffectsBulgeDistortionFilter : EffectsUnaryImageRenderingFilter

/// Specifies the center of the distortion in pixels.
@property (nonatomic) simd_float2 center;

/// Specifies the radius of the distortion in pixels.
@property (nonatomic) float radius;

/// Specifies the scale of the distortion, 0 being no-change.
@property (nonatomic) float scale;

@end

NS_ASSUME_NONNULL_END
