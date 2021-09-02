//
//  EffectsRenderCommand.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//
#import <EffectsGeometry.h>

@class EffectsRenderPipelineKernel, EffectsImage, EffectsRenderPassOutputDescriptor;

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface EffectsRenderCommand : NSObject <NSCopying>

@property (nonatomic, strong, readonly) EffectsRenderPipelineKernel *kernel;

@property (nonatomic, copy, readonly) id<EffectsGeometry> geometry;

@property (nonatomic, copy, readonly) NSArray<EffectsImage *> *images;

@property (nonatomic, copy, readonly) NSDictionary<NSString *, id> *parameters;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithKernel:(EffectsRenderPipelineKernel *)kernel
                      geometry:(id<EffectsGeometry>)geometry
                        images:(NSArray<EffectsImage *> *)images
                    parameters:(NSDictionary<NSString *,id> *)parameters NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
