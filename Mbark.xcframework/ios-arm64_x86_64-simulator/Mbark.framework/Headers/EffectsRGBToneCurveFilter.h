//
//  EffectsRGBToneCurveFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-08.
//

#import "EffectsFilter.h"

@class EffectsVector;

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface EffectsRGBToneCurveFilter : NSObject <EffectsFilter>

@property (nonatomic, strong, nullable) EffectsImage *inputImage;

@property (nonatomic, copy) NSArray<EffectsVector *> *redControlPoints;
@property (nonatomic, copy) NSArray<EffectsVector *> *greenControlPoints;
@property (nonatomic, copy) NSArray<EffectsVector *> *blueControlPoints;
@property (nonatomic, copy) NSArray<EffectsVector *> *RGBCompositeControlPoints;

@property (nonatomic) float intensity; //default 1.0

@property (nonatomic, strong, readonly) EffectsImage *toneCurveColorLookupImage;

@end

NS_ASSUME_NONNULL_END
