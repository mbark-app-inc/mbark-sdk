//
//  EffectsMemoryWarningObserver.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol EffectsMemoryWarningHandling <NSObject>

- (void)handleMemoryWarning;

@end

__attribute__((objc_subclassing_restricted))
@interface EffectsMemoryWarningObserver : NSObject

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

+ (void)addMemoryWarningHandler:(id<EffectsMemoryWarningHandling>)memoryWarningHandler;

+ (void)removeMemoryWarningHandler:(id<EffectsMemoryWarningHandling>)memoryWarningHandler;

@end

NS_ASSUME_NONNULL_END
