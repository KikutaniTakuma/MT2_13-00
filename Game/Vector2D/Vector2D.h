#pragma once

class Matrix3x3;

class Vector2D {
public:
	// コンストラクタ
	Vector2D();
	Vector2D(const float& X, const float& Y);

	// コピーコンストラクタ
	Vector2D(const Vector2D& num);

	Vector2D(const class Complex& tmp);

	// デストラクタ
	inline ~Vector2D(){}

public:
	float x;
	float y;

public:
	// =================================================================================
	//演算子のオーバーロード
	//　使用例
	// Vector2D num; Vector2D num2;
	// num = num2;

	Vector2D operator+(const Vector2D& num) const;
	Vector2D operator-(const Vector2D& num) const;
	Vector2D operator*(const Vector2D& num) const;
	Vector2D operator/(const Vector2D& num) const;
	Vector2D operator+(const float& num) const;
	Vector2D operator-(const float& num) const;
	Vector2D operator*(const float& num) const;
	Vector2D operator/(const float& num) const;
	friend Vector2D operator+(const float& num, const Vector2D& vec);
	friend Vector2D operator-(const float& num, const Vector2D& vec);
	friend Vector2D operator*(const float& num, const Vector2D& vec);
	friend Vector2D operator/(const float& num, const Vector2D& vec);
	const Vector2D& operator=(const Vector2D& num);
	const Vector2D& operator=(const float& num);
	const Vector2D& operator+=(const Vector2D& num);
	const Vector2D& operator-=(const Vector2D& num);
	const Vector2D& operator*=(const Vector2D& num);
	const Vector2D& operator/=(const Vector2D& num);
	const Vector2D& operator+=(const float& num);
	const Vector2D& operator-=(const float& num);
	const Vector2D& operator*=(const float& num);
	const Vector2D& operator/=(const float& num);
	bool operator==(const Vector2D& num) const;
	bool operator!=(const Vector2D& num) const;
	bool operator<(const Vector2D& num) const;
	bool operator>(const Vector2D& num) const;
	bool operator<=(const Vector2D& num) const;
	bool operator>=(const Vector2D& num) const;
	bool operator==(const float& num) const;
	bool operator!=(const float& num) const;
	bool operator<(const float& num) const;
	bool operator>(const float& num) const;
	bool operator<=(const float& num) const;
	bool operator>=(const float& num) const;
	friend bool operator==(const float& num ,const Vector2D& vec);
	friend bool operator!=(const float& num ,const Vector2D& vec);
	friend bool operator<(const float& num, const Vector2D& vec);
	friend bool operator>(const float& num, const Vector2D& vec);
	friend bool operator<=(const float& num, const Vector2D& vec);
	friend bool operator>=(const float& num, const Vector2D& vec);

	Vector2D operator*(const Matrix3x3& matrix) const;
	const Vector2D& operator*=(const Matrix3x3& matrix);

	const Vector2D& operator=(const class Complex& num);

	// =================================================================================

	const class Complex& GetComplex() const;

	void Rotate(float degree);
};