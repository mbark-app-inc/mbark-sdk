//
//  EffectsHasher.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

struct EffectsHasher {
    uint64_t _seed;
    BOOL _finalized;
};
typedef struct EffectsHasher EffectsHasher;

NS_INLINE EffectsHasher EffectsHasherMake(NSUInteger seed) {
    //EffectsHasher is designed to work on 64-bit systems.
    assert(sizeof(NSUInteger) == 8);
    return (EffectsHasher){._seed = seed, ._finalized = NO};
}

NS_INLINE __attribute__((__overloadable__)) void EffectsHasherCombine(EffectsHasher *hasher, uint64_t value) {
    //Ref boost::hash_combine
    //Ref https://stackoverflow.com/questions/4948780/magic-number-in-boosthash-combine
    hasher -> _seed ^= value + 0x9e3779b97f4a7c15 + (hasher -> _seed << 6) + (hasher -> _seed >> 2);
}

NS_INLINE __attribute__((__overloadable__)) void EffectsHasherCombine(EffectsHasher *hasher, unsigned int intValue) {
    uint64_t value = intValue;
    EffectsHasherCombine(hasher, value);
}

NS_INLINE __attribute__((__overloadable__)) void EffectsHasherCombine(EffectsHasher *hasher, unsigned long intValue) {
    uint64_t value = intValue;
    EffectsHasherCombine(hasher, value);
}

NS_INLINE __attribute__((__overloadable__)) void EffectsHasherCombine(EffectsHasher *hasher, double doubleValue) {
    static_assert(sizeof(uint64_t) == sizeof(double), "");
    uint64_t value = *(uint64_t *)&doubleValue;
    EffectsHasherCombine(hasher, value);
}

NS_INLINE __attribute__((__overloadable__)) void EffectsHasherCombine(EffectsHasher *hasher, float floatValue) {
    double doubleValue = floatValue;
    EffectsHasherCombine(hasher, doubleValue);
}

NS_INLINE NSUInteger EffectsHasherFinalize(EffectsHasher *hasher) {
    NSCParameterAssert(hasher -> _finalized == NO);
    hasher -> _finalized = YES;
    return (NSUInteger)hasher -> _seed;
}

NS_ASSUME_NONNULL_END
