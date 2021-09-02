//
//  EffectsColorMatrix.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//
#import <Foundation/Foundation.h>
#import <EffectsShaderLib.h>

FOUNDATION_EXPORT const EffectsColorMatrix EffectsColorMatrixIdentity NS_SWIFT_NAME(EffectsColorMatrix.identity);
FOUNDATION_EXPORT const EffectsColorMatrix EffectsColorMatrixRGBColorInvert NS_SWIFT_NAME(EffectsColorMatrix.rgbColorInvert);

FOUNDATION_EXPORT BOOL EffectsColorMatrixEqualToColorMatrix(EffectsColorMatrix a, EffectsColorMatrix b) NS_SWIFT_NAME(EffectsColorMatrix.isEqual(self:to:));
FOUNDATION_EXPORT BOOL EffectsColorMatrixIsIdentity(EffectsColorMatrix matrix) NS_SWIFT_NAME(getter:EffectsColorMatrix.isIdentity(self:));

FOUNDATION_EXPORT EffectsColorMatrix EffectsColorMatrixConcat(EffectsColorMatrix a, EffectsColorMatrix b) NS_SWIFT_NAME(EffectsColorMatrix.concat(self:with:));

FOUNDATION_EXPORT EffectsColorMatrix EffectsColorMatrixMakeWithExposure(float exposure) NS_SWIFT_NAME(EffectsColorMatrix.init(exposure:));
FOUNDATION_EXPORT EffectsColorMatrix EffectsColorMatrixMakeWithSaturation(float saturation, simd_float3 grayColorTransform) NS_SWIFT_NAME(EffectsColorMatrix.init(saturation:grayColorTransform:));
FOUNDATION_EXPORT EffectsColorMatrix EffectsColorMatrixMakeWithBrightness(float brightness) NS_SWIFT_NAME(EffectsColorMatrix.init(brightness:));
FOUNDATION_EXPORT EffectsColorMatrix EffectsColorMatrixMakeWithContrast(float contrast) NS_SWIFT_NAME(EffectsColorMatrix.init(contrast:));
FOUNDATION_EXPORT EffectsColorMatrix EffectsColorMatrixMakeWithOpacity(float opacity) NS_SWIFT_NAME(EffectsColorMatrix.init(opacity:));
