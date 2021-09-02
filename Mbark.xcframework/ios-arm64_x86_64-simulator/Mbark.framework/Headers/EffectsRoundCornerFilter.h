//
//  EffectsRoundCornerFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-08.
//

#import <simd/simd.h>
#import "EffectsFilter.h"
#import "EffectsCorner.h"

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface EffectsRoundCornerFilter : NSObject <EffectsUnaryFilter>

@property (nonatomic) EffectsCornerRadius cornerRadius;
@property (nonatomic) EffectsCornerCurve cornerCurve;

@property (nonatomic) simd_float4 radius __attribute__((deprecated("Use `cornerRadius` and `cornerCurve` instead.")));

@end

NS_ASSUME_NONNULL_END
