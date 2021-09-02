//
//  EffectsRenderTask.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Metal/Metal.h>

NS_ASSUME_NONNULL_BEGIN

@class EffectsImageRenderingContext;

/// Represents a GPU render task - i.e., commands in a command buffer.
__attribute__((objc_subclassing_restricted))
@interface EffectsRenderTask : NSObject

/// Status of the underlaying command buffer.
@property (readonly) MTLCommandBufferStatus commandBufferStatus;

- (instancetype)initWithCommandBuffer:(id<MTLCommandBuffer>)commandBuffer NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

/// Synchronously blocks execution until the task either completes or fails (with error).
- (void)waitUntilCompleted;

/// If an error occurred during execution, the NSError may contain more details about the problem.
@property (nullable, readonly) NSError *error;

@end

NS_ASSUME_NONNULL_END
