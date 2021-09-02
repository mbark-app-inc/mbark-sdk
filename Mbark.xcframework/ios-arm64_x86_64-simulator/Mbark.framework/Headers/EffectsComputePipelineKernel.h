//
//  EffectsComputePipelineKernel.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-08.
//

#import <Metal/Metal.h>
#import <EffectsKernel.h>
#import <EffectsTextureDimensions.h>

@class EffectsAlphaTypeHandlingRule;

NS_ASSUME_NONNULL_BEGIN

@class EffectsComputePipeline, EffectsFunctionDescriptor, EffectsImage;

__attribute__((objc_subclassing_restricted))
@interface EffectsComputeFunctionDispatchOptions : NSObject <NSCopying>

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithThreads:(MTLSize)threads threadgroups:(MTLSize)threadgroups threadsPerThreadgroup:(MTLSize)threadsPerThreadgroup;

- (instancetype)initWithGenerator:(void (^)(id<MTLComputePipelineState> pipelineState, MTLSize *threads, MTLSize *threadgroups, MTLSize *threadsPerThreadgroup))block NS_REFINED_FOR_SWIFT;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsComputePipelineKernel : NSObject <EffectsKernel>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

@property (nonatomic,copy,readonly) EffectsAlphaTypeHandlingRule *alphaTypeHandlingRule;

@property (nonatomic, copy, readonly) EffectsFunctionDescriptor *computeFunctionDescriptor;

- (instancetype)initWithComputeFunctionDescriptor:(EffectsFunctionDescriptor *)computeFunctionDescriptor;

- (instancetype)initWithComputeFunctionDescriptor:(EffectsFunctionDescriptor *)computeFunctionDescriptor alphaTypeHandlingRule:(EffectsAlphaTypeHandlingRule *)alphaTypeHandlingRule NS_DESIGNATED_INITIALIZER;

- (EffectsImage *)applyToInputImages:(NSArray<EffectsImage *> *)images
                      parameters:(NSDictionary<NSString *,id> *)parameters
         outputTextureDimensions:(EffectsTextureDimensions)outputTextureDimensions
               outputPixelFormat:(MTLPixelFormat)outputPixelFormat;

- (EffectsImage *)applyToInputImages:(NSArray<EffectsImage *> *)images
                      parameters:(NSDictionary<NSString *,id> *)parameters
                 dispatchOptions:(nullable EffectsComputeFunctionDispatchOptions *)dispatchOptions
         outputTextureDimensions:(EffectsTextureDimensions)outputTextureDimensions
               outputPixelFormat:(MTLPixelFormat)outputPixelFormat;

@end

NS_ASSUME_NONNULL_END
