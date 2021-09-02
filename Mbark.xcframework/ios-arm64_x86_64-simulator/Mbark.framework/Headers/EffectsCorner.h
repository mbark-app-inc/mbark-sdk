//
//  EffectsCorner.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

struct EffectsCornerRadius {
    float topLeft;
    float topRight;
    float bottomRight;
    float bottomLeft;
};
typedef struct EffectsCornerRadius EffectsCornerRadius;

typedef NS_ENUM(NSInteger, EffectsCornerCurve) {
    /// A circular corner curve.
    EffectsCornerCurveCircular = 0,

    /// A continuous corner curve. This option mimics the behavior of `kCACornerCurveContinuous`.
    EffectsCornerCurveContinuous = 1
};

NS_INLINE __attribute__((__overloadable__)) NS_SWIFT_UNAVAILABLE("Use EffectsCornerRadius.init(topLeft:topRight:bottomRight:bottomLeft:)") EffectsCornerRadius EffectsCornerRadiusMake(float topLeft, float topRight, float bottomRight, float bottomLeft){
    return (EffectsCornerRadius){.topLeft = topLeft, .topRight = topRight, .bottomRight = bottomRight, .bottomLeft = bottomLeft};
}

NS_INLINE __attribute__((__overloadable__)) NS_SWIFT_NAME(EffectsCornerRadius.init(_:)) EffectsCornerRadius EffectsCornerRadiusMake(float r) {
    return (EffectsCornerRadius){.topLeft = r, .topRight = r, .bottomRight = r, .bottomLeft = r};
}

NS_INLINE NS_SWIFT_NAME(getter:EffectsCornerRadius.isZero(self:)) BOOL EffectsCornerRadiusIsZero(EffectsCornerRadius r) {
    return r.topLeft == 0 && r.topRight == 0 && r.bottomLeft == 0 && r.bottomRight == 0;
}

/// Expansion scale factor applied to the rounded corner bounding box size when specific corner curve is used.
NS_INLINE NS_SWIFT_NAME(getter:EffectsCornerCurve.expansionFactor(self:)) float EffectsCornerCurveExpansionFactor(EffectsCornerCurve curve) {
    switch (curve) {
        case EffectsCornerCurveCircular:
            return 1.0;
        case EffectsCornerCurveContinuous:
            return 1.528665;
        default:
            return 1;
    }
}

NS_INLINE simd_float4 _EffectsCornerRadiusGetShadingParameterValue(EffectsCornerRadius r, EffectsCornerCurve curve) {
    return simd_make_float4(r.topLeft, r.topRight, r.bottomRight, r.bottomLeft) * EffectsCornerCurveExpansionFactor(curve);
}

NS_ASSUME_NONNULL_END
