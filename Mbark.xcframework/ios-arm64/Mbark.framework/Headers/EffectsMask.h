//
//  EffectsMask.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <EffectsColor.h>

NS_ASSUME_NONNULL_BEGIN

@class EffectsImage;

typedef NS_ENUM(NSInteger, EffectsMaskMode) {
    EffectsMaskModeNormal = 0,
    EffectsMaskModeOneMinusMaskValue
};

__attribute__((objc_subclassing_restricted))
@interface EffectsMask : NSObject <NSCopying>

@property (nonatomic, strong, readonly) EffectsImage *content;

@property (nonatomic, readonly) EffectsColorComponent component;

@property (nonatomic, readonly) EffectsMaskMode mode;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithContent:(EffectsImage *)content component:(EffectsColorComponent)component mode:(EffectsMaskMode)mode NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithContent:(EffectsImage *)content;

@end

NS_ASSUME_NONNULL_END
