//
//  EffectsMPSGaussianBlurFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import "EffectsFilter.h"

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface EffectsMPSGaussianBlurFilter : NSObject <EffectsUnaryFilter>

@property (nonatomic) float radius;

@end

NS_ASSUME_NONNULL_END
