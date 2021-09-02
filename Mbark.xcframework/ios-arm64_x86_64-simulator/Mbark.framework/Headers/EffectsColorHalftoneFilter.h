//
//  EffectsColorHalftoneFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import "EffectsUnaryImageRenderingFilter.h"
#include <simd/simd.h>

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface EffectsColorHalftoneFilter : EffectsUnaryImageRenderingFilter

/// Specifies the scale of the operation, i.e. the size for the pixels in the resulting image.
@property (nonatomic) float scale;

/// Specifies the angles of the r, g, b channel.
@property (nonatomic) simd_float4 angles;

@end

NS_ASSUME_NONNULL_END
