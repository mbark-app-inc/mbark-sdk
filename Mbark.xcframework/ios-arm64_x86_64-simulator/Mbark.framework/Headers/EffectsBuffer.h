//
//  Effectsbuffer.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Metal/Metal.h>

NS_ASSUME_NONNULL_BEGIN

/// A GPU mutable data buffer. You can pass a `EffectsDataBuffer` instance to multiple processing units, they can all read and write the buffer's content. However, accessing a `EffectsDataBuffer`'s contents using CPU is not safe. You must ensure all the GPU reads/writes to this buffer are completed. e.g. call a render task's waitUntilCompleted. For one `EffectsDataBuffer` instance, one and only one underlaying `MTLBuffer` will be created for one GPU device.
__attribute__((objc_subclassing_restricted))
@interface EffectsDataBuffer : NSObject

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)init NS_UNAVAILABLE;

- (nullable instancetype)initWithBytes:(const void *)bytes
                                length:(NSUInteger)length
                               options:(MTLResourceOptions)options;

- (nullable instancetype)initWithData:(NSData *)data options:(MTLResourceOptions)options;

- (nullable instancetype)initWithLength:(NSUInteger)length options:(MTLResourceOptions)options NS_DESIGNATED_INITIALIZER;

@property (nonatomic, readonly) NSUInteger length;

@property (nonatomic, readonly) MTLResourceOptions options;

- (nullable id<MTLBuffer>)bufferForDevice:(id<MTLDevice>)device NS_SWIFT_NAME(buffer(for:));

/// Accessing contents from CPU is unsafe.
- (void)unsafeAccess:(void (NS_NOESCAPE ^)(void *contents, NSUInteger length))block;

@end

NS_ASSUME_NONNULL_END
