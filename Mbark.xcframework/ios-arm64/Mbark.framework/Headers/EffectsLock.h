//
//  EffectsLock.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol EffectsLocking <NSLocking>

- (BOOL)tryLock;

@end

///Create a non-recursive lock. Unlocking a lock from a different thread other than the locking thread can result in undefined behavior.
FOUNDATION_EXPORT id<EffectsLocking> EffectsLockCreate(void) NS_RETURNS_RETAINED;

NS_ASSUME_NONNULL_END
