//
//  EffectsCLAHEFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import "EffectsFilter.h"

NS_ASSUME_NONNULL_BEGIN

struct EffectsCLAHESize {
    NSUInteger width, height;
};
typedef struct EffectsCLAHESize EffectsCLAHESize;

FOUNDATION_EXPORT EffectsCLAHESize EffectsCLAHESizeMake(NSUInteger width, NSUInteger height) NS_SWIFT_UNAVAILABLE("Use EffectsCLAHESize.init instead.");

/// Performs Contrast Limited Adaptive Histogram Equalization. https://github.com/YuAo/Accelerated-CLAHE
__attribute__((objc_subclassing_restricted))
@interface EffectsCLAHEFilter : NSObject <EffectsUnaryFilter>

@property (nonatomic) float clipLimit;

@property (nonatomic) EffectsCLAHESize tileGridSize;

@end

NS_ASSUME_NONNULL_END
