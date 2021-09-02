//
//  EffectsDefer.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Foundation/Foundation.h>

#define Effects_METAMACRO_CONCAT(A, B) \
Effects_METAMACRO_CONCAT_(A, B)

#define Effects_METAMACRO_CONCAT_(A, B) A ## B

#define Effects_DEFER \
try {} @finally {} \
__strong EffectsDeferBlock Effects_METAMACRO_CONCAT(EffectsExitBlock_, __LINE__) __attribute__((cleanup(EffectsExecuteCleanupBlock), unused)) = ^

typedef void (^EffectsDeferBlock)(void);

FOUNDATION_EXPORT void EffectsExecuteCleanupBlock (__strong EffectsDeferBlock *block);
