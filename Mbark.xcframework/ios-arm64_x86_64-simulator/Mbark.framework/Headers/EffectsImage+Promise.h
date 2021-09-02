//
//  EffectsImage+Promise.h"
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <EffectsImage.h>

@protocol EffectsImagePromise;

NS_ASSUME_NONNULL_BEGIN

@interface EffectsImage (Promise)

@property (nonatomic,copy,readonly) id<EffectsImagePromise> promise;

- (instancetype)initWithPromise:(id<EffectsImagePromise>)promise;

- (instancetype)initWithPromise:(id<EffectsImagePromise>)promise samplerDescriptor:(EffectsSamplerDescriptor *)samplerDescriptor;

- (instancetype)initWithPromise:(id<EffectsImagePromise>)promise samplerDescriptor:(EffectsSamplerDescriptor *)samplerDescriptor cachePolicy:(EffectsImageCachePolicy)cachePolicy;

- (instancetype)initWithPromise:(id<EffectsImagePromise>)promise cachePolicy:(EffectsImageCachePolicy)cachePolicy;

@end

NS_ASSUME_NONNULL_END
