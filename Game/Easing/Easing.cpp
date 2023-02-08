#include "Game/Easing/Easing.h"
#include "Game/Camera/Camera.h"

Easing::Easing() :
	spd(0.0f),
	easeT(0.0f)
{
}

Easing::Easing(Vector2D start, Vector2D end, float speed, std::function<float(float)> easeType) :
	startPos(start),
	endPos(end),
	spd(speed),
	easeFunc(easeType),
	easeT(0.0f),
	currentPos(startPos)
{
	if (spd >= 1.0f) {
		spd = 1.0f;
	}
}

void Easing::Set(Vector2D start, Vector2D end, float speed, std::function<float(float)> easeType) {
	startPos=start;
	endPos = end;
	spd = speed;
	easeFunc = easeType;
	easeT = 0.0f;
	currentPos = startPos;
	if (spd >= 1.0f) {
		spd = 1.0f;
	}
}

Vector2D Easing::Update() {
	float T = easeFunc(easeT);
	if (!(easeT > 1.0f)) {
		currentPos = (1.0f - T) * startPos + T * endPos;
	}
	easeT += spd * Camera::getDelta();

	return currentPos;
}

float Easing::EaseInSine(float x) {
	return 1.0f - cosf((x * (float)M_PI) / 2.0f);
}
float Easing::EaseOutSine(float x) {
	return sinf((x * (float)M_PI) / 2.0f);
}
float Easing::EaseInOutSine(float x) {
	return -1.0f * (cosf((float)M_PI * x) - 1.0f) / 2.0f;
}

float Easing::EaseInQuad(float x) {
	return powf(x, 2.0f);
}
float Easing::EaseOutQuad(float x) {
	return 1.0f - (1.0f - x) * (1.0f - x);
}
float Easing::EaseInOutQuad(float x) {

	if (x < 0.5f)
	{
		return 2.0f * powf(x, 2.0f);
	}
	else
	{
		return 1.0f - powf(-2.0f * x + 2.0f, 2.0f) / 2.0f;
	}
}

float Easing::EaseInCubic(float x) {
	return powf(x, 3.0f);
}
float Easing::EaseOutCubic(float x) {
	return 1.0f - powf(1.0f - x, 3.0f);
}
float Easing::EaseInOutCubic(float x) {
	if (x < 0.5f)
	{
		return 4.0f * powf(x, 4.0f);
	}
	else
	{
		return 1.0f - powf(-2.0f * x + 2.0f, 3.0f) / 2.0f;
	}
}

float Easing::EaseInQuart(float x) {
	return powf(x, 4.0f);
}
float Easing::EaseOutQuart(float x) {
	return 1.0f - powf(1.0f - x, 4.0f);
}
float Easing::EaseInOutQuart(float x) {
	if (x < 0.5f)
	{
		return 8.0f * powf(x, 4.0f);
	}
	else
	{
		return 1.0f - powf(-2.0f * x + 2.0f, 4.0f) / 2.0f;
	}
}

float Easing::EaseInQuint(float x) {
	return powf(x, 5.0f);
}
float Easing::EaseOutQuint(float x) {
	return 1.0f - powf(1.0f - x, 5.0f);
}
float Easing::EaseInOutQuint(float x) {
	if (x < 0.5f)
	{
		return 16.0f * powf(x, 5.0f);
	}
	else
	{
		return 1.0f - powf(-2.0f * x + 2.0f, 5.0f) / 2.0f;
	}
}

float Easing::EaseInExpo(float x) {
	if (x == 0.0f)
	{
		return 0.0f;
	}
	else
	{
		return powf(2.0f, 10.0f * x - 10.0f);
	}
}
float Easing::EaseOutExpo(float x) {
	if (x == 1.0f)
	{
		return 1.0f;
	}
	else
	{
		return (1.0f - powf(2.0f, -10.0f * x));
	}
}
float Easing::EaseInOutExpo(float x) {
	if (x == 0.0f)
	{
		return 0.0f;
	}
	else if (x == 1.0f)
	{
		return 1.0f;
	}
	else if (x < 0.5f)
	{
		return powf(2.0f, 20.0f * x - 10.0f) / 2.0f;
	}
	else
	{
		return (2.0f - powf(2.0f, -20.0f * x + 10.0f)) / 2.0f;
	}
}

