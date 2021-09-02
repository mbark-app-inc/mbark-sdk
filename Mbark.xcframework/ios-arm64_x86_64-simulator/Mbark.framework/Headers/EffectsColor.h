//
//  EffectsColor.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Foundation/Foundation.h>
#import <simd/simd.h>

typedef NS_ENUM(NSInteger, EffectsColorComponent) {
    EffectsColorComponentRed,
    EffectsColorComponentGreen,
    EffectsColorComponentBlue,
    EffectsColorComponentAlpha
};

struct EffectsColor {
    float red;
    float green;
    float blue;
    float alpha;
};
typedef struct EffectsColor EffectsColor;

NS_INLINE NS_SWIFT_UNAVAILABLE("Use EffectsColor.init instead.") EffectsColor EffectsColorMake(float red, float green, float blue, float alpha) {
    return (EffectsColor){ red, green, blue, alpha };
}

NS_INLINE NS_SWIFT_NAME(EffectsColor.toFloat4(self:)) simd_float4 EffectsColorToFloat4(EffectsColor color) {
    return simd_make_float4(color.red, color.green, color.blue, color.alpha);
}

FOUNDATION_EXPORT EffectsColor const EffectsColorWhite NS_SWIFT_NAME(EffectsColor.white);
FOUNDATION_EXPORT EffectsColor const EffectsColorBlack NS_SWIFT_NAME(EffectsColor.black);
FOUNDATION_EXPORT EffectsColor const EffectsColorClear NS_SWIFT_NAME(EffectsColor.clear);

FOUNDATION_EXPORT simd_float3 const EffectsGrayColorTransformDefault; //EffectsGrayColorTransform_ITU_R_601
FOUNDATION_EXPORT simd_float3 const EffectsGrayColorTransform_ITU_R_601; //0.299, 0.587, 0.114
FOUNDATION_EXPORT simd_float3 const EffectsGrayColorTransform_ITU_R_709; //0.2126, 0.7152, 0.0722
