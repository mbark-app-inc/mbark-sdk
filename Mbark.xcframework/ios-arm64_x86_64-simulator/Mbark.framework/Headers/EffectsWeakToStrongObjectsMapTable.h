//
//  EffectsWeakToStrongMapTable.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Behaves like NSMapTable with key options: NSMapTableObjectPointerPersonality|NSMapTableWeakMemory, value options: NSMapTableStrongMemory. Entries are purged right away when the weak key is reclaimed.

__attribute__((objc_subclassing_restricted))
@interface EffectsWeakToStrongObjectsMapTable <KeyType, ObjectType> : NSObject

- (nullable ObjectType)objectForKey:(KeyType)aKey;

- (void)removeObjectForKey:(KeyType)aKey;

- (void)setObject:(nullable ObjectType)anObject forKey:(KeyType)aKey;

- (void)removeAllObjects;

- (void)compact;

@end

NS_ASSUME_NONNULL_END
