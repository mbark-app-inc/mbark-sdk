//
//  EffectsPixelFormat.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Metal/Metal.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT MTLPixelFormat const EffectsPixelFormatUnspecified NS_REFINED_FOR_SWIFT;   //aliased to MTLPixelFormatInvalid

FOUNDATION_EXPORT MTLPixelFormat const EffectsPixelFormatYCBCR8_420_2P NS_REFINED_FOR_SWIFT;
FOUNDATION_EXPORT MTLPixelFormat const EffectsPixelFormatYCBCR8_420_2P_sRGB NS_REFINED_FOR_SWIFT;

FOUNDATION_EXPORT MTLPixelFormat const EffectsPixelFormatYCBCR10_420_2P NS_REFINED_FOR_SWIFT;
FOUNDATION_EXPORT MTLPixelFormat const EffectsPixelFormatYCBCR10_420_2P_sRGB NS_REFINED_FOR_SWIFT;

FOUNDATION_EXPORT BOOL EffectsDeviceSupportsYCBCRPixelFormat(id<MTLDevice> device);

NS_ASSUME_NONNULL_END

