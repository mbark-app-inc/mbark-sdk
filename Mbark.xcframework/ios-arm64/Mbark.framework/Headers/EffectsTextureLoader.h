//
//  EffectsTextureLoader.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <MetalKit/MetalKit.h>

NS_ASSUME_NONNULL_BEGIN

/// Abstract interface for texture loaders.
@protocol EffectsTextureLoader <NSObject>

+ (instancetype)newTextureLoaderWithDevice:(id <MTLDevice>)device NS_SWIFT_NAME(makeTextureLoader(device:));

- (nullable id <MTLTexture>)newTextureWithCGImage:(nonnull CGImageRef)cgImage
                                          options:(nullable NSDictionary <MTKTextureLoaderOption, id> *)options
                                            error:(NSError *__nullable *__nullable)error;

- (nullable id <MTLTexture>)newTextureWithContentsOfURL:(nonnull NSURL *)URL
                                                options:(nullable NSDictionary <MTKTextureLoaderOption, id> *)options
                                                  error:(NSError *__nullable *__nullable)error;

- (nullable id <MTLTexture>)newTextureWithName:(nonnull NSString *)name
                                   scaleFactor:(CGFloat)scaleFactor
                                        bundle:(nullable NSBundle *)bundle
                                       options:(nullable NSDictionary <MTKTextureLoaderOption, id> *)options
                                         error:(NSError *__nullable *__nullable)error;

- (nullable id <MTLTexture>)newTextureWithMDLTexture:(nonnull MDLTexture *)texture
                                             options:(nullable NSDictionary <MTKTextureLoaderOption, id> *)options
                                               error:(NSError *__nullable *__nullable)error;

@end

@interface MTKTextureLoader (EffectsTextureLoader) <EffectsTextureLoader>

@end

/// The default texture loader. A `EffectsDefaultTextureLoader` object uses a `MTKTextureLoader` internally to load textures. When an image cannot be loaded with `MTKTextureLoader`, `EffectsDefaultTextureLoader` draws the image to a 32bits/pixel BGRA `CVPixelBuffer` and creates a texture from that pixel buffer.
__attribute__((objc_subclassing_restricted))
@interface EffectsDefaultTextureLoader : NSObject <EffectsTextureLoader>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
