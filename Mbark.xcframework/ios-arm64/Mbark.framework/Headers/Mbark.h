//
//  mbark.h
//  mbark
//
//  Created by Nate de Jager on 2021-03-29.
//

#import <Foundation/Foundation.h>
#import <CoreTelephony/CTCallCenter.h>
#import <CoreTelephony/CTCall.h>
#import <CoreTelephony/CTCarrier.h>
#import <CoreTelephony/CTTelephonyNetworkInfo.h>
#include <ifaddrs.h>
#import <objc/runtime.h>
#import <objc/message.h>

//! Project version number for mbark.
FOUNDATION_EXPORT double mbarkVersionNumber;

//! Project version string for mbark.
FOUNDATION_EXPORT const unsigned char mbarkVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <mbark/PublicHeader.h>

NS_ASSUME_NONNULL_BEGIN

extern const IMP _mbark_objc_msgForward;

NS_ASSUME_NONNULL_END

