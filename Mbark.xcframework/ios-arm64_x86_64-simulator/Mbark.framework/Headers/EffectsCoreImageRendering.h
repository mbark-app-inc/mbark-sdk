//
//  EffectsCoreImageRendering.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <Metal/Metal.h>
#import <CoreImage/CoreImage.h>

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface EffectsCIImageRenderingOptions : NSObject <NSCopying>

@property (nullable, nonatomic, readonly) CGColorSpaceRef colorSpace;

@property (getter=isFlipped, readonly, nonatomic) BOOL flipped;

@property (nonatomic, readonly) MTLPixelFormat destinationPixelFormat;

@property (nonatomic, readonly) CIRenderDestinationAlphaMode alphaMode NS_AVAILABLE(10_13, 11_0);

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithDestinationPixelFormat:(MTLPixelFormat)pixelFormat colorSpace:(nullable CGColorSpaceRef)colorSpace flipped:(BOOL)flipped NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithDestinationPixelFormat:(MTLPixelFormat)pixelFormat alphaMode:(CIRenderDestinationAlphaMode)alphaMode colorSpace:(nullable CGColorSpaceRef)colorSpace flipped:(BOOL)flipped NS_DESIGNATED_INITIALIZER NS_AVAILABLE(10_13, 11_0);

@property (nonatomic, strong, class, readonly) EffectsCIImageRenderingOptions *defaultOptions;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsCIImageCreationOptions: NSObject <NSCopying>

@property (nonatomic, nullable, readonly) CGColorSpaceRef colorSpace;

@property (getter=isFlipped, readonly, nonatomic) BOOL flipped;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithColorSpace:(nullable CGColorSpaceRef)colorSpace flipped:(BOOL)flipped NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, class, readonly) EffectsCIImageCreationOptions *defaultOptions;

@end

NS_ASSUME_NONNULL_END
