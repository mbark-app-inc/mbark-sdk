//
//  EffectsMPSSobelFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <simd/simd.h>
#import "EffectsFilter.h"

typedef NS_ENUM(NSUInteger, EffectsMPSSobelColorMode) {
    EffectsMPSSobelColorModeAuto,
    EffectsMPSSobelColorModeGrayscale,
    EffectsMPSSobelColorModeGrayscaleInverted
};

__attribute__((objc_subclassing_restricted))
@interface EffectsMPSSobelFilter : NSObject <EffectsUnaryFilter>

@property (nonatomic, readonly) simd_float3 grayColorTransform;

- (instancetype)initWithGrayColorTransform:(simd_float3)grayColorTransform NS_DESIGNATED_INITIALIZER;

@property (nonatomic) EffectsMPSSobelColorMode colorMode;

@end

