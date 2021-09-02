//
//  EffectsGeometryUtilities.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT CGRect EffectsMakeRectWithAspectRatioFillRect(CGSize aspectRatio, CGRect boundingRect) NS_SWIFT_NAME(EffectsMakeRect(aspectRatio:fillRect:));

FOUNDATION_EXPORT CGRect EffectsMakeRectWithAspectRatioInsideRect(CGSize aspectRatio, CGRect boundingRect) NS_SWIFT_NAME(EffectsMakeRect(aspectRatio:insideRect:));

NS_ASSUME_NONNULL_END
