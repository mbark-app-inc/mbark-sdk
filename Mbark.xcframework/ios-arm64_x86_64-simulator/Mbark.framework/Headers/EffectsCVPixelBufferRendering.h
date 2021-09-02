//
//  EffectsCVPixelBufferRendering.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, EffectsCVPixelBufferRenderingAPI) {
    EffectsCVPixelBufferRenderingAPIDefault = 1,
    EffectsCVPixelBufferRenderingAPIMbark = 1,
    EffectsCVPixelBufferRenderingAPICoreImage = 2
};

__attribute__((objc_subclassing_restricted))
@interface EffectsCVPixelBufferRenderingOptions: NSObject <NSCopying>

@property (nonatomic, readonly) EffectsCVPixelBufferRenderingAPI renderingAPI;

@property (nonatomic, readonly) BOOL sRGB; //An option for treating the pixel buffer data as sRGB image data. Specifying whether to create the texture with an sRGB (gamma corrected) pixel format.

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithRenderingAPI:(EffectsCVPixelBufferRenderingAPI)renderingAPI sRGB:(BOOL)sRGB NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, class, readonly) EffectsCVPixelBufferRenderingOptions *defaultOptions;

@end

NS_ASSUME_NONNULL_END
