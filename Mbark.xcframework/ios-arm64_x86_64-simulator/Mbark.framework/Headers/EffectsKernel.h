//
//  EffectsKernel.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Metal/Metal.h>

NS_ASSUME_NONNULL_BEGIN

@class EffectsContext;

@protocol EffectsKernelConfiguration <NSObject, NSCopying>

@property (nonatomic, copy, readonly) id<NSCopying> identifier;

@end

/// A kernel must be stateless.

@protocol EffectsKernel <NSObject>

- (nullable id)newKernelStateWithContext:(EffectsContext *)context configuration:(nullable id<EffectsKernelConfiguration>)configuration error:(NSError **)error NS_SWIFT_NAME(makeKernelState(context:configuration:));

@end

NS_ASSUME_NONNULL_END
