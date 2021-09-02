//
//  EffectsDotScreenFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <simd/simd.h>
#import "EffectsUnaryImageRenderingFilter.h"

__attribute__((objc_subclassing_restricted))
@interface EffectsDotScreenFilter : EffectsUnaryImageRenderingFilter

/// Specifies the angle of the effect.
@property (nonatomic) float angle;

/// Specifies the scale of the operation, i.e. the size for the pixels in the resulting image.
@property (nonatomic) float scale;

@property (nonatomic) simd_float3 grayColorTransform;

@end
