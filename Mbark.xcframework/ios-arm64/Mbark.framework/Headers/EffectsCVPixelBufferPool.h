//
//  EffectsCVPixelBufferPool.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString * const EffectsCVPixelBufferPoolErrorDomain;

typedef NS_ERROR_ENUM(EffectsCVPixelBufferPoolErrorDomain, EffectsCVPixelBufferPoolError) {
    EffectsCVPixelBufferPoolErrorNone = kCVReturnSuccess,
    EffectsCVPixelBufferPoolErrorWouldExceedAllocationThreshold = kCVReturnWouldExceedAllocationThreshold,
    EffectsCVPixelBufferPoolErrorPoolAllocationFailed = kCVReturnPoolAllocationFailed,
    EffectsCVPixelBufferPoolErrorInvalidPoolAttributes = kCVReturnInvalidPoolAttributes,
    EffectsCVPixelBufferPoolErrorRetry = kCVReturnRetry
};

__attribute__((objc_subclassing_restricted))
@interface EffectsCVPixelBufferPool : NSObject

@property (nonatomic, readonly) size_t pixelBufferWidth;
@property (nonatomic, readonly) size_t pixelBufferHeight;

@property (nonatomic, readonly) NSUInteger minimumBufferCount;

@property (nonatomic, readonly) OSType pixelFormatType;

@property (nonatomic, copy, readonly) NSString *pixelFormatDescription;

@property (nonatomic, copy, readonly) NSDictionary *poolAttributes;
@property (nonatomic, copy, readonly) NSDictionary *pixelBufferAttributes;

@property (nonatomic, readonly) CVPixelBufferPoolRef internalPool NS_RETURNS_INNER_POINTER;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (nullable instancetype)initWithPixelBufferWidth:(size_t)width pixelBufferHeight:(size_t)height pixelFormatType:(OSType)pixelFormatType minimumBufferCount:(NSUInteger)minimumBufferCount error:(NSError **)error;

- (nullable instancetype)initWithPoolAttributes:(NSDictionary *)poolAttributes pixelBufferAttributes:(NSDictionary *)pixelBufferAttributes error:(NSError **)error;

- (instancetype)initWithCVPixelBufferPool:(CVPixelBufferPoolRef)pixelBufferPool NS_DESIGNATED_INITIALIZER;

- (nullable CVPixelBufferRef)newPixelBufferWithAllocationThreshold:(NSUInteger)allocationThreshold error:(NSError **)error CF_RETURNS_RETAINED NS_SWIFT_NAME(makePixelBuffer(allocationThreshold:));

- (void)flush:(CVPixelBufferPoolFlushFlags)flags;

@end

NS_ASSUME_NONNULL_END
