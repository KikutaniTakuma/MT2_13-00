#include "Game/Camera/Camera.h"
#include "Game/Frame/Frame.h"
#include "Game/Texture/Texture.h"
#include "Game/Quad/Quad.h"
#include "Game/MyMath/MyMath.h"
#include "Game/KeyInput/KeyInput.h"
#include "Game/World/World.h"

#include <Novice.h>

#include <stdlib.h>
#include <limits.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <format>

Camera::sclock::time_point Camera::start = Camera::sclock::time_point(), 
Camera::end = Camera::sclock::time_point(), 
Camera::totalStart = Camera::sclock::time_point(),
Camera::totalEnd = Camera::sclock::time_point();
Camera::sclock::duration Camera::total = Camera::sclock::duration();

float Camera::delta = 0.0f;
bool Camera::hitStop = false;
bool Camera::fpsDrwFlg = true;

Camera::Camera(World* world) :
	worldPos({ world->width / 2.0f, world->height / 2.0f }),
	screenPos(Vector2D()),
	drawLeftTop({ world->width / -2.0f, world->height / 2.0f }),
	drawRightBottom({ world->width / 2.0f, world->height / -2.0f }),
	size({ world->width, world->height }),
	scale(1.0f),
	frame(new Frame),
	shakeScale({ 10.0f,10.0f }),
	shakeFlg(false),
	drawLength(100.0f),
	world(world)
{
	viewMatrix.Translate(worldPos);
	viewMatrix.Inverse();

	NorDevMatrix.Orthographic(drawLeftTop, drawRightBottom);

	viewPortMatrix.Viewport(screenPos, size);

	frame->Restart();
}

Camera::~Camera(){
	delete frame;
}

void Camera::Update() {
	Vector2D tmp = this->worldPos;
	if (shakeFlg) {
		Shake();
	}
	viewMatrix.Translate(this->worldPos);
	viewMatrix.Inverse();

	worldPos = tmp;

	NorDevMatrix.Orthographic(size);
	viewPortMatrix.Viewport(screenPos, size);

	vpvpMatrix = viewMatrix * NorDevMatrix * viewPortMatrix;

	frame->Start();
	if (frame->getFrame() > ULLONG_MAX) {
		frame->Stop();
		frame->Restart();
	}
}

void Camera::Update(const Vector2D& worldPos, const Vector2D& cameraPos, const float& scale, const bool& shake) {
	frame->Start();
	if (frame->getFrame() > ULLONG_MAX) {
		frame->Stop();
		frame->Restart();
	}

	this->scale = scale;

	this->worldPos = worldPos;

	// もしシェイクフラグがオンなら
	if (shake) {
		Shake();
	}

	viewMatrix.Translate(this->worldPos);
	viewMatrix.Inverse();
	NorDevMatrix.Orthographic(size / this->scale);
	viewPortMatrix.Viewport(cameraPos, size);

	vpvpMatrix = viewMatrix * NorDevMatrix * viewPortMatrix;
}

void Camera::Update(const Vector2D& worldPos, const Vector2D& cameraPos, const Vector2D& drawLeftTop, const Vector2D& drawRightBottom, const bool& shake) {
	frame->Start();
	if (frame->getFrame() > ULLONG_MAX) {
		frame->Stop();
		frame->Restart();
	}

	this->worldPos = worldPos;

	// もしシェイクフラグがオンなら
	if (shake) {
		Shake();
	}
	this->drawLeftTop = drawLeftTop;
	this->drawRightBottom = drawRightBottom;

	viewMatrix.Translate(this->worldPos);
	viewMatrix.Inverse();
	NorDevMatrix.Orthographic(this->drawLeftTop, this->drawRightBottom);
	viewPortMatrix.Viewport(cameraPos, size);

	vpvpMatrix = viewMatrix * NorDevMatrix * viewPortMatrix;
}


void Camera::Shake() {
	worldPos.x += static_cast<float>(MyMath::Random(static_cast<int>(-shakeScale.x), static_cast<int>(shakeScale.x)));
	worldPos.y += static_cast<float>(MyMath::Random(static_cast<int>(-shakeScale.y), static_cast<int>(shakeScale.y)));
}

