//
//  EffectsGeometry.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Metal/Metal.h>

NS_ASSUME_NONNULL_BEGIN

@class EffectsRenderPipeline;

@protocol EffectsGeometryRenderingContext <NSObject>

@property (nonatomic, readonly, strong) EffectsRenderPipeline *renderPipeline;

@property (nonatomic, readonly, strong) id<MTLDevice> device;

@end

@protocol EffectsGeometry <NSObject, NSCopying>

- (void)encodeDrawCallWithCommandEncoder:(id<MTLRenderCommandEncoder>)commandEncoder
                                 context:(id<EffectsGeometryRenderingContext>)context;

@end

NS_ASSUME_NONNULL_END

#import <EffectsRenderPipeline.h>

NS_ASSUME_NONNULL_BEGIN

@interface EffectsRenderPipeline (EffectsGeometryRenderingContext) <EffectsGeometryRenderingContext>

@end

NS_ASSUME_NONNULL_END
