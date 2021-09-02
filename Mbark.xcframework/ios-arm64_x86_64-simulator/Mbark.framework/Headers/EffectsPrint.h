//
//  EffectsPrint.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Foundation/Foundation.h>

#if !defined(EffectsPrint)

#if DEBUG

#define EffectsPrint(format, ...) do { \
    if (getenv("Effects_PRINT_ENABLED") != NULL) {\
        NSLog(format, ##__VA_ARGS__); \
    }\
} while(0)

#else

#define EffectsPrint(format, ...) do { } while(0)

#endif

#endif
