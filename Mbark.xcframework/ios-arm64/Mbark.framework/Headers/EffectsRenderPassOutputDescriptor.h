//
//  EffectsRenderPassOutputDescriptor.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Metal/Metal.h>
#import <EffectsTextureDimensions.h>

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface EffectsRenderPassOutputDescriptor: NSObject <NSCopying>

@property (nonatomic,readonly) EffectsTextureDimensions dimensions;

@property (nonatomic,readonly) MTLPixelFormat pixelFormat;

@property (nonatomic,readonly) MTLLoadAction loadAction;

@property (nonatomic,readonly) MTLStoreAction storeAction;

@property (nonatomic,readonly) MTLClearColor clearColor;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithDimensions:(EffectsTextureDimensions)dimensions pixelFormat:(MTLPixelFormat)pixelFormat;

- (instancetype)initWithDimensions:(EffectsTextureDimensions)dimensions pixelFormat:(MTLPixelFormat)pixelFormat loadAction:(MTLLoadAction)loadAction;

- (instancetype)initWithDimensions:(EffectsTextureDimensions)dimensions pixelFormat:(MTLPixelFormat)pixelFormat loadAction:(MTLLoadAction)loadAction storeAction:(MTLStoreAction)storeAction;

- (instancetype)initWithDimensions:(EffectsTextureDimensions)dimensions pixelFormat:(MTLPixelFormat)pixelFormat clearColor:(MTLClearColor)clearColor loadAction:(MTLLoadAction)loadAction storeAction:(MTLStoreAction)storeAction NS_DESIGNATED_INITIALIZER;

- (BOOL)isEqualToOutputDescriptor:(EffectsRenderPassOutputDescriptor *)object;

@end

NS_ASSUME_NONNULL_END
