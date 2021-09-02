//
//  EffectsImagePromiseDebug.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>

@protocol EffectsImagePromise;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, EffectsImagePromiseType) {
    EffectsImagePromiseTypeSource,
    EffectsImagePromiseTypeProcessor
};

FOUNDATION_EXPORT NSString * EffectsImagePromiseDebugIdentifierForObject(id object);

__attribute__((objc_subclassing_restricted))
@interface EffectsImagePromiseDebugInfo : NSObject

@property (nonatomic,copy,readonly) NSString *identifier;

@property (nonatomic,readonly) EffectsImagePromiseType type;

@property (nonatomic,copy,readonly) NSString *title;

@property (nonatomic,strong,readonly,nullable) id content;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithPromise:(id<EffectsImagePromise>)promise
                           type:(EffectsImagePromiseType)type
                        content:(id)content;

@end

@interface EffectsImagePromiseDebugInfo (RenderGraph)

+ (CALayer *)layerRepresentationOfRenderGraphForPromise:(id<EffectsImagePromise>)promise;

@end

NS_ASSUME_NONNULL_END
