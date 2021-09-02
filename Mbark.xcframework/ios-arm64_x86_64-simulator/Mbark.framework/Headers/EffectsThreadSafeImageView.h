//
//  EffectsThreadSafeImageView.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#if __has_include(<UIKit/UIKit.h>)

#import <UIKit/UIKit.h>
#import "EffectsDrawableRendering.h"

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString * const EffectsImageViewErrorDomain;

typedef NS_ERROR_ENUM(EffectsImageViewErrorDomain, EffectsImageViewError) {
    EffectsImageViewErrorContextNotFound = 1001,
    EffectsImageViewErrorSameImage = 1002
};

@class EffectsImage,EffectsContext;

/// An image view that immediately draws its `image` on the calling thread. Most of the custom properties can be accessed from any thread safely. It's recommanded to use the `EffectsImageView` which draws it's content on the main thread instead of this view.

__attribute__((objc_subclassing_restricted))
@interface EffectsThreadSafeImageView : UIView <EffectsDrawableProvider>

@property (nonatomic) BOOL automaticallyCreatesContext;

@property (atomic) MTLPixelFormat colorPixelFormat;

@property (atomic) MTLClearColor clearColor;

/// This property aliases the colorspace property of the view's CAMetalLayer
@property (atomic, nullable) CGColorSpaceRef colorSpace;

@property (atomic) EffectsDrawableRenderingResizingMode resizingMode;

@property (atomic, strong, nullable) EffectsContext *context;

@property (atomic, nullable, strong) EffectsImage *image;

/// Update the image. `renderCompletion` will be called when the rendering is finished or failed. The callback will be called on current thread or a metal internal thread.
- (void)setImage:(EffectsImage * __nullable)image renderCompletion:(void (^ __nullable)(NSError * __nullable error))renderCompletion;

@end

NS_ASSUME_NONNULL_END

#endif
