#pragma once

#include <dawn/exports.h>

namespace sgd {

SGD_SHARED(Material);
SGD_SHARED(BindGroup);

enum struct RenderPassType {shadow, opaque, blend, effect};
constexpr int numRenderPassTypes = 4;

enum struct BlendMode { undefined, opaque, alphaMask, alphaBlend };

enum struct DepthFunc { undefined, never, less, equal, lessEqual, greater, notEqual, greaterEqual, always };

enum struct CullMode { undefined, none, front, back };

wgpu::RenderPipeline getOrCreateRenderPipeline(RenderPassType rpassType,
											   BlendMode blendMode,	 //
											   DepthFunc depthFunc,	 //
											   CullMode cullMode,	 //
											   CBindGroup* bindings1, //
											   CBindGroup* bindings2, //
											   CBindGroup* bindings3);

wgpu::RenderPipeline getOrCreateRenderPipeline(RenderPassType rpassType, //
											   CMaterial* material,		 //
											   CBindGroup* geometry,	 //
											   CBindGroup* renderer);	 //
} // namespace sgd
