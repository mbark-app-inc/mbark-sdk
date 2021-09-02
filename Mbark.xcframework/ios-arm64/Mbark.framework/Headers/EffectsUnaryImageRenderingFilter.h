//
//  EffectsUnaryImageRenderingFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <QuartzCore/QuartzCore.h>
#import <EffectsFilter.h>
#import <EffectsImageOrientation.h>
#import <EffectsAlphaType.h>

NS_ASSUME_NONNULL_BEGIN

@class EffectsRenderPipelineKernel, EffectsFunctionDescriptor;

@interface EffectsUnaryImageRenderingFilter : NSObject <EffectsUnaryFilter>

+ (EffectsRenderPipelineKernel *)kernel;

@property (nonatomic) EffectsImageOrientation orientation; //Rotate the canvas to that orientation.

+ (EffectsImage *)imageByProcessingImage:(EffectsImage *)image withInputParameters:(NSDictionary<NSString *,id> *)parameters outputPixelFormat:(MTLPixelFormat)outputPixelFormat;

+ (EffectsImage *)imageByProcessingImage:(EffectsImage *)image orientation:(EffectsImageOrientation)orientation parameters:(NSDictionary<NSString *,id> *)parameters outputPixelFormat:(MTLPixelFormat)outputPixelFormat;

+ (EffectsImage *)imageByProcessingImage:(EffectsImage *)image orientation:(EffectsImageOrientation)orientation parameters:(NSDictionary<NSString *,id> *)parameters outputPixelFormat:(MTLPixelFormat)outputPixelFormat outputImageSize:(CGSize)outputImageSize;

@end

@interface EffectsUnaryImageRenderingFilter (SubclassingHooks)

@property (nonatomic,copy,readonly) NSDictionary<NSString *, id> *parameters;

- (CGSize)outputImageSizeForInputImage:(EffectsImage *)inputImage;

+ (EffectsFunctionDescriptor *)fragmentFunctionDescriptor;

+ (EffectsAlphaTypeHandlingRule *)alphaTypeHandlingRule;

@end

NS_ASSUME_NONNULL_END
