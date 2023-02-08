#pragma once

#include <array>

class Vector2D;

class Matrix3x3 {
public:
	using arr3x3 = std::array<std::array<float, 3>, 3>;

public:
	Matrix3x3();
	Matrix3x3(const Matrix3x3& matrix);

	inline ~Matrix3x3() {}

private:
	static const int HEIGHT = 3;
	static const int WIDTH = 3;

public:
	arr3x3 m;

public:
	Matrix3x3 operator*(const Matrix3x3& Matrix1) const;
	const Matrix3x3& operator=(const Matrix3x3& Matrix1);
	const Matrix3x3& operator*=(const Matrix3x3& Matrix1);

public:
	// 回転行列
	void Rotate(float degree);
	friend Matrix3x3 MakeRotate(float degree);

	// 平行移動行列
	void Translate(const Vector2D& vec);
	void Translate(const float& vecX, const float& vecY);
	friend Matrix3x3 MakeTranslate(const Vector2D& vec);

	// スカラー倍行列
	void Scalar(const Vector2D& vec);
	void Scalar(const float& vecX, const float& vecY);
	friend Matrix3x3 MakeScalar(const Vector2D& vec);

	// アフィン変換
	void Affin(const Vector2D& size, float degree, const Vector2D& trancelate);
	friend Matrix3x3 MakeAffin(const Vector2D& size, float degree, const Vector2D& trancelate);

	// 逆行列
	void Inverse();

	// 転置行列
	void Transepose();

	// 正射影行列
	void Orthographic(const Vector2D& leftTop, const Vector2D& rightUnder);
	void Orthographic(const Vector2D& size);
	friend Matrix3x3 MakeOrthographic(const Vector2D& leftTop, const Vector2D& rightUnder);
	friend Matrix3x3 MakeOrthographic(const Vector2D& size);

	/// <summary>
	/// ビューポート行列
	/// </summary>
	/// <param name="pos">カメラの左上の座標</param>
	/// <param name="size">大きさ</param>
	void Viewport(const Vector2D& pos, const Vector2D& size);

	friend Matrix3x3 MakeViewport(const Vector2D& pos, const Vector2D& size);
};