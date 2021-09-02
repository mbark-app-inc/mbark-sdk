//
//  EffectsTexturePool.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Metal/Metal.h>

NS_ASSUME_NONNULL_BEGIN

@class EffectsTextureDescriptor;

/// A reusable texture from a texture pool.
__attribute__((objc_subclassing_restricted))
@interface EffectsReusableTexture : NSObject

/// Returns the underlaying texture. When a reusable texture's texture retain count reachs zero, this method will return nil.
@property (atomic,strong,nullable,readonly) id<MTLTexture> texture;

/// Increase the texture's texture retain count. If the retain operation failed, i.e. the texture is already been reused and no longer valid, this method will return `NO`.
- (BOOL)retainTexture;

/// Decrease the texture's texture retain count. When the retain count reaches zero, returns the underlaying texture to the texture pool.
- (void)releaseTexture;

@end


/// A texture pool which allocates and reuses metal textures.
@protocol EffectsTexturePool <NSObject>

+ (instancetype)newTexturePoolWithDevice:(id <MTLDevice>)device;

- (nullable EffectsReusableTexture *)newTextureWithDescriptor:(EffectsTextureDescriptor *)textureDescriptor error:(NSError **)error NS_SWIFT_NAME(makeTexture(descriptor:));

/// Frees as many textures from the pool as possible.
- (void)flush;

/// The size in bytes occupied by idle resources.
@property (nonatomic, readonly) NSUInteger idleResourceSize NS_AVAILABLE(10_13, 11_0);

/// The count of idle resources.
@property (nonatomic, readonly) NSUInteger idleResourceCount;

@end


/// Deivce allocated texture pool.
__attribute__((objc_subclassing_restricted))
@interface EffectsDeviceTexturePool: NSObject <EffectsTexturePool>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithDevice:(id<MTLDevice>)device NS_DESIGNATED_INITIALIZER;

@property (nonatomic, readonly) NSUInteger idleResourceSize NS_AVAILABLE(10_13, 11_0);

@end


/// Heap texture pool. **May** have smaller memory footprint than `EffectsDeviceTexturePool` depending on your use case. `EffectsHeapTexturePool` uses `MTLHeap`s for texture allocations. Heaps are reused based on heap's size and resource options. For example, the heap for a 512x512 bgra8Unorm texture may then be reused to create a 256x256 rgba32Float texture.
__attribute__((objc_subclassing_restricted))
NS_AVAILABLE(10_15, 13_0)
@interface EffectsHeapTexturePool: NSObject <EffectsTexturePool>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithDevice:(id<MTLDevice>)device NS_DESIGNATED_INITIALIZER;

/// EffectsHeapTexturePool supports MTLGPUFamilyApple5 (See https://forums.developer.apple.com/thread/113223), MTLGPUFamilyMac1 and MTLGPUFamilyMacCatalyst1 devices.
+ (BOOL)isSupportedOnDevice:(id<MTLDevice>)device;

@end

NS_ASSUME_NONNULL_END