void Camera::DrawQuad(Quad quad, Texture& texture, float animationSpd, const unsigned int& color) const {
	if (isDraw(quad.worldPos,drawLength)) {
		quad.Translate();

		quad.worldMatrix *= vpvpMatrix;

		animationSpd *= delta * static_cast<float>(!hitStop);

		if (animationSpd != 0) {
			if (frame->getFrame() % static_cast<int>(animationSpd) == 0) {
				texture.drawPos += texture.width;
				if (texture.drawPos > texture.spriteSize - texture.width) {
					texture.drawPos = 0;
				}
			}
		}

		Novice::DrawQuad(
			static_cast<int>(quad.getMatrixLeftTop().x), static_cast<int>(quad.getMatrixLeftTop().y),
			static_cast<int>(quad.getMatrixRightTop().x), static_cast<int>(quad.getMatrixRightTop().y),
			static_cast<int>(quad.getMatrixLeftUnder().x), static_cast<int>(quad.getMatrixLeftUnder().y),
			static_cast<int>(quad.getMatrixRightUnder().x), static_cast<int>(quad.getMatrixRightUnder().y),
			texture.drawPos, 0, texture.width, texture.height, texture.textureHandle, color
		);
	}
}


void Camera::DrawUI(Quad quad, Texture& texture, float animationSpd, const unsigned int& color) const {
	quad.worldPos += (worldPos - (size/ 2.0f));
	quad.Translate();
	quad.worldMatrix *= vpvpMatrix;

	animationSpd *= delta * static_cast<float>(!hitStop);

	if (animationSpd != 0) {
		if (frame->getFrame() % static_cast<int>(animationSpd) == 0) {
			texture.drawPos += texture.width;
			if (texture.drawPos > texture.spriteSize - texture.width) {
				texture.drawPos = 0;
			}
		}
	}

	Novice::DrawQuad(
		static_cast<int>(quad.getMatrixLeftTop().x), static_cast<int>(quad.getMatrixLeftTop().y),
		static_cast<int>(quad.getMatrixRightTop().x), static_cast<int>(quad.getMatrixRightTop().y),
		static_cast<int>(quad.getMatrixLeftUnder().x), static_cast<int>(quad.getMatrixLeftUnder().y),
		static_cast<int>(quad.getMatrixRightUnder().x), static_cast<int>(quad.getMatrixRightUnder().y),
		texture.drawPos, 0, texture.width, texture.height, texture.textureHandle, color
	);
}


bool Camera::isDraw(Vector2D pos, const float& drawLength) const {
	pos -= worldPos;
	if (pos.x < drawLeftTop.x - drawLength || pos.x > drawRightBottom.x + drawLength ||
		pos.y > drawLeftTop.y + drawLength || pos.y < drawRightBottom.y - drawLength) {
		return false;
	}
	else {
		return true;
	}
}

Vector2D Camera::getPos() const {
	return worldPos;
}

Vector2D Camera::getDrawLeftTop() const {
	return drawLeftTop;
}
Vector2D Camera::getDrawRightBottom() const {
	return drawRightBottom;
}
Vector2D Camera::getDrawSize() const {
	return size;
}

void Camera::DeltaStart() {
	start = sclock::now();
}

void Camera::DeltaEnd() {
	end = sclock::now();
	delta = static_cast<float>(static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) / MICROSEC);
}

void Camera::TotalStart() {
	totalStart = sclock::now();

	std::ifstream csvFile("./Data/TotalPlayTimeData.bin", std::ios::binary);

	if (!csvFile) {
		return;
	}

	std::string lineBuff;

	while (getline(csvFile, lineBuff)) {
		total = sclock::duration(stoull(lineBuff));
	}
}

void Camera::ToatlEnd() {
	totalEnd = sclock::now();

	std::ofstream totalFile("./Data/TotalPlayTimeData.bin", std::ios::binary);
	std::ofstream mdFile("./Data/TotalPlayTime.md");

	total += totalEnd - totalStart;

	auto hours = std::chrono::duration_cast<std::chrono::hours>(total).count();
	auto minutes = std::chrono::duration_cast<std::chrono::minutes>(total).count() % 60;
	auto seconds = std::chrono::duration_cast<std::chrono::seconds>(total).count() % 60LL;

	std::chrono::zoned_time zt{ "Asia/Tokyo", std::chrono::floor<std::chrono::seconds>(totalEnd) };
	std::chrono::local_seconds lt = zt.get_local_time();

	totalFile << total.count();
	mdFile << "Total Play : " << hours << "h " << minutes << "m " << seconds << "s" << std::endl
		<< "Last Play : " << std::format("{0:%Y/%m/%d %H:%M:%S}", lt);
}

float Camera::getDelta() {
	return delta;
}

void Camera::FpsDraw() {
	if (fpsDrwFlg) {
		Novice::ScreenPrintf(5, 5, "fps:%.0f", 1.0f / delta);
	}
}