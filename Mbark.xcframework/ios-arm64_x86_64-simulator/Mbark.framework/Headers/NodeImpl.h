//
//  NodeImpl.h
//  Mbark
//
//  Created by Nate de Jager on 2021-08-11.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "Layout.h"

/// The private wrapper around `css_node_t`.
///
/// This should not be used directly. It's only visible becase of swift
/// reasons. See `Layout` instead.
@interface NodeImpl : NSObject

@property (nonatomic, readonly, assign) css_node_t *node;

@property (nonatomic, copy) NSArray *children;

@property (nonatomic, readonly, assign) CGRect frame;

@property (nonatomic, copy) CGSize (^measure)(CGFloat width);

- (void)layout;

- (void)layoutWithMaxWidth:(CGFloat)maxWidth;

@end
