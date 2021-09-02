//
//  EffectsMultilayerCompositingFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import "EffectsFilter.h"
#import "EffectsAlphaType.h"

@class EffectsLayer;

NS_ASSUME_NONNULL_BEGIN

/// A filter that allows you to compose multiple `EffectsLayer` objects onto a background image. A `EffectsMultilayerCompositingFilter` object skips the actual rendering when its `layers.count` is zero.
__attribute__((objc_subclassing_restricted))
@interface EffectsMultilayerCompositingFilter : NSObject <EffectsFilter>

@property (nonatomic, strong, nullable) EffectsImage *inputBackgroundImage;

@property (nonatomic, copy) NSArray<EffectsLayer *> *layers;

@property (nonatomic) NSUInteger rasterSampleCount;

/// Specifies the alpha type of output image. If `.alphaIsOne` is assigned, the alpha channel of the output image will be set to 1. The default value for this property is `.nonPremultiplied`.
@property (nonatomic) EffectsAlphaType outputAlphaType;

@end

NS_ASSUME_NONNULL_END
