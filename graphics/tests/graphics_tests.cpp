#include <graphics/exports.h>

#include <graphics/shaders/uniforms.h>

using namespace sgd;

WindowPtr window;
GraphicsContextPtr gc;

MeshRendererPtr meshRenderer;

CameraUniforms camera;
LightingUniforms lighting;

void render() {

	static float camRot;
	camera.worldMatrix = Mat4f(AffineMat4f::TRS({0, 0, -3}));

	camera.viewMatrix = inverse(camera.worldMatrix);
	camera.projectionMatrix = Mat4f::perspective(45, (float)window->size().x / (float)window->size().y, .1, 100);
	camera.inverseProjectionMatrix = inverse(camera.projectionMatrix);
	camera.viewProjectionMatrix = camera.projectionMatrix * camera.viewMatrix;
	gc->bindGroup0()->getBuffer(0)->update(&camera, 0, sizeof(camera));

	gc->bindGroup0()->getBuffer(1)->update(&lighting, 0, sizeof(lighting));

	{
		static float meshRot;
		auto insts = meshRenderer->lockInstances(1);
		insts[0].matrix = Mat4f(AffineMat4f::TRS({0, 0, 0}, {0, meshRot += .0002, 0}));
		insts[0].color = {1, 1, 1, 1};
		meshRenderer->unlockInstances();
	}
	GraphicsResource::validateAll(gc);

	gc->beginRender({0, 0, 0, 1}, 1);
	{
		gc->beginRenderPass(RenderPass::clear);
		gc->endRenderPass();

		gc->beginRenderPass(RenderPass::opaque);
		meshRenderer->render(gc);
		gc->endRenderPass();
	}
	gc->endRender();

	gc->present(gc->colorBuffer());
}

void rrender() {
	if (!window->pollEvents()) std::exit(0);

	requestRender(rrender);

	render();
}

void start() {

	{
		window = new Window({1280, 960}, "Hello world!", sgd::WindowFlags::resizable);

		gc = new GraphicsContext(window);

		window->sizeChanged.connect(nullptr, [](CVec2u){
			render();
		});
	}

	{
		TexturePtr envTexture =
			loadTexture(Path("sunnysky-cube.png"), TextureFormat::srgba8, TextureFlags::cube | TextureFlags::filter).result();

		gc->bindGroup0()->setTexture(2, envTexture);

		lighting.pointLightCount = 1;
		lighting.ambientLightColor = {1, 1, 1, 0};
		lighting.pointLights[0].position = {2.5, 2.5, -2.5};
		lighting.pointLights[0].color = {1, 1, 1, 1};
		lighting.pointLights[0].falloff = 1;
		lighting.pointLights[0].range = 25;
	}

	{
		MaterialPtr material = loadMaterial(Path("Bricks076C_1K-JPG")).result();
		//MaterialPtr material = loadMaterial(Path("Marble008_1K-JPG")).result();
		// MaterialPtr material = loadMaterial(Path("Facade001_1K-JPG"));
		//MaterialPtr material = loadMaterial(Path("Facade018A_1K-JPG"));
		//MaterialPtr material = loadMaterial(Path("PavingStones131_1K-JPG"));

		MeshPtr mesh = createSphereMesh(1, 64, 32, material);
		//MeshPtr mesh = createBoxMesh(Boxf(-1, 1), material);

		transformTexCoords(mesh, {4,2}, {0,0});

		meshRenderer = new MeshRenderer(mesh);
		auto insts = meshRenderer->lockInstances(1);
		insts[0].matrix = {};
		insts[0].color = {1, 1, 1, 1};
		meshRenderer->unlockInstances();
	}

	requestRender(rrender);
}

int main() {

	requestWGPUDevice({}, [](const wgpu::Device&) { start(); });

	beginAppEventLoop();
}
