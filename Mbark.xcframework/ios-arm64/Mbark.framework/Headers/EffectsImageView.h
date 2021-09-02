//
//  EffectsImageView.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#if __has_include(<UIKit/UIKit.h>)

#import <UIKit/UIKit.h>
#import <MetalKit/MetalKit.h>
#import "EffectsDrawableRendering.h"

@class EffectsImage,EffectsContext;

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface EffectsImageView : UIView <MTKViewDelegate>

@property (nonatomic) BOOL automaticallyCreatesContext;

@property (nonatomic) MTLPixelFormat colorPixelFormat;

@property (nonatomic) MTLClearColor clearColor;

@property (nonatomic) EffectsDrawableRenderingResizingMode resizingMode;

/// The `EffectsContext` used to render the image. If no context is assigned and `automaticallyCreatesContext` is set to `true` (the default value), a `EffectsContext` is created automatically when the image view renders its content.
@property (nonatomic, strong, nullable) EffectsContext *context;

@property (nonatomic, strong, nullable) EffectsImage *image;

@property (nonatomic) BOOL drawsImmediately __attribute__((deprecated("Set `drawsImmediately` to `YES` is not recommended."))); //Default `NO`.

@end

NS_ASSUME_NONNULL_END

#endif
