#pragma once

#include <vector>
#include <Novice.h>
#include <memory>

#include "Game/Object/Object.h"

class World {
public:
	World();
	~World();

private:
	void Input();
	void Reset();
	void Update();
	void Draw();

public:
	const float width;
	const float height;

protected:
	void MainLoop();

private:
	std::shared_ptr<Camera> camera;
	std::weak_ptr<Camera> observer;

	WindowMode winMode;

	std::vector<std::unique_ptr<Object>> object;
};

class Game final : private World {
public:
	Game() : World() {}

public:
	void GameStart() {
		this->MainLoop();
	}
};