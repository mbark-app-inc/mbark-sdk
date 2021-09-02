//
//  EffectsTextureDimensions.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

struct EffectsTextureDimensions {
    NSUInteger width;
    NSUInteger height;
    NSUInteger depth;
};
typedef struct EffectsTextureDimensions EffectsTextureDimensions;

NS_INLINE NS_SWIFT_NAME(EffectsTextureDimensions.init(cgSize:)) EffectsTextureDimensions EffectsTextureDimensionsMake2DFromCGSize(CGSize size) {
    return (EffectsTextureDimensions){.width = (NSUInteger)size.width, .height = (NSUInteger)size.height, .depth = 1};
}

NS_INLINE NS_SWIFT_NAME(EffectsTextureDimensions.isEqual(self:to:)) BOOL EffectsTextureDimensionsEqualToTextureDimensions(EffectsTextureDimensions a, EffectsTextureDimensions b) {
    return a.width == b.width && a.height == b.height && a.depth == b.depth;
}

NS_ASSUME_NONNULL_END
