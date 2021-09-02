//
//  EffectsBlendWithMaskFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import "EffectsFilter.h"

@class EffectsMask;

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface EffectsBlendWithMaskFilter: NSObject <EffectsFilter>

@property (nonatomic, strong, nullable) EffectsImage *inputImage;

@property (nonatomic, strong, nullable) EffectsImage *inputBackgroundImage;

@property (nonatomic, strong, nullable) EffectsMask *inputMask;

@end

NS_ASSUME_NONNULL_END
