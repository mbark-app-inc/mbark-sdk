//
//  EffectsMPSUnsharpMaskFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import "EffectsFilter.h"

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface EffectsMPSUnsharpMaskFilter : NSObject  <EffectsUnaryFilter>

@property (nonatomic) float scale; //(0, 1]. Default is 0.5.
@property (nonatomic) float radius;
@property (nonatomic) float threshold; //[0, 1). Default is 0.

@end

NS_ASSUME_NONNULL_END
