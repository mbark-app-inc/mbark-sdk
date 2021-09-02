//
//  EffectsDrawableRendering.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Foundation/Foundation.h>
#import <Metal/Metal.h>

NS_ASSUME_NONNULL_BEGIN

@class EffectsDrawableRenderingRequest;

@protocol EffectsDrawableProvider <NSObject>

- (nullable id<MTLDrawable>)drawableForRequest:(EffectsDrawableRenderingRequest *)request;

- (nullable MTLRenderPassDescriptor *)renderPassDescriptorForRequest:(EffectsDrawableRenderingRequest *)request;

@end

typedef NS_ENUM(NSUInteger, EffectsDrawableRenderingResizingMode) {
    EffectsDrawableRenderingResizingModeScale,
    EffectsDrawableRenderingResizingModeAspect,
    EffectsDrawableRenderingResizingModeAspectFill
};

__attribute__((objc_subclassing_restricted))
@interface EffectsDrawableRenderingRequest : NSObject

@property (nonatomic, weak, readonly) id<EffectsDrawableProvider> drawableProvider;

@property (nonatomic, readonly) EffectsDrawableRenderingResizingMode resizingMode;

- (instancetype)initWithDrawableProvider:(id<EffectsDrawableProvider>)drawableProvider resizingMode:(EffectsDrawableRenderingResizingMode)resizingMode;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

#import <MetalKit/MetalKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MTKView (EffectsDrawableProvider) <EffectsDrawableProvider>

@end

NS_ASSUME_NONNULL_END
