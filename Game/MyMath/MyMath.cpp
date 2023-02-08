#include "Game/MyMath/MyMath.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
#include <random>
#include "Game/Vector2D/Vector2D.h"

std::random_device MyMath::seed;
std::mt19937_64 MyMath::engine(seed());
std::uniform_int_distribution<> MyMath::rndInt;
std::uniform_real_distribution<> MyMath::rndReal;

bool MyMath::CollisionRectangle(Vector2D LeftTop1, Vector2D size1, Vector2D LeftTop2, Vector2D size2) {
	if (LeftTop1.x < LeftTop2.x + size2.x && LeftTop2.x < LeftTop1.x + size1.x) {
		if (LeftTop1.y < LeftTop2.y - size2.y && LeftTop2.y < LeftTop1.y - size1.y) {
			return true;
		}
	}
	return false;
}

bool MyMath::CollisionRectangle(int LeftTopX1, int LeftTopY1, int sizeX1, int sizeY1, int LeftTopX2, int LeftTopY2, int sizeX2, int sizeY2) {
	if (LeftTopX1 < LeftTopX2 + sizeX2 && LeftTopX2 < LeftTopX1 + sizeX1) {
		if (LeftTopY1 < LeftTopY2 + sizeY2 && LeftTopY2 < LeftTopY1 + sizeY1) {
			return true;
		}
	}
	return false;
}

float MyMath::PythagoreanTheorem(const float& x, const float& y) {
	return sqrtf(powf(x, 2.0f) + powf(y, 2.0f));
}

float MyMath::PythagoreanTheorem(const Vector2D& pos1, const Vector2D& pos2) {
	return sqrtf(powf(abs(pos1.x - pos2.x), 2.0f) + powf(abs(pos1.y - pos2.y), 2.0f));
}

float MyMath::Normalize(const float& x, const float& y) {
	return x / MyMath::PythagoreanTheorem(x, y);
}

Vector2D MyMath::Normalize(Vector2D vec) {
	vec.x /= MyMath::PythagoreanTheorem(vec.x, vec.y);
	vec.y /= MyMath::PythagoreanTheorem(vec.y, vec.x);

	return vec;
}

void MyMath::BubbleSort(int* data, int arr, bool order) {
	for (int i = 0; i < arr - 1; i++) {
		for (int j = arr - 1; j > i; j--) {
			if (order == true) {
				if (data[j - 1] > data[j]) {
					MyMath::Swap(data[j], data[j - 1]);
				}
			}
			else if (order == false) {
				if (data[j - 1] < data[j]) {
					MyMath::Swap(data[j], data[j - 1]);
				}
			}
		}
	}
}

float MyMath::Dot(const Vector2D& vec1, const Vector2D& vec2) {
	return (vec1.x * vec2.x) + (vec1.y * vec2.y);
}

bool MyMath::Cross(const Vector2D& vec1, const Vector2D& vec2) {
	return (vec1.x * vec2.y) - (vec1.y * vec2.x) >= 0 ? true : false;
}

float MyMath::ToRad(const float& deg) {
	return deg * static_cast<float>(M_PI) / 180.0f;
}

float MyMath::ToDeg(const float& rad) {
	return rad * 180.0f / static_cast<float>(M_PI);
}

bool MyMath::isAngle(float deg, float maxDeg, float minDeg) {
	return deg < maxDeg && deg > minDeg;
}

float MyMath::GetAngle(Vector2D pos, Vector2D origin) {
	return MyMath::ToDeg(atan2f(pos.y - origin.y, pos.x - origin.x));
}

unsigned int MyMath::GetRGB(unsigned int red, unsigned int green, unsigned int blue, unsigned int alpha) {
	return (red << 24) + (green << 16) + (blue << 8) + alpha;
}

unsigned int MyMath::GetAlpha(unsigned int color) {
	return color & 0xff;
}

int MyMath::Random(int min, int max) {
	if (min > max) {
		Swap(min, max);
	}

	std::uniform_int_distribution<>::param_type param(min, max);

	rndInt.param(param);

	return rndInt(engine);
}

double MyMath::Random(double min, double max) {
	if (min > max) {
		Swap(min, max);
	}

	std::uniform_real_distribution<>::param_type param(min, max);

	rndReal.param(param);

	return rndReal(engine);
}

bool MyMath::Capsule(Vector2D pos, Vector2D start, Vector2D end, float size) {
	Vector2D d = pos - start;
	Vector2D ba = end - start;
	Vector2D e = Normalize(ba);

	float t = Dot(d, e) / sqrtf(ba.x * ba.x + ba.y * ba.y);
	Clamp(t, 1.0f, 0.0f);
	Vector2D f = (1.0f - t) * start + t * end;

	Vector2D fc = pos - f;

	return sqrtf(fc.x * fc.x + fc.y * fc.y) < size + size ? true : false;
}