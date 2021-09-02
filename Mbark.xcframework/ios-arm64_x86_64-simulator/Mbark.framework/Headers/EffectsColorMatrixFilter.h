//
//  EffectsColorMatrixFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <EffectsUnaryImageRenderingFilter.h>
#import <EffectsColorMatrix.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString * const EffectsColorMatrixFilterColorMatrixParameterKey;

@interface EffectsColorMatrixFilter : EffectsUnaryImageRenderingFilter

@property (nonatomic) EffectsColorMatrix colorMatrix;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsExposureFilter : EffectsColorMatrixFilter

- (void)setColorMatrix:(EffectsColorMatrix)colorMatrix NS_UNAVAILABLE;

/// Specifies the exposure, with 0 being no-change.
///
/// R  [e 0 0 0 0]
/// G  [0 e 0 0 0]
/// B  [0 0 e 0 0]
/// A  [0 0 0 1 0]
/// W  [0 0 0 0 1]
/// e = pow(2, exposure)
@property (nonatomic) float exposure;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsSaturationFilter : EffectsColorMatrixFilter

- (void)setColorMatrix:(EffectsColorMatrix)colorMatrix NS_UNAVAILABLE;

@property (nonatomic) simd_float3 grayColorTransform;

/// Specifies the saturation. Saturation ranges from 0.0 (fully desaturated) to 2.0 (max saturation), with 1.0 as the normal level.
@property (nonatomic) float saturation;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsColorInvertFilter : EffectsColorMatrixFilter

- (void)setColorMatrix:(EffectsColorMatrix)colorMatrix NS_UNAVAILABLE;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsOpacityFilter: EffectsColorMatrixFilter

- (void)setColorMatrix:(EffectsColorMatrix)colorMatrix NS_UNAVAILABLE;

/// Specifies the opacity, with 0 being fully transparent, and 1 being no-change.
@property (nonatomic) float opacity;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsBrightnessFilter: EffectsColorMatrixFilter

- (void)setColorMatrix:(EffectsColorMatrix)colorMatrix NS_UNAVAILABLE;

/// Specifies the brightness in the range of 0 to 1, with 0 being no-change.
///
/// R  [1 0 0 0 0]
/// G  [0 1 0 0 0]
/// B  [0 0 1 0 0]
/// A  [0 0 0 1 0]
/// W  [b b b 0 1]
/// b = brightness
@property (nonatomic) float brightness;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsContrastFilter: EffectsColorMatrixFilter

- (void)setColorMatrix:(EffectsColorMatrix)colorMatrix NS_UNAVAILABLE;

/// Specifies the contrast, with 0 being minimal contrast and 1.0 as the normal level.
///
/// R  [c 0 0 0 0]
/// G  [0 c 0 0 0]
/// B  [0 0 c 0 0]
/// A  [0 0 0 1 0]
/// W  [t t t 0 1]
/// c = contrast
/// t = (1.0 - c) / 2.0
@property (nonatomic) float contrast;

@end

NS_ASSUME_NONNULL_END
