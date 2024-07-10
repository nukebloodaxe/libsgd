#pragma once

#include "mesh.h"

namespace sgd {

struct alignas(16) SkinnedMeshInstance {
	static constexpr int maxJoints = 256;
	Mat4f matrix;
	Vec4f color;
	Mat4f jointMatrices[maxJoints];
};

SGD_SHARED(RenderContext);

SGD_SHARED(SkinnedMeshRenderer);

struct SkinnedMeshRenderer : Shared {
	SGD_OBJECT_TYPE(SkinnedMeshRenderer, Shared);

	explicit SkinnedMeshRenderer(CMesh* mesh);

	SkinnedMeshInstance* lockInstances(uint32_t numInstances);
	void unlockInstances();

	void render(RenderContext* rc) const;

private:
	CMeshPtr m_mesh;
	BindGroupPtr m_bindGroup;
	uint32_t m_instanceCapacity{};
	uint32_t m_instanceCount{};
	BufferPtr m_instanceBuffer;
};

}
