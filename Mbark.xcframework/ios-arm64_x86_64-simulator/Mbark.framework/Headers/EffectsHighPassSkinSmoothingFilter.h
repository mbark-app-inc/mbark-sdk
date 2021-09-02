//
//  EffectsHighPassSkinSmoothingFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import "EffectsFilter.h"

@class EffectsVector;

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface EffectsHighPassSkinSmoothingFilter : NSObject <EffectsFilter>

@property (nonatomic, strong, nullable) EffectsImage *inputImage;

@property (nonatomic) float amount;

@property (nonatomic) float radius;

@property (nonatomic, copy, null_resettable) NSArray<EffectsVector *> *toneCurveControlPoints;

+ (BOOL)isSupportedOnDevice:(id<MTLDevice>)device;

@end

NS_ASSUME_NONNULL_END
