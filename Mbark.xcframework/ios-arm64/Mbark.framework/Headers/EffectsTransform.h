//
//  EffectsTransform.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Foundation/Foundation.h>
#import <simd/simd.h>
#import <QuartzCore/QuartzCore.h>

FOUNDATION_EXPORT simd_float4x4 EffectsMakeOrthographicMatrix(float left, float right, float top, float bottom, float near, float far);

FOUNDATION_EXPORT simd_float4x4 EffectsMakePerspectiveMatrix(float left, float right, float top, float bottom, float near, float far);

FOUNDATION_EXPORT simd_float4x4 EffectsMakeTransformMatrixFromCATransform3D(CATransform3D transform);
