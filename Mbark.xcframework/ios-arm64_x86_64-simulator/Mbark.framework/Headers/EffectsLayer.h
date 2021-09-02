//
//  EffectsLayer.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <CoreGraphics/CoreGraphics.h>
#import <EffectsBlendModes.h>
#import <EffectsColor.h>
#import <EffectsCorner.h>

NS_ASSUME_NONNULL_BEGIN

@class EffectsImage, EffectsMask;

typedef NS_CLOSED_ENUM(NSInteger, EffectsLayerLayoutUnit) {
    EffectsLayerLayoutUnitPixel,
    EffectsLayerLayoutUnitFractionOfBackgroundSize
} NS_SWIFT_NAME(EffectsLayer.LayoutUnit);

typedef NS_OPTIONS(NSUInteger, EffectsLayerFlipOptions) {
    EffectsLayerFlipOptionsDonotFlip = 0,
    EffectsLayerFlipOptionsFlipVertically = 1 << 0,
    EffectsLayerFlipOptionsFlipHorizontally = 1 << 1,
} NS_SWIFT_NAME(EffectsLayer.FlipOptions);

/// A EffectsLayer represents a compositing layer for EffectsMultilayerCompositingFilter. EffectsLayers use a UIKit like coordinate system.
__attribute__((objc_subclassing_restricted))
@interface EffectsLayer: NSObject <NSCopying>

@property (nonatomic, strong, readonly) EffectsImage *content;

@property (nonatomic, readonly) CGRect contentRegion; //pixel

@property (nonatomic, readonly) EffectsLayerFlipOptions contentFlipOptions;

/// A mask that applies to the `content` of the layer. This mask is resized and aligned with the layer.
@property (nonatomic, strong, readonly, nullable) EffectsMask *mask;

/// A mask that applies to the `content` of the layer. This mask is resized and aligned with the background.
@property (nonatomic, strong, readonly, nullable) EffectsMask *compositingMask;

@property (nonatomic, readonly) EffectsLayerLayoutUnit layoutUnit;

@property (nonatomic, readonly) CGPoint position;

@property (nonatomic, readonly) CGSize size;

@property (nonatomic, readonly) float rotation; //rad

@property (nonatomic, readonly) float opacity;

@property (nonatomic, readonly) EffectsCornerRadius cornerRadius;

@property (nonatomic, readonly) EffectsCornerCurve cornerCurve;

/// Tint the content to with the color. If the tintColor's alpha is zero original content is rendered.
@property (nonatomic, readonly) EffectsColor tintColor;

@property (nonatomic, copy, readonly) EffectsBlendMode blendMode;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithContent:(EffectsImage *)content layoutUnit:(EffectsLayerLayoutUnit)layoutUnit position:(CGPoint)position size:(CGSize)size rotation:(float)rotation opacity:(float)opacity blendMode:(EffectsBlendMode)blendMode;

- (instancetype)initWithContent:(EffectsImage *)content contentRegion:(CGRect)contentRegion compositingMask:(nullable EffectsMask *)compositingMask layoutUnit:(EffectsLayerLayoutUnit)layoutUnit position:(CGPoint)position size:(CGSize)size rotation:(float)rotation opacity:(float)opacity blendMode:(EffectsBlendMode)blendMode;

- (instancetype)initWithContent:(EffectsImage *)content contentRegion:(CGRect)contentRegion contentFlipOptions:(EffectsLayerFlipOptions)contentFlipOptions compositingMask:(nullable EffectsMask *)compositingMask layoutUnit:(EffectsLayerLayoutUnit)layoutUnit position:(CGPoint)position size:(CGSize)size rotation:(float)rotation opacity:(float)opacity blendMode:(EffectsBlendMode)blendMode;

- (instancetype)initWithContent:(EffectsImage *)content contentRegion:(CGRect)contentRegion contentFlipOptions:(EffectsLayerFlipOptions)contentFlipOptions compositingMask:(nullable EffectsMask *)compositingMask layoutUnit:(EffectsLayerLayoutUnit)layoutUnit position:(CGPoint)position size:(CGSize)size rotation:(float)rotation opacity:(float)opacity tintColor:(EffectsColor)tintColor blendMode:(EffectsBlendMode)blendMode;

- (instancetype)initWithContent:(EffectsImage *)content contentRegion:(CGRect)contentRegion contentFlipOptions:(EffectsLayerFlipOptions)contentFlipOptions mask:(nullable EffectsMask *)mask compositingMask:(nullable EffectsMask *)compositingMask layoutUnit:(EffectsLayerLayoutUnit)layoutUnit position:(CGPoint)position size:(CGSize)size rotation:(float)rotation opacity:(float)opacity tintColor:(EffectsColor)tintColor blendMode:(EffectsBlendMode)blendMode;

- (instancetype)initWithContent:(EffectsImage *)content contentRegion:(CGRect)contentRegion contentFlipOptions:(EffectsLayerFlipOptions)contentFlipOptions mask:(nullable EffectsMask *)mask compositingMask:(nullable EffectsMask *)compositingMask layoutUnit:(EffectsLayerLayoutUnit)layoutUnit position:(CGPoint)position size:(CGSize)size rotation:(float)rotation opacity:(float)opacity cornerRadius:(EffectsCornerRadius)cornerRadius cornerCurve:(EffectsCornerCurve)cornerCurve tintColor:(EffectsColor)tintColor blendMode:(EffectsBlendMode)blendMode NS_DESIGNATED_INITIALIZER;

- (CGSize)sizeInPixelForBackgroundSize:(CGSize)backgroundSize;

- (CGPoint)positionInPixelForBackgroundSize:(CGSize)backgroundSize;

@end

NS_ASSUME_NONNULL_END

