#pragma once

#include "Game/MyMath/MyMath.h"
#include "Game/Vector2D/Vector2D.h"
#include <functional>
#define _USE_MATH_DEFINES
#include <math.h>

		/*　イージングチートシート参照（左上[1]から右下[30]にかけて）　*/

//		使い方：例文
//		if(true){
//			T = Easing::EaseInSine(num);		Easing(クラス名)	EaseInSine(クラス内変数名)
//			num += spd;
//			pos_x = (1 - T) * 始点 + T * 終点;
//			pos_y = (1 - T) * 始点 + T * 終点;
//		}

class Easing {
public:
	Easing();

	Easing(Vector2D start, Vector2D end, float speed, std::function<float(float)> easeType);

	void Set(Vector2D start, Vector2D end, float speed, std::function<float(float)> easeType);

	Vector2D Update();

public:
	float spd;

private:
	float easeT;
	Vector2D startPos;
	Vector2D endPos;
	Vector2D currentPos;
	std::function<float(float)> easeFunc;

public:
	explicit inline operator bool() const {
		return easeT <= 1.0f ? true : false;
	}
	inline bool operator!() const {
		return easeT > 1.0f ? true : false;
	}

public:
	//	1番
	static float EaseInSine(float x);
	//	2
	static float EaseOutSine(float x);
	//	3
	static float EaseInOutSine(float x);
	//	4
	static float EaseInQuad(float x);
	//	5
	static float EaseOutQuad(float x);
	//	6
	static float EaseInOutQuad(float x);
	//	7
	static float EaseInCubic(float x);
	//	8
	static float EaseOutCubic(float x);
	//	9
	static float EaseInOutCubic(float x);
	//	10
	static float EaseInQuart(float x);
	//	11
	static float EaseOutQuart(float x);
	//	12
	static float EaseInOutQuart(float x);
	//	13
	static float EaseInQuint(float x);
	//	14
	static float EaseOutQuint(float x);
	//	15
	static float EaseInOutQuint(float x);
	//	16
	static float EaseInExpo(float x);
	//	17
	static float EaseOutExpo(float x);
	//	18
	static float EaseInOutExpo(float x);
	//	19
	static float EaseInCirc(float x);
	//	20
	static float EaseOutCirc(float x);
	//	21
	static float EaseInOutCirc(float x);
	//	22
	static float EaseInBack(float x);
	//	23
	static float EaseOutBack(float x);
	//	24
	static float EaseInOutBack(float x);
	//	25
	static float EaseInElastic(float x);
	//	26
	static float EaseOutElastic(float x);
	//	27
	static float EaseInOutElastic(float x);
	//	28
	static float EaseInBounce(float x);
	//	29
	static float EaseOutBounce(float x);
	//	30
	static float EaseInOutBounce(float x);
};