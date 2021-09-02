//
//  EffectsImage+Filters.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import "EffectsFilter.h"
#import "EffectsImage.h"

NS_ASSUME_NONNULL_BEGIN

@interface EffectsImage (Filters)

- (EffectsImage *)imageByUnpremultiplyingAlpha;

- (EffectsImage *)imageByPremultiplyingAlpha;

- (EffectsImage *)imageByUnpremultiplyingAlphaWithPixelFormat:(MTLPixelFormat)pixelFormat NS_SWIFT_NAME(unpremultiplyingAlpha(outputPixelFormat:));

- (EffectsImage *)imageByPremultiplyingAlphaWithPixelFormat:(MTLPixelFormat)pixelFormat NS_SWIFT_NAME(premultiplyingAlpha(outputPixelFormat:));

- (EffectsImage *)imageByApplyingCGOrientation:(CGImagePropertyOrientation)orientation NS_SWIFT_NAME(oriented(_:));

- (EffectsImage *)imageByApplyingCGOrientation:(CGImagePropertyOrientation)orientation outputPixelFormat:(MTLPixelFormat)pixelFormat NS_SWIFT_NAME(oriented(_:outputPixelFormat:));

@end

NS_ASSUME_NONNULL_END
