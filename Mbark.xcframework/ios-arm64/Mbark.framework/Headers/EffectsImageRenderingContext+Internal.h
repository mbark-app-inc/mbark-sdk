//
//  EffectsImageRenderingContext+Internal.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import "EffectsImageRenderingContext.h"

NS_ASSUME_NONNULL_BEGIN

@protocol EffectsImagePromiseResolution <NSObject>

@property (nonatomic,readonly) id<MTLTexture> texture;

- (void)markAsConsumedBy:(id)consumer;

@end

@interface EffectsImageRenderingContext (Internal)

- (instancetype)initWithContext:(EffectsContext *)context;

- (nullable id<EffectsImagePromiseResolution>)resolutionForImage:(EffectsImage *)image error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
