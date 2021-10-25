// Generated by Apple Swift version 5.5 (swiftlang-1300.0.31.1 clang-1300.0.29.1)
#ifndef MBARK_SWIFT_H
#define MBARK_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import ObjectiveC;
@import UIKit;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="Mbark",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif





@class NSNumber;
@class NSString;
@class MbarkInstance;
enum MbarkEventType : NSInteger;
@class MbarkEventData;
@class UINavigationController;
@class MbarkViewController;
@class MbarkActionHandler;
@class MbarkPurchaseActionHandler;

SWIFT_CLASS("_TtC5Mbark5Mbark")
@interface Mbark : NSObject
/// Tracks whether the SDK is active / enabled based on the availability of the main mbark instance
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) BOOL isActive;)
+ (BOOL)isActive SWIFT_WARN_UNUSED_RESULT;
/// Initializes an instance of the API with the host’s ‘MbarkInfo.plist’ file..
/// Returns a new Mbark instance object. This allows us to create more than one instance of the API, which is
/// convenient if we’d like to send data to more than one flow from a single app.
+ (MbarkInstance * _Nullable)initializeSDKWithInstanceName:(NSString * _Nonnull)instanceName selectedLanguage:(NSString * _Nullable)selectedLanguage;
/// Initializes an instance of the API with manually added API info (config ID and (prod | dev) API Key).
/// Returns a new Mbark instance object. This allows us to create more than one instance of the API, which is
/// convenient if we’d like to send data to more than one flow from a single app.
+ (MbarkInstance * _Nullable)initializeSDKWithInstanceName:(NSString * _Nonnull)instanceName remoteConfigId:(NSString * _Nonnull)remoteConfigId productionAPIKey:(NSString * _Nullable)productionAPIKey developmentAPIKey:(NSString * _Nullable)developmentAPIKey selectedLanguage:(NSString * _Nullable)selectedLanguage;
/// Sets the main instance based on the instance name
/// \param name the instance name
///
+ (void)setMainInstanceWithName:(NSString * _Nonnull)name;
/// Removes an unneeded Mbark instance based on its name
/// \param name the instance name
///
+ (void)removeInstanceWithName:(NSString * _Nonnull)name;
/// Tracks Mbark events
+ (void)trackWithEventType:(enum MbarkEventType)eventType step:(NSString * _Nullable)step component:(NSString * _Nullable)component data:(MbarkEventData * _Nullable)data;
/// Track singular Mbark events
+ (void)trackOnceWithEventType:(enum MbarkEventType)eventType step:(NSString * _Nullable)step component:(NSString * _Nullable)component data:(MbarkEventData * _Nullable)data;
/// Helper method used to simplify tracking flow starts
+ (void)trackFlowStart;
/// Helper method used to simplify tracking flow ends
+ (void)trackFlowEnd;
/// Helper method used to simplify tracking step views - used in cases where we can’t register the step with an mbark id
/// for example, SSO-flows
+ (void)trackStepView:(NSString * _Nonnull)step data:(MbarkEventData * _Nullable)data;
/// Helper method used to simplify tracking new user authentication events
+ (void)trackAuthenticationForNewUser;
/// Helper method used to simplify tracking existing user authentication events
+ (void)trackAuthenticationForExistingUser;
/// Helper method used to simplify tracking accept events
+ (void)trackAcceptWithStep:(NSString * _Nullable)step component:(NSString * _Nullable)component shouldTrackOnce:(BOOL)shouldTrackOnce;
/// Helper method used to simplify tracking reject events
+ (void)trackRejectWithStep:(NSString * _Nullable)step component:(NSString * _Nullable)component shouldTrackOnce:(BOOL)shouldTrackOnce;
/// Helper method used to simplify tracking tap events
+ (void)trackTapWithStep:(NSString * _Nullable)step component:(NSString * _Nullable)component data:(MbarkEventData * _Nullable)data;
/// Helper method used to simplify tracking input events
+ (void)trackInputWithStep:(NSString * _Nullable)step component:(NSString * _Nullable)component data:(MbarkEventData * _Nullable)data;
/// Helper method used to simplify tracking app loading
+ (void)trackAppLoading;
+ (UINavigationController * _Nullable)userFlowWithStartingViewId:(NSString * _Nonnull)mbarkId onLoaded:(void (^ _Nullable)(BOOL))onLoaded SWIFT_WARN_UNUSED_RESULT;
+ (MbarkViewController * _Nullable)userViewForMbarkId:(NSString * _Nonnull)mbarkId onLoaded:(void (^ _Nullable)(BOOL))onLoaded SWIFT_WARN_UNUSED_RESULT;
+ (void)addActionHandler:(MbarkActionHandler * _Nonnull)actionHandler;
+ (void)removeActionHandlerForId:(NSString * _Nonnull)id;
+ (void)addPurchaseActionHandler:(MbarkPurchaseActionHandler * _Nonnull)purchaseActionHandler;
+ (void)removePurchaseActionHandlerForId:(NSString * _Nonnull)id;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC5Mbark18MbarkActionHandler")
@interface MbarkActionHandler : NSObject
- (nonnull instancetype)initWithId:(NSString * _Nonnull)id handler:(void (^ _Nonnull)(void))handler OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, readonly, copy) NSString * _Nonnull id;
- (void)finishWithSuccess:(BOOL)success;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


/// Allows hosting app to add optional context to action.
SWIFT_CLASS("_TtC5Mbark14MbarkEventData")
@interface MbarkEventData : NSObject
- (nonnull instancetype)initWithName:(NSString * _Nonnull)name value:(NSString * _Nonnull)value OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


/// Event action type
typedef SWIFT_ENUM(NSInteger, MbarkEventType, open) {
  MbarkEventTypeAccept = 0,
  MbarkEventTypeAuthenticate = 1,
  MbarkEventTypeBackground = 2,
  MbarkEventTypeForeground = 3,
  MbarkEventTypeFlowStart = 4,
  MbarkEventTypeFlowEnd = 5,
  MbarkEventTypeInput = 6,
  MbarkEventTypeLongPress = 7,
  MbarkEventTypeReject = 8,
  MbarkEventTypeSwipeLeft = 9,
  MbarkEventTypeSwipeRight = 10,
  MbarkEventTypeTap = 11,
  MbarkEventTypeView = 12,
};


SWIFT_CLASS("_TtC5Mbark13MbarkInstance")
@interface MbarkInstance : NSObject
@property (nonatomic, readonly, copy) NSString * _Nonnull debugDescription;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end







SWIFT_CLASS("_TtC5Mbark26MbarkPurchaseActionHandler")
@interface MbarkPurchaseActionHandler : NSObject
- (nonnull instancetype)initWithId:(NSString * _Nonnull)id handler:(void (^ _Nonnull)(NSString * _Nonnull))handler OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, copy) void (^ _Nullable finish)(BOOL);
@property (nonatomic, readonly, copy) NSString * _Nonnull id;
- (void)finishWithSuccess:(BOOL)success;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

typedef SWIFT_ENUM(NSInteger, MbarkStepNames, open) {
  MbarkStepNamesLoading = 0,
};

@class NSCoder;
@class NSBundle;

SWIFT_CLASS("_TtC5Mbark19MbarkViewController")
@interface MbarkViewController : UIViewController
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder SWIFT_UNAVAILABLE;
- (void)viewDidLoad;
- (void)viewDidLayoutSubviews;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil SWIFT_UNAVAILABLE;
@end














































#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
#endif