float Easing::EaseInCirc(float x) {
	return 1.0f - sqrtf(1.0f - powf(x, 2.0f));
}
float Easing::EaseOutCirc(float x) {
	return sqrtf(1.0f - powf(x - 1.0f, 2.0f));
}
float Easing::EaseInOutCirc(float x) {
	if (x < 0.5f)
	{
		return (1.0f - sqrtf(1.0f - powf(2.0f * x, 2.0f))) / 2.0f;
	}
	else
	{
		return (sqrtf(1.0f - powf(-2.0f * x + 2.0f, 2.0f)) + 1.0f) / 2.0f;
	}
}

float Easing::EaseInBack(float x) {
	const float c1 = 1.70158f;
	const float c3 = c1 + 1.0f;

	return (c3 * powf(x, 3.0f)) - (c1 * powf(x, 2.0f));
}
float Easing::EaseOutBack(float x) {
	const float c1 = 1.70158f;
	const float c3 = c1 + 1.0f;

	return 1 + c3 * powf(x - 1.0f, 3.0f) + c1 * powf(x - 1.0f, 2.0f);
}
float Easing::EaseInOutBack(float x) {
	const float c1 = 1.70158f;
	const float c2 = c1 * 1.525f;

	if (x < 0.5f)
	{
		return (powf(2.0f * x, 2.0f) * ((c2 + 1.0f) * 2.0f * x - c2)) / 2.0f;
	}
	else
	{
		return (powf(2.0f * x - 2.0f, 2.0f) * ((c2 + 1.0f) * (x * 2.0f - 2.0f) + c2) + 2.0f) / 2.0f;
	}
}

float Easing::EaseInElastic(float x) {
	const float c4 = (2.0f * (float)M_PI) / 3.0f;

	if (x == 0.0f)
	{
		return 0.0f;
	}
	else if (x == 1.0f)
	{
		return 1.0f;
	}
	else
	{
		return -powf(2.0f, 10.0f * x - 10.0f) * sinf((x * 10.0f - 10.75f) * c4);
	}
}
float Easing::EaseOutElastic(float x) {
	const float c4 = (2.0f * (float)M_PI) / 3.0f;

	if (x == 0.0f) {
		return 0.0f;
	}
	else if (x >= 1.0f) {
		return 1.0f;
	}
	else {
		return powf(2.0f, -10.0f * x) * sinf((x * 10.0f - 0.75f) * c4) + 1.0f;
	}
}
float Easing::EaseInOutElastic(float x) {
	const float c5 = (2.0f * (float)M_PI) / 4.5f;

	if (x == 0.0f)
	{
		return 0.0f;
	}
	else if (x == 1.0f)
	{
		return 1.0f;
	}
	else if (x < 0.5f)
	{
		return -1.0f * (powf(2.0f, 20.0f * x - 10.0f) * sinf((20.0f * x - 11.125f) * c5)) / 2.0f;
	}
	else
	{
		return (powf(2.0f, -20.0f * x + 10.0f) * sinf((20.0f * x - 11.125f) * c5)) / 2.0f + 1.0f;
	}
}

float Easing::EaseInBounce(float x) {
	return 1.0f - EaseOutBounce(1.0f - x);
}
float Easing::EaseOutBounce(float x) {
	const float n1 = 7.5625f;
	const float d1 = 2.75f;

	if (x < 1.0f / d1) {
		return n1 * powf(x, 2.0f);
	}
	else if (x < 2.0f / d1) {
		return n1 * (x -= 1.5f / d1) * x + 0.75f;
	}
	else if (x < 2.5f / d1) {
		return n1 * (x -= 2.25f / d1) * x + 0.9375f;
	}
	else {
		return n1 * (x -= 2.625f / d1) * x + 0.984375f;
	}
}
float Easing::EaseInOutBounce(float x) {
	if (x < 0.5f)
	{
		return (1.0f - EaseOutBounce(1.0f - 2.0f * x)) / 2.0f;
	}
	else
	{
		return (1.0f + EaseOutBounce(2.0f * x - 1.0f)) / 2.0f;
	}
}