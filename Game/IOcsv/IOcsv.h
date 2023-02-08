#pragma once

#include <vector>
#include <string>

class IOcsv {
private:
	inline IOcsv(){}
	inline ~IOcsv(){}

public:
	/*
	csvファイルを開き引数に数字と文字を区別して代入する

	第１引数：ファイルの名前
	第２引数：可変長配列(int 型)
	第３引数：可変長配列(string 型)

	戻り値
	0：成功
	1：失敗
	*/
	static int Input(const char* fileName, std::vector<int>& data, std::vector<std::string>& coment);

	/*
	csvファイルを開き引数に数字と文字を区別して代入する
	 
	第１引数：ファイルの名前
	第２引数：可変長配列(float 型)
	第３引数：可変長配列(string 型)

	戻り値
	0：成功
	1：失敗
	*/
	static int Input(const char* fileName, std::vector<float>& data, std::vector<std::string>& coment);

	/*
	csvファイルを開き引数に数字を代入する

	第１引数：ファイルの名前
	第２引数：可変長配列(int 型)

	戻り値
	0：成功
	1：失敗
	*/
	static int Input(const char* fileName, std::vector<int>& data);

	/*
	csvファイルを開き引数に数字を代入する

	第１引数：ファイルの名前
	第２引数：可変長配列(float 型)

	戻り値
	0：成功
	1：失敗
	*/
	static int Input(const char* fileName, std::vector<float>& data);

	/*
	csvファイルを開き引数に文字列を代入する

	第１引数：ファイルの名前
	第２引数：可変長配列(string 型)

	戻り値
	0：成功
	1：失敗
	*/
	static int Input(const char* fileName, std::vector<std::string>& coment);

	/*
	csvファイルを開き配列に代入

	第１引数：ファイルの名前
	第２引数：配列のポインタ(int 型)
	第３引数：要素数

	戻り値
	0：成功
	1：失敗
	*/
	static int Input(const char* fileName, int* data, const int& index);

	/*
	csvファイルを開き配列に代入

	第１引数：ファイルの名前
	第２引数：配列のポインタ(float 型)
	第３引数：要素数

	戻り値
	0：成功
	1：失敗
	*/
	static int Input(const char* fileName, float* data, const int& index);

	/*
	※これを使うのはお勧めしない(データのバッファーを用意するのが面倒なのでおとなしくstring型のvector使ってください)※
	バッファーの用意例
	char hoge[4][10] = {NULL};
	char* p[] = {hoge[0],hoge[1],hoge[2],hoge[3]};
	↑めんどくね？それとこのバッファーの入れることのできる文字列の最大は10文字でこれを超えるものはバグる

	csvファイルを開き配列に代入

	第１引数：ファイルの名前
	第２引数：配列のポインタ(char* 型)
	第３引数：要素数

	戻り値
	0：成功
	1：失敗
	*/
	static int Input(const char* fileName, char** data, const int& index);


	//==================================================================================================================================

	/*
	csvファイルに文字と数字を１つづつ入れたら改行を繰り返して保存(ファイルがなかった場合生成する)

	第１引数：ファイルの名前
	第２引数：可変長配列(int 型)
	第３引数：可変長配列(string 型)

	戻り値
	0：成功
	1：失敗
	*/
	static int Output(const char* fileName, const std::vector<int>& data, const std::vector<std::string>& coment);

	/*
	csvファイルに文字と数字を１つづつ入れたら改行を繰り返して保存(ファイルがなかった場合生成する)

	第１引数：ファイルの名前
	第２引数：可変長配列(float 型)
	第３引数：可変長配列(string 型)

	戻り値
	0：成功
	1：失敗
	*/
	static int Output(const char* fileName, const std::vector<float> &data, const std::vector<std::string> &coment);

	/*
	csvファイルに数字を１つ入れたら改行を繰り返して保存(ファイルがなかった場合生成する)

	第１引数：ファイルの名前
	第２引数：可変長配列(int 型)

	戻り値
	0：成功
	1：失敗
	*/
	static int Output(const char* fileName, const std::vector<int>& data);

	/*
	csvファイルに数字を１つ入れたら改行を繰り返して保存(ファイルがなかった場合生成する)

	第１引数：ファイルの名前
	第２引数：可変長配列(float 型)

	戻り値
	0：成功
	1：失敗
	*/
	static int Output(const char* fileName, const std::vector<float>& data);

	/*
	csvファイルに文字列を１つ入れたら改行を繰り返して保存(ファイルがなかった場合生成する)

	第１引数：ファイルの名前
	第２引数：可変長配列(string 型)

	戻り値
	0：成功
	1：失敗
	*/
	static int Output(const char* fileName, const std::vector<std::string>& coment);

	/*
	csvファイルに文字と数字を１つづつ入れたら改行を繰り返して保存(ファイルがなかった場合生成する)

	第１引数：ファイルの名前
	第２引数：配列のポインタ(int 型)
	第３引数：数値配列の要素数
	第４引数：配列のポインタ(const char* 型)
	第５引数：文字列配列の要素数

	戻り値
	0：成功
	1：失敗
	*/
	static int Output(const char* fileName, int* data, const int& dataIndex, const char** coment, const int& comeIndex);

	/*
	csvファイルに文字と数字を１つづつ入れたら改行を繰り返して保存(ファイルがなかった場合生成する)

	第１引数：ファイルの名前
	第２引数：配列のポインタ(float 型)
	第３引数：数値配列の要素数
	第４引数：配列のポインタ(const char* 型)
	第５引数：文字列配列の要素数

	戻り値
	0：成功
	1：失敗
	*/
	static int Output(const char* fileName, float* data, const int& dataIndex, const char** coment, const int& comeIndex);

	/*
	csvファイルに数字を１つ入れたら改行を繰り返して保存(ファイルがなかった場合生成する)

	第１引数：ファイルの名前
	第２引数：配列のポインタ(int 型)
	第３引数：要素数

	戻り値
	0：成功
	1：失敗
	*/
	static int Output(const char* fileName, int* data, const int& index);

	/*
	csvファイルに数字を１つ入れたら改行を繰り返して保存(ファイルがなかった場合生成する)

	第１引数：ファイルの名前
	第２引数：配列のポインタ(float 型)
	第３引数：要素数

	戻り値
	0：成功
	1：失敗
	*/
	static int Output(const char* fileName, float* data, const int& index);

	/*
	csvファイルに文字を１つ入れたら改行を繰り返して保存(ファイルがなかった場合生成する)

	第１引数：ファイルの名前
	第２引数：配列のポインタ(const char* 型)
	第３引数：要素数

	戻り値
	0：成功
	1：失敗
	*/
	static int Output(const char* fileName, const char** data, const int& index);
};