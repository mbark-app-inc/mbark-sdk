//
//  EffectsSamplerDescriptor.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Metal/Metal.h>

NS_ASSUME_NONNULL_BEGIN

/// An immutable wrapper for MTLSamplerDescriptor.
__attribute__((objc_subclassing_restricted))
@interface EffectsSamplerDescriptor : NSObject <NSCopying>

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithMTLSamplerDescriptor:(MTLSamplerDescriptor *)samplerDescriptor NS_DESIGNATED_INITIALIZER;

- (MTLSamplerDescriptor *)newMTLSamplerDescriptor NS_SWIFT_NAME(makeMTLSamplerDescriptor());

@property (nonatomic, readonly, class) EffectsSamplerDescriptor *defaultSamplerDescriptor;

+ (instancetype)defaultSamplerDescriptorWithAddressMode:(MTLSamplerAddressMode)addressMode;

@end

@interface MTLSamplerDescriptor (EffectsSamplerDescriptor)

- (EffectsSamplerDescriptor *)newEffectsSamplerDescriptor NS_SWIFT_NAME(makeEffectsSamplerDescriptor());

@end

NS_ASSUME_NONNULL_END
