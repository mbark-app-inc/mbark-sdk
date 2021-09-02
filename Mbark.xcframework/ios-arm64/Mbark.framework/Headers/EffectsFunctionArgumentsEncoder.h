//
//  EffectsFunctionArgumentsEncoder.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Metal/Metal.h>

NS_ASSUME_NONNULL_BEGIN

@protocol EffectsFunctionArgumentEncodingProxy <NSObject>

- (void)encodeBytes:(const void *)bytes length:(NSUInteger)length;

@end

@protocol EffectsFunctionArgumentEncoding <NSObject>

+ (BOOL)encodeValue:(id)value argument:(MTLArgument *)argument proxy:(id<EffectsFunctionArgumentEncodingProxy>)proxy error:(NSError **)error;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsFunctionArgumentsEncoder : NSObject

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

+ (BOOL)encodeArguments:(NSArray<MTLArgument *>*)arguments
                 values:(NSDictionary<NSString *, id> *)parameters
           functionType:(MTLFunctionType)functionType
                encoder:(id<MTLCommandEncoder>)encoder
                  error:(NSError **)error;

@end


NS_ASSUME_NONNULL_END
