//
//  EffectsBlendModes.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Modes that describe how source colors blend with destination colors. See also: https://www.w3.org/TR/compositing-1/
typedef NSString * EffectsBlendMode NS_EXTENSIBLE_STRING_ENUM;

FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeNormal;

FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeDarken;
FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeMultiply;
FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeColorBurn;
FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeLinearBurn;
FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeDarkerColor;

FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeLighten;
FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeScreen;
FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeColorDodge;
FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeAdd; // also LinearDodge
FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeLighterColor;

FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeOverlay;
FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeSoftLight;
FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeHardLight;
FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeVividLight;
FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeLinearLight;
FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModePinLight;
FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeHardMix;

FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeDifference;
FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeExclusion;
FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeSubtract;
FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeDivide;

FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeHue;
FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeSaturation;
FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeColor;
FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeLuminosity;

FOUNDATION_EXPORT EffectsBlendMode const EffectsBlendModeColorLookup512x512;

@class EffectsFunctionDescriptor;

__attribute__((objc_subclassing_restricted))
@interface EffectsBlendFunctionDescriptors: NSObject <NSCopying>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

@property (nonatomic,copy,readonly) EffectsFunctionDescriptor *fragmentFunctionDescriptorForBlendFilter;

@property (nonatomic,copy,readonly,nullable) EffectsFunctionDescriptor *fragmentFunctionDescriptorForMultilayerCompositingFilterWithProgrammableBlending;

@property (nonatomic,copy,readonly,nullable) EffectsFunctionDescriptor *fragmentFunctionDescriptorForMultilayerCompositingFilterWithoutProgrammableBlending;

- (instancetype)initWithFragmentFunctionDescriptorForBlendFilter:(EffectsFunctionDescriptor *)fragmentFunctionDescriptorForBlendFilter
fragmentFunctionDescriptorForMultilayerCompositingFilterWithProgrammableBlending:(nullable EffectsFunctionDescriptor *)fragmentFunctionDescriptorForMultilayerCompositingFilterWithProgrammableBlending
fragmentFunctionDescriptorForMultilayerCompositingFilterWithoutProgrammableBlending:(nullable EffectsFunctionDescriptor *)fragmentFunctionDescriptorForMultilayerCompositingFilterWithoutProgrammableBlending NS_DESIGNATED_INITIALIZER;

/// Creates a `EffectsBlendFunctionDescriptors` using a metal shader function.
///
/// @discussion
/// The name of the function must be `blend`. The function must have exactly two arguments of type `float4`. The first argument represents the value of the backdrop pixel and the second represents the source pixel. The value returned by the function will be the new destination color. All colors should have unpremultiplied alpha component.
///
/// Example:
///
/// @textblock
/// float4 blend(float4 backdrop, float4 source) {
///     return float4(backdrop.rgb + source.rgb, 1.0);
/// }
/// @/textblock
///
/// You can optionally provide a `modify_source_texture_coordinates` function. This function is used to modify the sample coordinates of the source texture. It must have three arguments. The first argument represents the value of the backdrop pixel, the second represents the normalized sample coordinates for the source texture and the third position represents the pixel size of the source texture. The value returned by the function will be the new sample coordinates.
///
/// Example:
///
/// @textblock
/// float2 modify_source_texture_coordinates(float4 backdrop, float2 coordinates, uint2 source_texture_size) {
///     return coordinates;
/// }
///
/// float4 blend(float4 backdrop, float4 source) {
///     return float4(backdrop.rgb + source.rgb, 1.0);
/// }
/// @/textblock

- (instancetype)initWithBlendFormula:(NSString *)formula;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsBlendModes: NSObject

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

@property (nonatomic,copy,readonly,class) NSArray<EffectsBlendMode> *allModes NS_SWIFT_NAME(all);

+ (void)registerBlendMode:(EffectsBlendMode)blendMode withFunctionDescriptors:(EffectsBlendFunctionDescriptors *)functionDescriptors;

+ (void)unregisterBlendMode:(EffectsBlendMode)blendMode;

+ (nullable EffectsBlendFunctionDescriptors *)functionDescriptorsForBlendMode:(EffectsBlendMode)blendMode NS_SWIFT_NAME(functionDescriptors(for:));

@end

NS_ASSUME_NONNULL_END
