#include "Game/Effect/Effect.h"
#include "Game/MyMath/MyMath.h"
#include "Game/Mouse/Mouse.h"
#include "Game/KeyInput/KeyInput.h"
#include "Game/Texture/Texture.h"

Effect::Effect(std::shared_ptr<Camera> camera, Mode mode, int frequency) :
	Object(camera),
	acceleration(2.0f),
	emitter({ {-3.0f, -3.0f}, { 3.0f, 3.0f} }),
	frequency(frequency),
	count(0),
	particleBuf(Quad()),
	blend(BlendMode::kBlendModeAdd),
	mode(mode),
	flg(true)
{
	pos.Set({640.0f,360.0f}, {0.0f,0.0f});
	frame.Restart();
	worldPos = pos.worldPos;

	if (mode == Mode::Absorption) {
		emitter = { {-100.0f, -100.0f}, { 100.0f, 100.0f} };

		acceleration = 10.0f;

		for (auto& i : particle) {
			i = { Vector2D(), Vector2D(), 2.0f,0.0f,false,0,Easing(Vector2D(), pos.worldPos, 0.01f, Easing::EaseOutCirc)};
		}
	}
	else if (mode == Mode::Fluffy) {
		emitter = { {-3.0f, -3.0f}, { 3.0f, 3.0f} };

		acceleration = 5.0f;

		for (auto& i : particle) {
			i = { Vector2D(), Vector2D(), 10.0f,0.0f,false,255,Easing()};
		}
	}
	else if (mode == Mode::Powerups) {
		emitter = { {-640.0f, -5.0f}, { 640.0f, 5.0f} };

		acceleration = 2.0f;

		pos.worldPos.y = -5.0f;

		worldPos = pos.worldPos;

		blend = kBlendModeNormal;

		for (auto& i : particle) {
			i = { Vector2D(), Vector2D(), 55.0f,0.0f,false,255,Easing() };
		}
	}
	else if (mode == Mode::Bullet) {
		emitter = { {-3.0f, -3.0f}, { 3.0f, 3.0f} };

		acceleration = 20.0f;

		for (auto& i : particle) {
			i = { Vector2D(), Vector2D(), 2.0f,0.0f,false,255,Easing() };
		}
	}
}

void Effect::Update() {
	pos.worldPos = worldPos;
	if (mode == Mode::Absorption) {
		this->Absorption();
	}
	else if (mode == Mode::Fluffy) {
		this->Fluffy();
	}
	else if (mode == Mode::Powerups) {
		this->Powerups();
	}
	else if (mode == Mode::Bullet) {
		this->Bullet();
	}
}

void Effect::Draw() {
	if (mode == Mode::Absorption) {
		Novice::SetBlendMode(blend);

		for (auto& i : particle) {
			if (i.flg) {
				particleBuf.Set(i.pos, { i.size,i.size });
				camera->DrawQuad(particleBuf, whiteBox, 0, 0xffff0000 + i.alpha);
			}
		}

		Novice::SetBlendMode(kBlendModeNormal);
	}
	else if (mode == Mode::Fluffy) {
		Novice::SetBlendMode(blend);

		for (auto& i : particle) {
			if (i.flg) {
				particleBuf.Set(i.pos, { i.size,i.size });
				camera->DrawQuad(particleBuf, whiteBox, 0, 0xffffff00 + i.alpha);
			}
		}

		Novice::SetBlendMode(kBlendModeNormal);
	}
	else if (mode == Mode::Powerups) {
		Novice::SetBlendMode(blend);

		for (auto& i : particle) {
			if (i.flg) {
				particleBuf.Set(i.pos, { i.size,i.size });
				camera->DrawQuad(particleBuf, whiteBox, 0, MyMath::GetRGB(0x1e,0x90,0xff,i.alpha));
			}
		}

		Novice::SetBlendMode(kBlendModeNormal);
	}
	else if (mode == Mode::Bullet) {
		Novice::SetBlendMode(blend);

		for (auto& i : particle) {
			if (i.flg) {
				particleBuf.Set(i.pos, { i.size,i.size });
				camera->DrawQuad(particleBuf, whiteBox, 0, 0xffffff00 + i.alpha);
			}
		}

		Novice::SetBlendMode(kBlendModeNormal);
	}
}

void Effect::Reset() {
	count = 0;
	particleBuf = Quad();
	blend = BlendMode::kBlendModeAdd;
	flg = true;

	pos.Set({ 640.0f,360.0f }, { 0.0f,0.0f });
	frame.Restart();
	worldPos = pos.worldPos;

	if (mode == Mode::Absorption) {
		emitter = { {-100.0f, -100.0f}, { 100.0f, 100.0f} };

		acceleration = 10.0f;

		for (auto& i : particle) {
			i = { Vector2D(), Vector2D(), 2.0f,0.0f,false,0,Easing(Vector2D(), pos.worldPos, 0.01f, Easing::EaseOutCirc) };
		}
	}
	else if (mode == Mode::Fluffy) {
		emitter = { {-3.0f, -3.0f}, { 3.0f, 3.0f} };

		acceleration = 5.0f;

		for (auto& i : particle) {
			i = { Vector2D(), Vector2D(), 10.0f,0.0f,false,255,Easing() };
		}
	}
	else if (mode == Mode::Powerups) {
		emitter = { {-640.0f, -5.0f}, { 640.0f, 5.0f} };

		acceleration = 2.0f;

		pos.worldPos.y = -5.0f;

		worldPos = pos.worldPos;

		blend = kBlendModeNormal;

		for (auto& i : particle) {
			i = { Vector2D(), Vector2D(), 55.0f,0.0f,false,255,Easing() };
		}
	}
	else if (mode == Mode::Bullet) {
		emitter = { {-3.0f, -3.0f}, { 3.0f, 3.0f} };

		acceleration = 20.0f;

		for (auto& i : particle) {
			i = { Vector2D(), Vector2D(), 2.0f,0.0f,false,255,Easing() };
		}
	}
}

