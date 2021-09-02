//
//  EffectsVertex.h
//  Mbark
//
//  Created by Nate de Jager on 2021-06-07.
//

#import <Accelerate/Accelerate.h>
#import <simd/simd.h>
#import <Metal/Metal.h>
#import <EffectsShaderLib.h>
#import <EffectsGeometry.h>
#import <EffectsBuffer.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT EffectsVertex EffectsVertexMake(float x, float y, float z, float w, float u, float v) NS_SWIFT_NAME(EffectsVertex.init(x:y:z:w:u:v:));
FOUNDATION_EXPORT BOOL EffectsVertexEqualToVertex(EffectsVertex v1, EffectsVertex v2) NS_SWIFT_NAME(EffectsVertex.isEqual(self:to:));


/// A EffectsGeometry implementation. A EffectsVertices contains EffectsVertex data structures. It is designed to handle small amount of vertices. A EffectsVertices bounds its contents to the vertex buffer with index of 0. The shader receives a EffectsVertices' contents as `EffectsVertex *`. e.g. `const device EffectsVertex * vertices [[ buffer(0) ]]`.
__attribute__((objc_subclassing_restricted))
@interface EffectsVertices : NSObject <EffectsGeometry>

@property (nonatomic, readonly) NSUInteger vertexCount;

@property (nonatomic, readonly) NSUInteger indexCount;

@property (nonatomic, readonly) MTLPrimitiveType primitiveType;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithVertices:(const EffectsVertex * _Nonnull)vertices
                           count:(NSUInteger)count
                   primitiveType:(MTLPrimitiveType)primitiveType NS_DESIGNATED_INITIALIZER NS_REFINED_FOR_SWIFT;

/// Create a `EffectsVertices` instance with `EffectsDataBuffer` objects. The contents of the vertexBuffer must be `EffectsVertex *`. Only `MTLIndexTypeUInt32` is supported, so the contents of the indexBuffer must be `uint32_t *`.
- (instancetype)initWithVertexBuffer:(EffectsDataBuffer *)vertexBuffer
                         vertexCount:(NSUInteger)vertexCount
                         indexBuffer:(nullable EffectsDataBuffer *)indexBuffer
                          indexCount:(NSUInteger)indexCount
                       primitiveType:(MTLPrimitiveType)primitiveType NS_DESIGNATED_INITIALIZER;

+ (instancetype)squareVerticesForRect:(CGRect)rect;

+ (instancetype)verticallyFlippedSquareVerticesForRect:(CGRect)rect;

@property (nonatomic, class, readonly, strong) EffectsVertices *fullViewportSquareVertices;

@end

NS_ASSUME_NONNULL_END


@interface EffectsDataBuffer (EffectsVertices)

+ (nullable instancetype)dataBufferWithEffectsVertices:(const EffectsVertex * _Nonnull)vertices count:(NSUInteger)count NS_REFINED_FOR_SWIFT;

+ (nullable instancetype)dataBufferWithUInt32Indexes:(const uint32_t * _Nonnull)indexes count:(NSUInteger)count NS_REFINED_FOR_SWIFT;

@end
