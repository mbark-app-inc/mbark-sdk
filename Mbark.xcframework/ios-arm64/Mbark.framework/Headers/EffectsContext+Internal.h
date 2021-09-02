//
//  EffectsContext+Internal.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Metal/Metal.h>
#import <MetalKit/MetalKit.h>
#import <CoreImage/CoreImage.h>
#import <CoreVideo/CoreVideo.h>
#import <EffectsContext.h>

@class EffectsImage;
@protocol EffectsKernelConfiguration, EffectsKernel, EffectsImagePromise;

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface EffectsImagePromiseRenderTarget : NSObject

@property (nonatomic,strong,readonly,nullable) id<MTLTexture> texture;

- (BOOL)retainTexture;

- (void)releaseTexture;

@end

typedef NSString * EffectsContextPromiseAssociatedValueTableName NS_EXTENSIBLE_STRING_ENUM;
typedef NSString * EffectsContextImageAssociatedValueTableName NS_EXTENSIBLE_STRING_ENUM;

@class EffectsFunctionDescriptor, EffectsSamplerDescriptor, EffectsRenderPipeline, EffectsComputePipeline, EffectsTextureDescriptor;

@interface EffectsContext (Internal)

#pragma mark - Render Target

- (nullable EffectsImagePromiseRenderTarget *)newRenderTargetWithReusableTextureDescriptor:(EffectsTextureDescriptor *)textureDescriptor error:(NSError **)error NS_SWIFT_NAME(makeRenderTarget(reusableTextureDescriptor:));

- (EffectsImagePromiseRenderTarget *)newRenderTargetWithTexture:(id<MTLTexture>)texture NS_SWIFT_NAME(makeRenderTarget(texture:));

#pragma mark - Lock

- (void)lockForRendering;

- (void)unlockForRendering;

#pragma mark - Cache

- (nullable id<MTLFunction>)functionWithDescriptor:(EffectsFunctionDescriptor *)descriptor error:(NSError **)error;

- (nullable id<MTLSamplerState>)samplerStateWithDescriptor:(EffectsSamplerDescriptor *)descriptor error:(NSError **)error;

- (nullable EffectsRenderPipeline *)renderPipelineWithDescriptor:(MTLRenderPipelineDescriptor *)descriptor error:(NSError **)error;

- (nullable EffectsComputePipeline *)computePipelineWithDescriptor:(MTLComputePipelineDescriptor *)descriptor error:(NSError **)error;

- (nullable id)kernelStateForKernel:(id<EffectsKernel>)kernel configuration:(nullable id<EffectsKernelConfiguration>)configuration error:(NSError **)error;

#pragma mark - Privately Used Caches

/* Weak to strong tables */

- (nullable id)valueForPromise:(id<EffectsImagePromise>)promise inTable:(EffectsContextPromiseAssociatedValueTableName)tableName;

- (void)setValue:(nullable id)value forPromise:(id<EffectsImagePromise>)promise inTable:(EffectsContextPromiseAssociatedValueTableName)tableName;

- (nullable id)valueForImage:(EffectsImage *)image inTable:(EffectsContextImageAssociatedValueTableName)tableName;

- (void)setValue:(nullable id)value forImage:(EffectsImage *)image inTable:(EffectsContextImageAssociatedValueTableName)tableName;

/* EffectsImagePromise (weak) to EffectsImagePromiseRenderTarget (weak) table. */

- (void)setRenderTarget:(EffectsImagePromiseRenderTarget *)renderTarget forPromise:(id<EffectsImagePromise>)promise;

- (nullable EffectsImagePromiseRenderTarget *)renderTargetForPromise:(id<EffectsImagePromise>)promise;

@end

NS_ASSUME_NONNULL_END
