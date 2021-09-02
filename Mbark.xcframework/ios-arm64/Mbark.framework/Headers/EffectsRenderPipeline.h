//
//  EffectsRenderPipeline.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Metal/Metal.h>

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface EffectsRenderPipeline : NSObject <NSCopying>

@property (nonatomic,strong,readonly) id<MTLRenderPipelineState> state;

@property (nonatomic,strong,readonly) MTLRenderPipelineReflection *reflection;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithState:(id<MTLRenderPipelineState>)state reflection:(MTLRenderPipelineReflection *)reflection NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
