//
//  EffectsRGBColorSpaceConversionFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-08.
//

#import "EffectsUnaryImageRenderingFilter.h"

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface EffectsLinearToSRGBToneCurveFilter : EffectsUnaryImageRenderingFilter

+ (EffectsImage *)imageByProcessingImage:(EffectsImage *)image;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsSRGBToneCurveToLinearFilter: EffectsUnaryImageRenderingFilter

+ (EffectsImage *)imageByProcessingImage:(EffectsImage *)image;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsITUR709RGBToLinearRGBFilter: EffectsUnaryImageRenderingFilter

+ (EffectsImage *)imageByProcessingImage:(EffectsImage *)image;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsITUR709RGBToSRGBFilter: EffectsUnaryImageRenderingFilter

+ (EffectsImage *)imageByProcessingImage:(EffectsImage *)image;

@end

typedef NS_ENUM(NSInteger, EffectsRGBColorSpace) {
    EffectsRGBColorSpaceLinearSRGB = 0,
    EffectsRGBColorSpaceSRGB NS_SWIFT_NAME(sRGB) = 1,
    EffectsRGBColorSpaceITUR709 NS_SWIFT_NAME(itur709) = 2,
};

__attribute__((objc_subclassing_restricted))
@interface EffectsRGBColorSpaceConversionFilter : NSObject <EffectsUnaryFilter>

@property (nonatomic) EffectsRGBColorSpace inputColorSpace;
@property (nonatomic) EffectsRGBColorSpace outputColorSpace;

@property (nonatomic) EffectsAlphaType outputAlphaType;

+ (EffectsImage *)imageByConvertingImage:(EffectsImage *)image
                      fromColorSpace:(EffectsRGBColorSpace)inputColorSpace
                        toColorSpace:(EffectsRGBColorSpace)outputColorSpace
                     outputAlphaType:(EffectsAlphaType)outputAlphaType
                   outputPixelFormat:(MTLPixelFormat)pixelFormat NS_REFINED_FOR_SWIFT;

@end

NS_ASSUME_NONNULL_END
