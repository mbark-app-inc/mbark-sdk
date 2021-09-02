//
//  EffectsRenderGraphOptimization.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <EffectsImagePromise.h>

NS_ASSUME_NONNULL_BEGIN

@class EffectsImage;

__attribute__((objc_subclassing_restricted))
@interface EffectsRenderGraphNode: NSObject

@property (nonatomic, strong, nullable) NSMutableArray<EffectsRenderGraphNode *> *inputs;

@property (nonatomic, strong, nullable) EffectsImage *image;

@property (nonatomic, readonly) NSInteger uniqueDependentCount;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsRenderGraphOptimizer : NSObject

+ (id<EffectsImagePromise>)promiseByOptimizingRenderGraphOfPromise:(id<EffectsImagePromise>)promise;

@end

NS_ASSUME_NONNULL_END
