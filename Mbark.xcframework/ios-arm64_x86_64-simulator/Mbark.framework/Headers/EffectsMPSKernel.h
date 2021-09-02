//
//  EffectsMPSKernel.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-08.
//

#import <MetalPerformanceShaders/MetalPerformanceShaders.h>
#import <EffectsKernel.h>
#import <EffectsTextureDimensions.h>

@class EffectsAlphaTypeHandlingRule;

NS_ASSUME_NONNULL_BEGIN

@class EffectsContext, EffectsImage;

typedef MPSKernel * _Nonnull (^EffectsMPSKernelBuilder)(id<MTLDevice> device);

__attribute__((objc_subclassing_restricted))
@interface EffectsMPSKernel : NSObject <EffectsKernel>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

@property (nonatomic,copy,readonly) EffectsAlphaTypeHandlingRule *alphaTypeHandlingRule;

- (instancetype)initWithMPSKernelBuilder:(EffectsMPSKernelBuilder)builder NS_SWIFT_NAME(init(builder:));

- (instancetype)initWithMPSKernelBuilder:(EffectsMPSKernelBuilder)builder alphaTypeHandlingRule:(EffectsAlphaTypeHandlingRule *)alphaTypeHandlingRule NS_DESIGNATED_INITIALIZER NS_SWIFT_NAME(init(builder:alphaTypeHandlingRule:));

- (EffectsImage *)applyToInputImages:(NSArray<EffectsImage *> *)images
                      parameters:(NSDictionary<NSString *,id> *)parameters
         outputTextureDimensions:(EffectsTextureDimensions)outputTextureDimensions
               outputPixelFormat:(MTLPixelFormat)outputPixelFormat;

@end

NS_ASSUME_NONNULL_END
