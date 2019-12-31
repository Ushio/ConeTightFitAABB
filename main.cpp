#include "pr.hpp"
#include <iostream>
#include <memory>

int main() {
    using namespace pr;

    Config config;
    config.ScreenWidth = 1920;
    config.ScreenHeight = 1080;
    config.SwapInterval = 1;
    Initialize(config);

    Camera3D camera;
    camera.origin = { 4, 8, 8 };
    camera.lookat = { 0, 0, 0 };
    camera.zUp = false;

    double e = GetElapsedTime();

	glm::vec3 p0 = { -2, 2, -3 };
	glm::vec3 p1 = { 2, 5, 1 };
	float r0 = 0.5f;
	float r1 = 1.0f;

    while (pr::NextFrame() == false) {
        if (IsImGuiUsingMouse() == false) {
            UpdateCameraBlenderLike(&camera);
        }

        ClearBackground(0.1f, 0.1f, 0.1f, 1);

        BeginCamera(camera);

        PushGraphicState();

        DrawGrid(GridAxis::XZ, 1.0f, 10, { 128, 128, 128 });
        DrawXYZAxis(1.0f);

		DrawTube(p0, p1, r0, r1, {255, 255, 0}, 32);

		glm::vec3 a = p1 - p0;
		glm::vec3 e = glm::sqrt(
			glm::max(
				glm::vec3(1.0f) - a * a / glm::dot(a, a),
				glm::vec3(0.0f)
			)
		);

		glm::vec3 lower = glm::min(p0 - e * r0, p1 - e * r1);
		glm::vec3 upper = glm::max(p0 + e * r0, p1 + e * r1);
		DrawAABB(lower, upper, {255, 255, 255}, 2);

        ManipulatePosition(camera, &p0, 0.5f);
        ManipulatePosition(camera, &p1, 0.5f);

        PopGraphicState();
        EndCamera();

        BeginImGui();

        ImGui::SetNextWindowSize({ 500, 800 }, ImGuiCond_Once);
        ImGui::Begin("Panel");
		ImGui::Text("fps = %f", GetFrameRate());
        ImGui::SliderFloat("perspective", &camera.perspective, 0, 1);
        ImGui::SliderFloat("r1", &r0, 0, 1);
        ImGui::SliderFloat("r2", &r1, 0, 1);

        ImGui::End();

        EndImGui();
    }

    pr::CleanUp();
}
