#pragma once

class Complex {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Complex();

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="re">実部</param>
	/// <param name="im">虚部</param>
	Complex(const float& re, const float& im);

	/// <summary>
	/// コピーコンストラクタ
	/// </summary>
	/// <param name="tmp">複素数</param>
	Complex(const Complex& tmp);

	/// <summary>
	/// Vector2Dで初期化
	/// </summary>
	/// <param name="tmp">Vec2</param>
	Complex(const class Vector2D& tmp);

	/// <summary>
	/// デストラクタ
	/// </summary>
	inline ~Complex(){}

public:
	/// <summary>
	/// 実部
	/// </summary>
	float real;

	/// <summary>
	/// 虚部
	/// </summary>
	float imag;

public:
	/// <summary>
	/// 演算子のオーバーロード
	/// </summary>
	/// <param name="num">足したい複素数</param>
	/// <returns>足した結果</returns>
	Complex operator+(const Complex& num);

	/// <summary>
	/// 演算子のオーバーロード
	/// </summary>
	/// <param name="num">掛けたい複素数</param>
	/// <returns>掛けた結果</returns>
	Complex operator*(const Complex& num);

	/// <summary>
	/// 演算子のオーバーロード
	/// </summary>
	/// <param name="num">代入したい複素数</param>
	/// <returns>*this</returns>
	const Complex& operator=(const Complex& num);

	/// <summary>
	/// 演算子のオーバーロード
	/// </summary>
	/// <param name="num">代入したいvec2</param>
	/// <returns>*this</returns>
	const Complex& operator=(const class Vector2D& num);

	/// <summary>
	/// 演算子のオーバーロード
	/// </summary>
	/// <param name="num">代入足し算したい複素数</param>
	/// <returns>足して代入した結果</returns>
	const Complex& operator+=(const Complex& num);

	/// <summary>
	/// 演算子のオーバーロード
	/// </summary>
	/// <param name="num">代入して掛け算したい複素数</param>
	/// <returns>掛けて代入した結果</returns>
	const Complex& operator*=(const Complex& num);

public:
	const class Vector2D& GetVector2D() const;
};