//
//  EffectsVibranceFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-08.
//

#import <simd/simd.h>
#import "EffectsUnaryImageRenderingFilter.h"

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface EffectsVibranceFilter : EffectsUnaryImageRenderingFilter

/// Specifies the scale of the operation in the range of -1 to 1, with 0 being no-change.
@property (nonatomic) float amount;

@property (nonatomic) BOOL avoidsSaturatingSkinTones;

@property (nonatomic) simd_float3 grayColorTransform;

@end

NS_ASSUME_NONNULL_END
