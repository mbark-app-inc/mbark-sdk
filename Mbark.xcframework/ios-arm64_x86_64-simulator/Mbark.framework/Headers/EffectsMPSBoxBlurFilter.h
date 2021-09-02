//
//  EffectsMPSBoxBlurFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <simd/simd.h>
#import "EffectsFilter.h"

__attribute__((objc_subclassing_restricted))
@interface EffectsMPSBoxBlurFilter : NSObject <EffectsUnaryFilter>

@property (nonatomic) simd_int2 size;

@end
