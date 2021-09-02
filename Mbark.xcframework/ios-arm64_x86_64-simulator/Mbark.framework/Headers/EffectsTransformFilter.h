//
//  EffectsTransformFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-08.
//

#import <QuartzCore/QuartzCore.h>
#import "EffectsFilter.h"

NS_ASSUME_NONNULL_BEGIN

/*
           ^  y+
           |
           |
     +--+--+--+--+
     |/////|/////|
 ----|-----|-----|---> x+
     |/////|/////|
     +--+--+--+--+
           |
           |
*/

typedef CGRect EffectsTransformFilterViewport NS_SWIFT_NAME(EffectsTransformFilter.Viewport);

FOUNDATION_EXPORT EffectsTransformFilterViewport EffectsTransformFilterMinimumEnclosingViewportForImageWithTransform(EffectsImage *image, CATransform3D transform, float fieldOfView) NS_SWIFT_NAME(EffectsTransformFilter.minimumEnclosingViewport(for:transform:fieldOfView:));
FOUNDATION_EXPORT EffectsTransformFilterViewport EffectsTransformFilterDefaultViewportForImage(EffectsImage *image) NS_SWIFT_NAME(EffectsTransformFilter.defaultViewport(for:));

FOUNDATION_EXPORT EffectsImage * EffectsTransformFilterApplyTransformToImage(EffectsImage *image, CATransform3D transform, float fieldOfView, NSUInteger rasterSampleCount, EffectsTransformFilterViewport viewport, MTLPixelFormat outputPixelFormat);

__attribute__((objc_subclassing_restricted))
@interface EffectsTransformFilter : NSObject <EffectsUnaryFilter>

@property (nonatomic) CATransform3D transform;

/*!
 @property fov
 @abstract Determines the receiver's field of view on the X And Y axis (in radian).
 @discussion When fov is zero the orthographic matrix will be applied . Otherwise, use the perspective matrix. Value in [0, M_PI) is valid. Defaults to 0.
 */
@property (nonatomic) float fieldOfView;

@property (nonatomic) EffectsTransformFilterViewport viewport;

@property (nonatomic, readonly) EffectsTransformFilterViewport minimumEnclosingViewport;

@property (nonatomic, readonly) EffectsTransformFilterViewport defaultViewport;

@property (nonatomic) NSUInteger rasterSampleCount;

@end

NS_ASSUME_NONNULL_END
