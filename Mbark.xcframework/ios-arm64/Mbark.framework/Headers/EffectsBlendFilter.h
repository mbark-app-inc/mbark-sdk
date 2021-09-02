//
//  EffectsBlendFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import "EffectsFilter.h"
#import "EffectsBlendModes.h"
#import "EffectsAlphaType.h"

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface EffectsBlendFilter : NSObject <EffectsFilter>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

@property (nonatomic,copy,readonly) EffectsBlendMode blendMode;

- (instancetype)initWithBlendMode:(EffectsBlendMode)mode;

@property (nonatomic,strong,nullable) EffectsImage *inputBackgroundImage;

@property (nonatomic,strong,nullable) EffectsImage *inputImage;

/// Specifies the intensity (in the range [0, 1]) of the operation.
@property (nonatomic) float intensity;

/// Specifies the alpha type of output image. If `.alphaIsOne` is assigned, the alpha channel of the output image will be set to 1. The default value for this property is `.nonPremultiplied`.
@property (nonatomic) EffectsAlphaType outputAlphaType;

@end

NS_ASSUME_NONNULL_END
