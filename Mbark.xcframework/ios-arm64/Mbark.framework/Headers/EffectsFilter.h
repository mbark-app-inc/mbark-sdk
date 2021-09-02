//
//  EffectsFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Foundation/Foundation.h>
#import <Metal/Metal.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString * const EffectsFilterPassthroughVertexFunctionName;
FOUNDATION_EXPORT NSString * const EffectsFilterPassthroughFragmentFunctionName;

FOUNDATION_EXPORT NSString * const EffectsFilterUnpremultiplyAlphaFragmentFunctionName;
FOUNDATION_EXPORT NSString * const EffectsFilterUnpremultiplyAlphaWithSRGBToLinearRGBFragmentFunctionName;
FOUNDATION_EXPORT NSString * const EffectsFilterPremultiplyAlphaFragmentFunctionName;

FOUNDATION_EXPORT NSString * const EffectsFilterColorMatrixFragmentFunctionName;

@class EffectsImage;

@protocol EffectsFilter

@property (nonatomic) MTLPixelFormat outputPixelFormat; //Default: EffectsPixelFormatUnspecified aka MTLPixelFormatInvalid

@property (nonatomic, readonly, nullable) EffectsImage *outputImage;

@end

@protocol EffectsUnaryFilter <EffectsFilter>

@property (nonatomic, strong, nullable) EffectsImage *inputImage;

@end

NS_ASSUME_NONNULL_END
