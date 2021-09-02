//
//  EffectsCVMetalIOSurfaceBridge.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//
#import <Foundation/Foundation.h>
#import "EffectsCVMetalTextureBridging.h"

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString * const EffectsCVMetalIOSurfaceBridgeErrorDomain;

typedef NS_ERROR_ENUM(EffectsCVMetalIOSurfaceBridgeErrorDomain, EffectsCVMetalIOSurfaceBridgeError) {
    EffectsCVMetalIOSurfaceBridgeErrorImageBufferIsNotBackedByIOSurface = 10001,
    EffectsCVMetalIOSurfaceBridgeErrorFailedToCreateTexture = 10002,
    EffectsCVMetalIOSurfaceBridgeErrorCoreVideoDoesNotSupportIOSurface = 10003
};

__attribute__((objc_subclassing_restricted))
NS_CLASS_AVAILABLE(10_11, 11_0)
@interface EffectsCVMetalIOSurfaceBridge : NSObject <EffectsCVMetalTextureBridging>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithDevice:(id<MTLDevice>)device;

@end

NS_ASSUME_NONNULL_END
