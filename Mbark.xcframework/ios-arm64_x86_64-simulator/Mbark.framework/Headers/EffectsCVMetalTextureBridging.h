//
//  EffectsCVMetalTextureBridging.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Metal/Metal.h>
#import <CoreVideo/CoreVideo.h>

NS_ASSUME_NONNULL_BEGIN

@protocol EffectsCVMetalTexture <NSObject>

@property (nonatomic, readonly) id<MTLTexture> texture;

@end

@protocol EffectsCVMetalTextureBridging <NSObject>

+ (nullable instancetype)newCoreVideoMetalTextureBridgeWithDevice:(id<MTLDevice>)device error:(NSError **)error NS_SWIFT_NAME(makeCoreVideoMetalTextureBridge(device:));

- (nullable id<EffectsCVMetalTexture>)newTextureWithCVImageBuffer:(CVImageBufferRef)imageBuffer
                                            textureDescriptor:(MTLTextureDescriptor *)textureDescriptor
                                                   planeIndex:(size_t)planeIndex
                                                        error:(NSError **)error NS_SWIFT_NAME(makeTexture(with:textureDescriptor:planeIndex:));

- (void)flushCache;

@end

NS_ASSUME_NONNULL_END
