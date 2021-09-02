//
//  EffectsAlphaType.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Describe different ways to represent the opacity of a color value. See also: https://microsoft.github.io/Win2D/html/PremultipliedAlpha.htm
typedef NS_CLOSED_ENUM(NSInteger, EffectsAlphaType) {
    /// The alpha type is unknown.
    EffectsAlphaTypeUnknown = 0,

    /// RGB values specify the color of the thing being drawn. The alpha value specifies how solid it is.
    EffectsAlphaTypeNonPremultiplied = 1,

    /// RGB specifies how much color the thing being drawn contributes to the output. The alpha value specifies how much it obscures whatever is behind it.
    EffectsAlphaTypePremultiplied = 2,

    /// There is no alpha channel or the alpha value is one.
    EffectsAlphaTypeAlphaIsOne = 3
};

FOUNDATION_EXPORT NSString * EffectsAlphaTypeGetDescription(EffectsAlphaType alphaType);

@class EffectsImage;

typedef EffectsAlphaType (^EffectsAlphaTypeHandlingOutputAlphaTypeRule)(NSArray<NSNumber *> *inputAlphaTypes);

/// Describes how a image processing unit handles alpha types.
__attribute__((objc_subclassing_restricted))
@interface EffectsAlphaTypeHandlingRule: NSObject <NSCopying>

/// Acceptable alpha types.
@property (nonatomic, copy, readonly) NSArray<NSNumber *> *acceptableAlphaTypes NS_REFINED_FOR_SWIFT;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (BOOL)canAcceptAlphaType:(EffectsAlphaType)alphaType;

- (EffectsAlphaType)outputAlphaTypeForInputAlphaTypes:(NSArray<NSNumber *> *)inputAlphaTypes NS_REFINED_FOR_SWIFT;

- (EffectsAlphaType)outputAlphaTypeForInputImages:(NSArray<EffectsImage *> *)inputImages;

- (instancetype)initWithAcceptableAlphaTypes:(NSArray<NSNumber *> *)acceptableAlphaTypes outputAlphaTypeHandler:(EffectsAlphaTypeHandlingOutputAlphaTypeRule)outputAlphaTypeHandler NS_DESIGNATED_INITIALIZER NS_REFINED_FOR_SWIFT;

- (instancetype)initWithAcceptableAlphaTypes:(NSArray<NSNumber *> *)acceptableAlphaTypes outputAlphaType:(EffectsAlphaType)outputAlphaType NS_DESIGNATED_INITIALIZER NS_REFINED_FOR_SWIFT;

/// Accepts EffectsAlphaTypeNonPremultiplied and EffectsAlphaTypeAlphaIsOne. Outputs EffectsAlphaTypeNonPremultiplied.
@property (nonatomic, copy, class, readonly) EffectsAlphaTypeHandlingRule *generalAlphaTypeHandlingRule;

/// Accepts all alpha types. The output alpha type is the same as input alpha type.
@property (nonatomic, copy, class, readonly) EffectsAlphaTypeHandlingRule *passthroughAlphaTypeHandlingRule;


@end

NS_ASSUME_NONNULL_END
