//
//  EffectsCVMetalTextureCache.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import "EffectsCVMetalTextureBridging.h"

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString * const EffectsCVMetalTextureCacheErrorDomain;

typedef NS_ERROR_ENUM(EffectsCVMetalTextureCacheErrorDomain, EffectsCVMetalTextureCacheError) {
    EffectsCVMetalTextureCacheErrorMetalIsNotSupported = 10001,
    EffectsCVMetalTextureCacheErrorFailedToInitialize = 10002,
    EffectsCVMetalTextureCacheErrorFailedToCreateTexture = 10003
};

/// Thread-safe object-orientated CVMetalTextureCache.
__attribute__((objc_subclassing_restricted))
@interface EffectsCVMetalTextureCache : NSObject <EffectsCVMetalTextureBridging>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (nullable instancetype)initWithDevice:(id<MTLDevice>)device
                        cacheAttributes:(nullable NSDictionary *)cacheAttributes
                      textureAttributes:(nullable NSDictionary *)textureAttributes
                                  error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
