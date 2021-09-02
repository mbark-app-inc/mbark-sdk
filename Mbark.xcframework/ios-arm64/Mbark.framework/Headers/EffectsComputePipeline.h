//
//  EffectsComputePipeline.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//


#import <Metal/Metal.h>

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface EffectsComputePipeline : NSObject <NSCopying>

@property (nonatomic,strong,readonly) id<MTLComputePipelineState> state;

@property (nonatomic,strong,readonly) MTLComputePipelineReflection *reflection;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithState:(id<MTLComputePipelineState>)state reflection:(MTLComputePipelineReflection *)reflection NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