void Effect::Absorption() {
	if (flg) {
		for (int i = count; i < count + frequency && count < particle.size(); i++) {
			if (!particle[i].flg) {
				particle[i].flg = true;
				particle[i].size = static_cast<float>(MyMath::Random(20, 100));
				particle[i].pos = pos.worldPos;
				float len = static_cast<float>((MyMath::Random(static_cast<int>(emitter.rightTop.x), static_cast<int>(emitter.rightTop.x) * 2)));
				Vector2D rotate = { len,len };
				rotate.Rotate(static_cast<float>(MyMath::Random(0, 359)));
				particle[i].pos += rotate;
				particle[i].moveVec = { -particle[i].spd, -particle[i].spd };
				particle[i].moveVec.Rotate(static_cast<float>(MyMath::Random(0, 359)));

				particle[i].ease.Set(particle[i].pos, pos.worldPos, 0.01f, Easing::EaseOutCirc);
			}
		}
		count += frequency;

		MyMath::Clamp(count, 0, static_cast<int>(particle.size()));
		if (count == particle.size()) {
			count = 0;
			flg = false;
		}

	}

	for (auto& i : particle) {
		if (i.flg) {
			i.alpha += static_cast<int>(acceleration);
			i.pos = i.ease.Update();
			if (i.alpha >= 255) {
				i.alpha = 255;
			}

			if (!i.ease) {
				i = { Vector2D(), Vector2D(), 2.0f,0.0f,false,0,Easing(Vector2D(), pos.worldPos, 0.01f, Easing::EaseOutCirc) };
			}
		}
	}
}

void Effect::Fluffy() {
	for (int i = count; i < count + frequency && count < 100; i++) {
		if (!particle[i].flg) {
			particle[i].flg = true;
			particle[i].size = static_cast<float>(MyMath::Random(80, 100));
			particle[i].pos = pos.worldPos;
			particle[i].pos.x += static_cast<float>(MyMath::Random(static_cast<int>(emitter.leftBottom.x), static_cast<int>(emitter.rightTop.x)));
			particle[i].pos.y += static_cast<float>(MyMath::Random(static_cast<int>(emitter.leftBottom.y), static_cast<int>(emitter.rightTop.y)));
			particle[i].moveVec = { particle[i].spd, particle[i].spd };
			particle[i].moveVec.Rotate(static_cast<float>(MyMath::Random(0, 359)));
		}
	}
	count += frequency;

	MyMath::Clamp(count, 0, 100);

	int num = 0;
	for (auto& i : particle) {
		if (i.flg) {
			i.alpha -= static_cast<int>(acceleration);
			i.pos += i.moveVec;
			if (i.alpha < 0) {
				i = { Vector2D(), Vector2D(), 10.0f,0.0f,false,255,Easing() };
				if (num == 99) {
					flg = false;
				}
			}
		}
		num++;
	}
}

void Effect::Powerups() {
	if (flg) {
		for (int i = count; i < count + frequency && count < particle.size(); i++) {
			if (!particle[i].flg) {
				particle[i].flg = true;
				particle[i].size = static_cast<float>(MyMath::Random(40, 60));
				particle[i].pos = pos.worldPos;
				particle[i].pos.x += static_cast<float>(MyMath::Random(static_cast<int>(emitter.leftBottom.x), static_cast<int>(emitter.rightTop.x)));
				particle[i].pos.y += static_cast<float>(MyMath::Random(static_cast<int>(emitter.leftBottom.y), static_cast<int>(emitter.rightTop.y)));
				particle[i].moveVec = { 0.0f, particle[i].spd };
			}
		}
		count += frequency;

		MyMath::Clamp(count, 0, static_cast<int>(particle.size()));
		if (count == particle.size()) {
			count = 0;
			flg = false;
		}
	}

	for (auto& i : particle) {
		if (i.flg) {
			i.moveVec.y -= static_cast<int>(acceleration);
			i.pos += i.moveVec;
			if (i.moveVec.y < 0.0f) {
				i = { Vector2D(), Vector2D(), 55.0f,0.0f,false,255,Easing() };
			}
		}
	}
}


void Effect::Bullet() {
	if (flg) {
		for (int i = count; i < count + frequency && count < particle.size(); i++) {
			if (!particle[i].flg) {
				particle[i].flg = true;
				particle[i].size = static_cast<float>(MyMath::Random(80, 100));
				particle[i].pos = pos.worldPos;
				particle[i].pos.x += static_cast<float>(MyMath::Random(static_cast<int>(emitter.leftBottom.x), static_cast<int>(emitter.rightTop.x)));
				particle[i].pos.y += static_cast<float>(MyMath::Random(static_cast<int>(emitter.leftBottom.y), static_cast<int>(emitter.rightTop.y)));
				particle[i].moveVec = { particle[i].spd, particle[i].spd };
				particle[i].moveVec.Rotate(static_cast<float>(MyMath::Random(0, 359)));
			}
		}
		count += frequency;

		MyMath::Clamp(count, 0, static_cast<int>(particle.size()));
		if (count == particle.size()) {
			count = 0;
		}
	}

	for (auto& i : particle) {
		if (i.flg) {
			i.alpha -= static_cast<int>(acceleration);
			i.pos += i.moveVec;
			if (i.alpha < 0) {
				i = { Vector2D(), Vector2D(), 2.0f,0.0f,false,255,Easing() };
			}
		}
	}
}