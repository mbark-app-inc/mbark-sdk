//
//  EffectsColorLookupFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <CoreGraphics/CoreGraphics.h>
#import "EffectsFilter.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, EffectsColorLookupTableType) {
    EffectsColorLookupTableTypeUnknown,

    /// The look up table contents must a 2D image representing `n` slices of a unit color cube texture, arranged in an square of `n` images. For instance, a color cube of dimension 64x64x64 should be provided as an image of size 512x512 - sqrt(64x64x64).
    EffectsColorLookupTableType2DSquare,

    /// The look up table contents must a 2D image representing `n` slices of a unit color cube texture, arranged in an horizontal row of `n` images. For instance, a color cube of dimension 16x16x16 should be provided as an image of size 256x16.
    EffectsColorLookupTableType2DHorizontalStrip,

    EffectsColorLookupTableType2DVerticalStrip,

    EffectsColorLookupTableType3D
};

__attribute__((objc_subclassing_restricted))
@interface EffectsColorLookupTableInfo: NSObject <NSCopying>

@property (nonatomic,readonly) EffectsColorLookupTableType type;

@property (nonatomic,readonly) NSInteger dimension;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithType:(EffectsColorLookupTableType)type dimension:(NSInteger)dimension NS_DESIGNATED_INITIALIZER;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsColorLookupFilter : NSObject <EffectsFilter>

@property (nonatomic, strong, nullable) EffectsImage *inputImage;

@property (nonatomic, strong, nullable) EffectsImage *inputColorLookupTable;

@property (nonatomic, strong, nullable, readonly) EffectsColorLookupTableInfo *inputColorLookupTableInfo;

/// Specifies the intensity (in the range [0, 1]) of the operation.
@property (nonatomic) float intensity;

+ (nullable EffectsImage *)create3DColorLookupTableFrom2DColorLookupTable:(EffectsImage *)image pixelFormat:(MTLPixelFormat)pixelFormat NS_SWIFT_NAME(make3DColorLookupTable(from:pixelFormat:));

@end

NS_ASSUME_NONNULL_END
