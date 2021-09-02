//
//  EffectsChromaKeyBlendFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import "EffectsFilter.h"
#import "EffectsColor.h"

__attribute__((objc_subclassing_restricted))
@interface EffectsChromaKeyBlendFilter : NSObject <EffectsFilter>

@property (nonatomic, strong, nullable) EffectsImage *inputImage;

@property (nonatomic, strong, nullable) EffectsImage *inputBackgroundImage;

@property (nonatomic) float thresholdSensitivity;

@property (nonatomic) float smoothing;

@property (nonatomic) EffectsColor color;

@end
