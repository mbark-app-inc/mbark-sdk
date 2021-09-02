//
//  EffectsImageOrientation.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//
#import <Foundation/Foundation.h>
#import <ImageIO/ImageIO.h>

// https://developer.apple.com/documentation/uikit/uiimageorientation?language=objc

typedef NS_ENUM(NSInteger, EffectsImageOrientation) {
    EffectsImageOrientationUnknown = 0,
    EffectsImageOrientationUp = 1,
    EffectsImageOrientationUpMirrored = 2,
    EffectsImageOrientationDown = 3,
    EffectsImageOrientationDownMirrored = 4,
    EffectsImageOrientationLeftMirrored = 5,
    EffectsImageOrientationRight = 6,
    EffectsImageOrientationRightMirrored = 7,
    EffectsImageOrientationLeft = 8
};

FOUNDATION_EXPORT EffectsImageOrientation EffectsImageOrientationFromCGImagePropertyOrientation(CGImagePropertyOrientation orientation) NS_SWIFT_NAME(EffectsImageOrientation.init(cgImagePropertyOrientation:));
