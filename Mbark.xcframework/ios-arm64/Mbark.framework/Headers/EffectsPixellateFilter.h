//
//  EffectsPixellateFilter.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-08.
//

#import "EffectsUnaryImageRenderingFilter.h"

__attribute__((objc_subclassing_restricted))
@interface EffectsPixellateFilter : EffectsUnaryImageRenderingFilter

/// Specifies the scale of the operation, i.e. the size for the pixels in the resulting image.
@property (nonatomic) CGSize scale;

@end
