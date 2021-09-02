//
//  EffectsError.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString * const EffectsErrorDomain;

typedef NS_ERROR_ENUM(EffectsErrorDomain, EffectsError) {
    //Core errors
    EffectsErrorDeviceNotFound = 1001,
    EffectsErrorFunctionNotFound = 1002,
    EffectsErrorFailedToCreateSamplerState = 1003,
    EffectsErrorFailedToCreateTexture = 1004,
    EffectsErrorFailedToCreateCommandEncoder = 1005,
    EffectsErrorFailedToCreateHeap = 1006,
    EffectsErrorDefaultLibraryNotFound = 1007,
    EffectsErrorBlendFunctionNotFound = 1008,

    //Texture loading errors
    EffectsErrorUnsupportedCVPixelBufferFormat = 2001,
    EffectsErrorTextureDimensionsMismatch = 2002,
    EffectsErrorTextureLoaderFailedToCreateCGContext = 2004,
    EffectsErrorTextureLoaderFailedToCreateCGImage = 2005,

    //Image errors
    EffectsErrorUnsupportedImageCachePolicy = 3001,

    //Kernel errors
    EffectsErrorParameterDataSizeMismatch = 4001,
    EffectsErrorUnsupportedParameterType = 4002,
    EffectsErrorMPSKernelInputCountMismatch = 4003,
    EffectsErrorMPSKernelNotSupported = 4004,
    EffectsErrorTextureBindingFailed = 4005,
    EffectsErrorParameterDataTypeMismatch = 4006,

    //Render errors
    EffectsErrorEmptyDrawable = 5001,
    EffectsErrorEmptyDrawableTexture = 5101,
    EffectsErrorFailedToCreateCGImageFromCVPixelBuffer = 5002,
    EffectsErrorFailedToCreateCVPixelBuffer = 5003,
    EffectsErrorInvalidCVPixelBufferRenderingAPI = 5004,
    EffectsErrorFailedToGetRenderedBuffer = 5005,

    //For operations do not support cross device or cross context rendering, we report these errors.
    EffectsErrorCrossDeviceRendering = 5006,
    EffectsErrorCrossContextRendering = 5007,

    //For features not available on iOS simulator.
    EffectsErrorFeatureNotAvailableOnSimulator = 6001
};

/// Create a NSError with EffectsErrorDomain and the specified error code and user info. Creating a symbolic breakpoint for `_EffectsErrorCreate` can help you locate the source of the error.
FOUNDATION_EXPORT NSError * _EffectsErrorCreate(EffectsError code, NSString *defaultDescription, NSDictionary * _Nullable userInfo);

#define EffectsErrorCreate(code, userInfo) _EffectsErrorCreate(code, @#code, userInfo)

NS_ASSUME_NONNULL_END
