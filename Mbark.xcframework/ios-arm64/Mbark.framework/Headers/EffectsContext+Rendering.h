//
//  EffectsContext+Rendering.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Foundation/Foundation.h>
#import <CoreImage/CoreImage.h>
#import <EffectsContext.h>
#import <EffectsAlphaType.h>

NS_ASSUME_NONNULL_BEGIN

@class EffectsDrawableRenderingRequest, EffectsCIImageCreationOptions, EffectsRenderTask;

@interface EffectsContext (Rendering)

- (BOOL)renderImage:(EffectsImage *)image toDrawableWithRequest:(EffectsDrawableRenderingRequest *)request error:(NSError **)error NS_SWIFT_NAME(render(_:toDrawableWithRequest:));

- (nullable CIImage *)createCIImageFromImage:(EffectsImage *)image error:(NSError **)error NS_SWIFT_NAME(makeCIImage(from:));

- (nullable CIImage *)createCIImageFromImage:(EffectsImage *)image options:(EffectsCIImageCreationOptions *)options error:(NSError **)error NS_SWIFT_NAME(makeCIImage(from:options:));

- (BOOL)renderImage:(EffectsImage *)image toCVPixelBuffer:(CVPixelBufferRef)pixelBuffer error:(NSError **)error NS_SWIFT_NAME(render(_:to:));

- (BOOL)renderImage:(EffectsImage *)image toCVPixelBuffer:(CVPixelBufferRef)pixelBuffer sRGB:(BOOL)sRGB error:(NSError **)error NS_SWIFT_NAME(render(_:to:sRGB:));

- (nullable CGImageRef)createCGImageFromImage:(EffectsImage *)image error:(NSError **)error CF_RETURNS_RETAINED NS_SWIFT_NAME(makeCGImage(from:));

- (nullable CGImageRef)createCGImageFromImage:(EffectsImage *)image colorSpace:(nullable CGColorSpaceRef)colorSpace error:(NSError **)error CF_RETURNS_RETAINED NS_SWIFT_NAME(makeCGImage(from:colorSpace:));

- (nullable EffectsRenderTask *)startTaskToRenderImage:(EffectsImage *)image toCVPixelBuffer:(CVPixelBufferRef)pixelBuffer sRGB:(BOOL)sRGB error:(NSError **)error NS_SWIFT_NAME(startTask(toRender:to:sRGB:));

- (nullable EffectsRenderTask *)startTaskToCreateCGImage:(CF_RETURNS_RETAINED __nullable CGImageRef * __nonnull)outImage fromImage:(EffectsImage *)image colorSpace:(nullable CGColorSpaceRef)colorSpace error:(NSError **)error NS_SWIFT_NAME(startTask(toCreate:from:colorSpace:));

- (nullable EffectsRenderTask *)startTaskToRenderImage:(EffectsImage *)image toDrawableWithRequest:(EffectsDrawableRenderingRequest *)request error:(NSError **)error NS_SWIFT_NAME(startTask(toRender:toDrawableWithRequest:));

- (nullable EffectsRenderTask *)startTaskToCreateCGImage:(CF_RETURNS_RETAINED __nullable CGImageRef * __nonnull)outImage fromImage:(EffectsImage *)image colorSpace:(nullable CGColorSpaceRef)colorSpace error:(NSError **)error completion:(nullable void (^)(EffectsRenderTask *task))completion NS_SWIFT_NAME(startTask(toCreate:from:colorSpace:completion:));

- (nullable EffectsRenderTask *)startTaskToRenderImage:(EffectsImage *)image toCVPixelBuffer:(CVPixelBufferRef)pixelBuffer sRGB:(BOOL)sRGB error:(NSError **)error completion:(nullable void (^)(EffectsRenderTask *task))completion NS_SWIFT_NAME(startTask(toRender:to:sRGB:completion:));

/// The default destinationAlphaType is premultiplied.
- (nullable EffectsRenderTask *)startTaskToRenderImage:(EffectsImage *)image
                                   toCVPixelBuffer:(CVPixelBufferRef)pixelBuffer
                                              sRGB:(BOOL)sRGB
                              destinationAlphaType:(EffectsAlphaType)destinationAlphaType
                                             error:(NSError **)error
                                        completion:(nullable void (^)(EffectsRenderTask *task))completion NS_SWIFT_NAME(startTask(toRender:to:sRGB:destinationAlphaType:completion:));

- (nullable EffectsRenderTask *)startTaskToRenderImage:(EffectsImage *)image toDrawableWithRequest:(EffectsDrawableRenderingRequest *)request error:(NSError **)error completion:(nullable void (^)(EffectsRenderTask *task))completion NS_SWIFT_NAME(startTask(toRender:toDrawableWithRequest:completion:));

- (nullable EffectsRenderTask *)startTaskToRenderImage:(EffectsImage *)image
                                         toTexture:(id<MTLTexture>)texture
                              destinationAlphaType:(EffectsAlphaType)destinationAlphaType
                                             error:(NSError **)error
                                        completion:(nullable void (^)(EffectsRenderTask *task))completion NS_SWIFT_NAME(startTask(toRender:to:destinationAlphaType:completion:));

/// Render the image to nowhere.
- (nullable EffectsRenderTask *)startTaskToRenderImage:(EffectsImage *)image
                                             error:(NSError **)error
                                        completion:(nullable void (^)(EffectsRenderTask *task))completion NS_SWIFT_NAME(startTask(toRender:completion:));

@end

NS_ASSUME_NONNULL_END
