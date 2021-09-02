//
//  EffectsLibrarySource.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Metal/Metal.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString * const EffectsURLSchemeForLibraryWithSource;

FOUNDATION_EXPORT NSString * const EffectsLibrarySourceErrorDomain;

typedef NS_ERROR_ENUM(EffectsLibrarySourceErrorDomain, EffectsLibrarySourceError) {
    EffectsLibrarySourceErrorLibraryNotFound = 10001
};

/// EffectsLibrarySourceRegistration can be used under the situation where it is impossible to use a offline metal compiler. You should avoid using this class as possbile as you can.
__attribute__((objc_subclassing_restricted))
@interface EffectsLibrarySourceRegistration : NSObject

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, strong, readonly, class) EffectsLibrarySourceRegistration *sharedRegistration;

/// Returns a URL representing the metal library compiled with the `source` code. This URL can be used in `EffectsFunctionDescriptor(name:libraryURL:)`.
- (NSURL *)registerLibraryWithSource:(NSString *)source
                      compileOptions:(nullable MTLCompileOptions *)compileOptions NS_SWIFT_NAME(registerLibrary(source:compileOptions:));

- (void)unregisterLibraryWithURL:(NSURL *)url;

@end

@interface EffectsLibrarySourceRegistration (Internal)

- (nullable id<MTLLibrary>)newLibraryWithURL:(NSURL *)libraryURL device:(id<MTLDevice>)device error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
