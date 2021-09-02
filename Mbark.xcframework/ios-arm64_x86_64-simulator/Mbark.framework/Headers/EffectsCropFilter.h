//
//  EffectsCropFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <CoreGraphics/CoreGraphics.h>
#import "EffectsFilter.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, EffectsCropRegionUnit) {
    EffectsCropRegionUnitPixel,
    EffectsCropRegionUnitPercentage
};

// Rounding policies:
//
// Original Value  1.2 | 1.21 | 1.25 | 1.35 | 1.27
// -----------------------------------------------
// Plain           1.2 | 1.2  | 1.3  | 1.4  | 1.3
// Floor           1.2 | 1.2  | 1.2  | 1.3  | 1.2
// Ceiling         1.2 | 1.3  | 1.3  | 1.4  | 1.3

typedef NS_ENUM(NSUInteger, EffectsCropFilterRoundingMode) {
    EffectsCropFilterRoundingModePlain,
    EffectsCropFilterRoundingModeCeiling,
    EffectsCropFilterRoundingModeFloor
};

struct EffectsCropRegion {
    CGRect bounds;
    EffectsCropRegionUnit unit;
};
typedef struct EffectsCropRegion EffectsCropRegion;

FOUNDATION_EXPORT EffectsCropRegion EffectsCropRegionMake(CGRect rect, EffectsCropRegionUnit unit) NS_SWIFT_UNAVAILABLE("Use EffectsCropRegion.init instead.");

__attribute__((objc_subclassing_restricted))
@interface EffectsCropFilter : NSObject <EffectsUnaryFilter>

@property (nonatomic) EffectsCropRegion cropRegion;

@property (nonatomic) float scale;

@property (nonatomic) EffectsCropFilterRoundingMode roundingMode;

@end

NS_ASSUME_NONNULL_END
