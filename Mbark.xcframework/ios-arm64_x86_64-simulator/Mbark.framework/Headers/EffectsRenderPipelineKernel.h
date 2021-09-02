//
//  EffectsRenderPipelineKernel.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Metal/Metal.h>
#import <EffectsKernel.h>
#import <EffectsTextureDimensions.h>
#import <EffectsRenderCommand.h>

NS_ASSUME_NONNULL_BEGIN

@class EffectsRenderPipeline, EffectsFunctionDescriptor, EffectsContext, EffectsImage, EffectsRenderPassOutputDescriptor, EffectsAlphaTypeHandlingRule;

FOUNDATION_EXPORT NSUInteger const EffectsRenderPipelineMaximumColorAttachmentCount;

__attribute__((objc_subclassing_restricted))
@interface EffectsRenderPipelineKernelConfiguration: NSObject <EffectsKernelConfiguration>

@property (nonatomic, readonly) const MTLPixelFormat *colorAttachmentPixelFormats;

@property (nonatomic, readonly) NSUInteger colorAttachmentCount;

@property (nonatomic, readonly) MTLPixelFormat depthAttachmentPixelFormat;

@property (nonatomic, readonly) MTLPixelFormat stencilAttachmentPixelFormat;

@property (nonatomic, readonly) NSUInteger rasterSampleCount;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithColorAttachmentPixelFormats:(MTLPixelFormat[_Nonnull])colorAttachmentPixelFormats count:(NSUInteger)count;

- (instancetype)initWithColorAttachmentPixelFormat:(MTLPixelFormat)colorAttachmentPixelFormat;

- (instancetype)initWithColorAttachmentPixelFormats:(MTLPixelFormat[_Nonnull])colorAttachmentPixelFormats count:(NSUInteger)count depthAttachmentPixelFormat:(MTLPixelFormat)depthAttachmentPixelFormat stencilAttachmentPixelFormat:(MTLPixelFormat)stencilAttachmentPixelFormat rasterSampleCount:(NSUInteger)rasterSampleCount NS_DESIGNATED_INITIALIZER;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsRenderPipelineKernel : NSObject <EffectsKernel>

@property (nonatomic,copy,readonly) EffectsFunctionDescriptor *vertexFunctionDescriptor;

@property (nonatomic,copy,readonly) EffectsFunctionDescriptor *fragmentFunctionDescriptor;

@property (nonatomic,copy,readonly,nullable) MTLVertexDescriptor *vertexDescriptor;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

@property (nonatomic,readonly) NSUInteger colorAttachmentCount;

@property (nonatomic,copy,readonly) EffectsAlphaTypeHandlingRule *alphaTypeHandlingRule;

- (instancetype)initWithVertexFunctionDescriptor:(EffectsFunctionDescriptor *)vertexFunctionDescriptor
                      fragmentFunctionDescriptor:(EffectsFunctionDescriptor *)fragmentFunctionDescriptor
                                vertexDescriptor:(nullable MTLVertexDescriptor *)vertexDescriptor
                            colorAttachmentCount:(NSUInteger)colorAttachmentCount
                           alphaTypeHandlingRule:(EffectsAlphaTypeHandlingRule *)alphaTypeHandlingRule NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithVertexFunctionDescriptor:(EffectsFunctionDescriptor *)vertexFunctionDescriptor
                      fragmentFunctionDescriptor:(EffectsFunctionDescriptor *)fragmentFunctionDescriptor;

@end

@interface EffectsRenderPipelineKernel (ImageCreation)

- (EffectsImage *)applyToInputImages:(NSArray<EffectsImage *> *)images
                      parameters:(NSDictionary<NSString *,id> *)parameters
         outputTextureDimensions:(EffectsTextureDimensions)outputTextureDimensions
               outputPixelFormat:(MTLPixelFormat)outputPixelFormat;

- (NSArray<EffectsImage *> *)applyToInputImages:(NSArray<EffectsImage *> *)images
                                 parameters:(NSDictionary<NSString *,id> *)parameters
                          outputDescriptors:(NSArray<EffectsRenderPassOutputDescriptor *> *)outputDescriptors;

@end

@interface EffectsRenderPipelineKernel (PassthroughKernel)

@property (nonatomic, class, strong, readonly) EffectsRenderPipelineKernel *passthroughRenderPipelineKernel;

@end

@interface EffectsRenderCommand (ImageCreation)

+ (NSArray<EffectsImage *> *)imagesByPerformingRenderCommands:(NSArray<EffectsRenderCommand *> *)renderCommands
                                        outputDescriptors:(NSArray<EffectsRenderPassOutputDescriptor *> *)outputDescriptors;


+ (NSArray<EffectsImage *> *)imagesByPerformingRenderCommands:(NSArray<EffectsRenderCommand *> *)renderCommands
                                        rasterSampleCount:(NSUInteger)rasterSampleCount
                                        outputDescriptors:(NSArray<EffectsRenderPassOutputDescriptor *> *)outputDescriptors;

@end

@class EffectsRenderGraphNode;

FOUNDATION_EXPORT void EffectsColorMatrixRenderGraphNodeOptimize(EffectsRenderGraphNode *node);

NS_ASSUME_NONNULL_END
