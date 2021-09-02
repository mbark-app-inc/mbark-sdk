//
//  EffectsTextureDescriptor.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Metal/Metal.h>

NS_ASSUME_NONNULL_BEGIN

/// An immutable wrapper for MTLTextureDescriptor
__attribute__((objc_subclassing_restricted))
@interface EffectsTextureDescriptor : NSObject <NSCopying>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithMTLTextureDescriptor:(MTLTextureDescriptor *)textureDescriptor NS_DESIGNATED_INITIALIZER;

/// Create a texture descriptor for a common 2D texture.
- (instancetype)initWithPixelFormat:(MTLPixelFormat)pixelFormat
                              width:(NSUInteger)width
                             height:(NSUInteger)height
                          mipmapped:(BOOL)mipmapped
                              usage:(MTLTextureUsage)usage
                    resourceOptions:(MTLResourceOptions)resourceOptions NS_DESIGNATED_INITIALIZER;

/// Create a texture descriptor for a common 2D texture.
- (instancetype)initWithPixelFormat:(MTLPixelFormat)pixelFormat
                              width:(NSUInteger)width
                             height:(NSUInteger)height
                          mipmapped:(BOOL)mipmapped
                              usage:(MTLTextureUsage)usage NS_DESIGNATED_INITIALIZER;

+ (instancetype)texture2DDescriptorWithPixelFormat:(MTLPixelFormat)pixelFormat
                                             width:(NSUInteger)width
                                            height:(NSUInteger)height
                                             usage:(MTLTextureUsage)usage;

+ (instancetype)texture2DDescriptorWithPixelFormat:(MTLPixelFormat)pixelFormat
                                             width:(NSUInteger)width
                                            height:(NSUInteger)height
                                         mipmapped:(BOOL)mipmapped
                                             usage:(MTLTextureUsage)usage
                                   resourceOptions:(MTLResourceOptions)resourceOptions;

- (MTLTextureDescriptor *)newMTLTextureDescriptor NS_SWIFT_NAME(makeMTLTextureDescriptor());

@property (readonly, nonatomic) MTLTextureType textureType;

@property (readonly, nonatomic) MTLPixelFormat pixelFormat;

@property (readonly, nonatomic) NSUInteger width;

@property (readonly, nonatomic) NSUInteger height;

@property (readonly, nonatomic) NSUInteger depth;

@property (readonly, nonatomic) MTLResourceOptions resourceOptions;

@property (readonly, nonatomic) MTLHazardTrackingMode hazardTrackingMode API_AVAILABLE(macos(10.15), ios(13.0));

- (MTLSizeAndAlign)heapTextureSizeAndAlignWithDevice:(id<MTLDevice>)device NS_AVAILABLE(10_13, 10_0);

- (nullable id<MTLTexture>)newTextureWithDevice:(id<MTLDevice>)device NS_SWIFT_NAME(makeTexture(device:));

- (nullable id<MTLTexture>)newTextureWithHeap:(id<MTLHeap>)heap NS_SWIFT_NAME(makeTexture(heap:)) NS_AVAILABLE(10_13, 10_0);

@end

@interface MTLTextureDescriptor (EffectsTextureDescriptor)

- (EffectsTextureDescriptor *)newEffectsTextureDescriptor NS_SWIFT_NAME(makeEffectsTextureDescriptor());;

@end

NS_ASSUME_NONNULL_END
