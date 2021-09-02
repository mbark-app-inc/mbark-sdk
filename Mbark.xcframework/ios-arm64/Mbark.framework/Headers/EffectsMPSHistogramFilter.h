//
//  EffectsMPSHistogramFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <MetalPerformanceShaders/MetalPerformanceShaders.h>
#import <CoreGraphics/CoreGraphics.h>
#import "EffectsFilter.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, EffectsHistogramType) {
    EffectsHistogramTypeLuminance = 1 << 0,
    EffectsHistogramTypeRGB = 1 << 1
};

__attribute__((objc_subclassing_restricted))
@interface EffectsMPSHistogramFilter : NSObject <EffectsFilter>

- (void)setOutputPixelFormat:(MTLPixelFormat)outputPixelFormat NS_UNAVAILABLE;

@property (nonatomic, strong, nullable) EffectsImage *inputImage;

@property (nonatomic) float scaleFactor; //Unimplemented

@property (nonatomic) EffectsHistogramType type; //Unimplemented

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsHistogramDisplayFilter: NSObject <EffectsUnaryFilter>

@property (nonatomic) CGSize outputSize;

@end

NS_ASSUME_NONNULL_END
