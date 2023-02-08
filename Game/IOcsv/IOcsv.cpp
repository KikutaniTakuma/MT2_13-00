#include "IOcsv.h"

#include <fstream>
#include <sstream>
#include <algorithm>

int IOcsv::Input(const char* fileName, std::vector<int>& data, std::vector<std::string>& coment)
{
	// ファイルバッファー(コンストラクタで開く)
	std::ifstream fileBuff(fileName);

	// もしファイルが開かなかったり、なかったら1を返す
	if (!fileBuff) { return 1; }

	else
	{
		// バッファー
		std::string lineBuff;
		std::string buff;

		// イテレータ
		auto id = data.begin();
		auto ic = coment.begin();

		// 引数の要素数バッファー
		auto dataSize = data.size();
		auto dataNum = 0;
		auto comeSize = coment.size();
		auto comeNum = 0;

		// 一行取得
		while (getline(fileBuff, lineBuff))
		{
			// 変換
			std::istringstream line(lineBuff);

			// 区切り文字以前のstringを取得
			while (getline(line, buff, ','))
			{
				// buffに格納されている文字がすべて数字なら数値(int型)に変えて代入
				if (std::all_of(buff.cbegin(), buff.cend(), isdigit))
				{
					if (dataNum >= dataSize) {
						data.push_back(stoi(buff));
					}
					else {
						*id = stoi(buff);// stringをintへ変換し保存
						id++;
						dataNum++;
					}
				}
				// buffに格納されている文字に一つでも数字以外が入っていたらbuffをそのまま代入
				else if (std::any_of(buff.cbegin(), buff.cend(), isalpha))
				{
					if (comeNum >= comeSize) {
						coment.push_back(buff);
					}
					else {
						*ic = buff;
						ic++;
						comeNum++;
					}
				}
			}
		}

		return 0;
	}
}

int IOcsv::Input(const char* fileName, std::vector<float>& data, std::vector<std::string>& coment) 
{
	// ファイルバッファー(コンストラクタで開く)
	std::ifstream fileBuff(fileName);

	// もしファイルが開かなかったり、なかったら1を返す
	if (!fileBuff) { return 1; }

	else
	{
		// バッファ
		std::string lineBuff;
		std::string buff;

		// イテレータ
		auto id = data.begin();
		auto ic = coment.begin();

		// 引数の要素数バッファー
		auto dataSize = data.size();
		auto dataNum = 0;
		auto comeSize = coment.size();
		auto comeNum = 0;

		// 一行取得
		while (getline(fileBuff, lineBuff))
		{
			// 変換
			std::istringstream line(lineBuff);

			// 区切り文字以前のstringを取得
			while (getline(line, buff, ','))
			{
				// buffに格納されている文字に数字が一文字でも含まれていたら数値(float型)に変えて代入
				if (std::any_of(buff.cbegin(), buff.cend(), isdigit))
				{
					if (dataNum >= dataSize) {
						data.push_back(stof(buff));
					}
					else {
						*id = stof(buff);// stringをfloatへ変換し保存
						id++;
						dataNum++;
					}
				}
				// buffに格納されている文字がすべて文字だったらbuffをそのまま代入
				else if (std::all_of(buff.cbegin(), buff.cend(), isalpha))
				{
					if (comeNum >= comeSize) {
						coment.push_back(buff);
					}
					else {
						*ic = buff;
						ic++;
						comeNum++;
					}
				}
			}
		}

		return 0;
	}
}

int IOcsv::Input(const char* fileName, std::vector<int>& data)
{
	// ファイルバッファー(コンストラクタで開く)
	std::ifstream fileBuff(fileName);

	// もしファイルが開かなかったり、なかったら1を返す
	if (!fileBuff) { return 1; }

	else
	{
		// バッファ
		std::string lineBuff;
		std::string buff;

		// イテレータ
		auto id = data.begin();

		// 引数の要素数バッファー
		auto size = data.size();
		auto num = 0;

		// 一行取得
		while (getline(fileBuff, lineBuff))
		{
			// 変換
			std::istringstream line(lineBuff);

			// 区切り文字以前のstringを取得
			while (getline(line, buff, ','))
			{
				// buffに格納されている文字がすべて数字なら数値(int型)に変えて代入
				if (std::all_of(buff.cbegin(), buff.cend(), isdigit) && id != data.end())
				{
					if (num >= size) {
						data.push_back(stoi(buff));
					}
					else {
						*id = stoi(buff);// stringをintへ変換し保存
						id++;
						num++;
					}
				}
			}
		}

		return 0;
	}
}

int IOcsv::Input(const char* fileName, std::vector<float>& data) 
{
	// ファイルバッファー(コンストラクタで開く)
	std::ifstream fileBuff(fileName);

	// もしファイルが開かなかったり、なかったら1を返す
	if (!fileBuff) { return 1; }

	else
	{
		// バッファ
		std::string lineBuff;
		std::string buff;

		// イテレータ
		auto id = data.begin();

		// 引数の要素数バッファー
		auto size = data.size();
		auto num = 0;

		// 一行取得
		while (getline(fileBuff, lineBuff))
		{
			// 変換
			std::istringstream line(lineBuff);

			// 区切り文字以前のstringを取得
			while (getline(line, buff, ','))
			{
				// buffに格納されている文字がすべて数字なら数値(float型)に変えて代入
				if (std::any_of(buff.cbegin(), buff.cend(), isdigit))
				{
					if (num >= size) {
						data.push_back(stof(buff));
					}
					else {
						*id = stof(buff);// stringをfloatへ変換し保存
						id++;
						num++;
					}
				}
			}
		}

		return 0;
	}
}

int IOcsv::Input(const char* fileName, std::vector<std::string>& coment) 
{
	// ファイルバッファー(コンストラクタで開く)
	std::ifstream fileBuff(fileName);

	// もしファイルが開かなかったり、なかったら1を返す
	if (!fileBuff) { return 1; }

	else
	{
		// バッファ
		std::string lineBuff;
		std::string buff;

		// イテレータ
		auto ic = coment.begin();

		// 引数の要素数バッファー
		auto size = coment.size();
		auto num = 0;

		// 一行取得
		while (getline(fileBuff, lineBuff))
		{
			// 変換
			std::istringstream line(lineBuff);

			// 区切り文字以前のstringを取得
			while (getline(line, buff, ','))
			{
				// buffに格納されている文字がすべて文字なら代入
				if (std::all_of(buff.cbegin(), buff.cend(), isalnum))
				{
					if (num >= size) {
						coment.push_back(buff);
					}
					else {
						*ic = buff;
						ic++;
						num++;
					}
				}
			}
		}

		return 0;
	}
}

int IOcsv::Input(const char* fileName, int* data, const int& index) 
{
	// ファイルバッファー(コンストラクタで開く)
	std::ifstream fileBuff(fileName);

	// 要素数バッファー
	int num = 0;

	// もしファイルが開かなかったり、なかったら1を返す
	if (!fileBuff) { return 1; }

	else
	{
		// バッファ
		std::string lineBuff;
		std::string buff;

		// 一行取得
		while (getline(fileBuff, lineBuff))
		{
			// 変換
			std::istringstream line(lineBuff);

			// 区切り文字以前のstringを取得
			while (getline(line, buff, ','))
			{
				// buffに格納されている文字がすべて数字なら数値(int型)に変えて代入
				if (std::all_of(buff.cbegin(), buff.cend(), isdigit))
				{
					// データバッファーが要素数を超えていたら終了
					if (num >= index) {
						return 0;
					}

					data[num] = stoi(buff);// stringをintへ変換し保存
					num++;
				}
			}
		}

		return 0;
	}
}

int IOcsv::Input(const char* fileName, float* data, const int& index) {
	// ファイルバッファー(コンストラクタで開く)
	std::ifstream fileBuff(fileName);

	// 要素数バッファー
	int num = 0;

	// もしファイルが開かなかったり、なかったら1を返す
	if (!fileBuff) { return 1; }

	else
	{
		// バッファ
		std::string lineBuff;
		std::string buff;

		// 一行取得
		while (getline(fileBuff, lineBuff))
		{
			// 変換
			std::istringstream line(lineBuff);

			// 区切り文字以前のstringを取得
			while (getline(line, buff, ','))
			{
				// buffに格納されている文字がすべて数字なら数値(float型)に変えて代入
				if (std::any_of(buff.cbegin(), buff.cend(), isdigit))
				{
					// データバッファーが要素数を超えていたら終了
					if (num >= index) {
						return 0;
					}

					data[num] = stof(buff);// stringをfloatへ変換し保存
					num++;
				}
			}
		}

		return 0;
	}
}

int IOcsv::Input(const char* fileName, char** data, const int& index) {
	// ファイルバッファー(コンストラクタで開く)
	std::ifstream fileBuff(fileName);

	// 要素数バッファー
	int num = 0;

	// もしファイルが開かなかったり、なかったら1を返す
	if (!fileBuff) { return 1; }

	else
	{
		// バッファ
		std::string lineBuff;
		std::string buff;

		// 一行取得
		while (getline(fileBuff, lineBuff))
		{
			// 変換
			std::istringstream line(lineBuff);

			// 区切り文字以前のstringを取得
			while (getline(line, buff, ','))
			{
				// データバッファーが要素数を超えていたら終了
				if (num >= index) {
					return 0;
				}

				int index = 0;
				for (char& i : buff) {
					data[num][index] = i; // 一文字づつ代入
					index++;
				}
				num++;
			}
		}

		return 0;
	}
}

///====================================================================================================================================
///====================================================================================================================================
///====================================================================================================================================

int IOcsv::Output(const char* fileName, const std::vector<int>& data, const std::vector<std::string>& coment)
{
	// ファイルバッファー(コンストラクタで開く)
	std::ofstream fileBuff(fileName);

	// もしファイルが開かなかったり、なかったら1を返す
	if (!fileBuff) { return 1; }

	// 入力処理
	else
	{
		// for文のバッファー
		int num = 0;
		if (data.size() > coment.size()) { num = static_cast<int>(data.size()); }
		else if (data.size() <= coment.size()) { num = static_cast<int>(coment.size()); }

		auto id = data.begin();
		auto ic = coment.begin();
		for (int i = 0; i < num; i++)
		{
			if (i >= static_cast<int>(data.size())) {
				fileBuff << *ic << "," << std::endl;
			}
			else if (i >= static_cast<int>(coment.size())) {
				fileBuff << *id << "," << std::endl;
			}
			else {
				fileBuff << *ic << "," << *id << "," << std::endl;
			}

			if (id != data.end()) { ++id; }
			if (ic != coment.end()) { ++ic; }
		}
		return 0;
	}
}

int IOcsv::Output(const char* fileName, const std::vector<float>& data, const std::vector<std::string>& coment) 
{
	// ファイルバッファー(コンストラクタで開く)
	std::ofstream fileBuff(fileName);

	// もしファイルが開かなかったり、なかったら1を返す
	if (!fileBuff) { return 1; }

	// 入力処理
	else 
	{
		// for文のバッファー
		int num = 0;
		if (data.size() > coment.size()) { num = static_cast<int>(data.size()); }
		else if(data.size() <= coment.size()) { num = static_cast<int>(coment.size()); }

		auto id = data.begin();
		auto ic = coment.begin();
		for (int i = 0; i < num; i++)
		{
			if (i >= static_cast<int>(data.size())) {
				fileBuff << *ic << "," << std::endl; 
			}
			else if (i >= static_cast<int>(coment.size())) {
				fileBuff << *id << "," << std::endl; 
			}
			else { 
				fileBuff << *ic << "," << *id << "," << std::endl; 
			}

			if (id != data.end()) { ++id; }
			if (ic != coment.end()) { ++ic; }
		}

		return 0;
	}
}

int IOcsv::Output(const char* fileName, const std::vector<int>& data)
{
	// ファイルバッファー(コンストラクタで開く)
	std::ofstream fileBuff(fileName);

	// もしファイルが開かなかったり、なかったら1を返す
	if (!fileBuff) { return 1; }

	else
	{
		// 入力処理
		for (auto& id : data)
		{
			fileBuff << id << "," << std::endl;
		}

		return 0;
	}
}

int IOcsv::Output(const char* fileName, const std::vector<float>& data) {
	// ファイルバッファー(コンストラクタで開く)
	std::ofstream fileBuff(fileName);

	// もしファイルが開かなかったり、なかったら1を返す
	if (!fileBuff) { return 1; }

	// 入力処理
	else 
	{
		for (auto& id : data) 
		{
			fileBuff << id << "," << std::endl;
		}

		return 0;
	}
}

int IOcsv::Output(const char* fileName, const std::vector<std::string>& coment) {
	// ファイルバッファー(コンストラクタで開く)
	std::ofstream fileBuff(fileName);

	// もしファイルが開かなかったり、なかったら1を返す
	if (!fileBuff) { return 1; }

	// 入力処理
	else 
	{
		for (auto& ic : coment) 
		{
			fileBuff << ic << "," << std::endl;
		}

		return 0;
	}
}

int IOcsv::Output(const char* fileName, int* data, const int& dataIndex, const char** coment, const int& comeIndex) {
	// ファイルバッファー(コンストラクタで開く)
	std::ofstream fileBuff(fileName);

	// もしファイルが開かなかったり、なかったら1を返す
	if (!fileBuff) { return 1; }

	// 入力処理
	else
	{
		// for文のバッファー
		int num = 0;
		if (dataIndex > comeIndex) { num = dataIndex; }
		else if (dataIndex <= comeIndex) { num = comeIndex; }

		for (int i = 0; i < num; i++)
		{
			if (i >= dataIndex && i < comeIndex) {
				fileBuff << coment[i] << "," << std::endl;
			}
			else if (i < dataIndex && i >= comeIndex) {
				fileBuff << data[i] << "," << std::endl;
			}
			else {
				fileBuff << coment[i] << "," << data[i] << "," << std::endl;
			}
		}

		return 0;
	}
}

int IOcsv::Output(const char* fileName, float* data, const int& dataIndex, const char** coment, const int& comeIndex) {
	// ファイルバッファー(コンストラクタで開く)
	std::ofstream fileBuff(fileName);

	// もしファイルが開かなかったり、なかったら1を返す
	if (!fileBuff) { return 1; }

	// 入力処理
	else
	{
		// for文のバッファー
		int num = 0;
		if (dataIndex > comeIndex) { num = dataIndex; }
		else if (dataIndex <= comeIndex) { num = comeIndex; }

		for (int i = 0; i < num; i++)
		{
			if (i >= dataIndex && i < comeIndex) {
				fileBuff << coment[i] << "," << std::endl;
			}
			else if (i < dataIndex && i >= comeIndex) {
				fileBuff << data[i] << "," << std::endl;
			}
			else {
				fileBuff << coment[i] << "," << data[i] << "," << std::endl;
			}
		}

		return 0;
	}
}

int IOcsv::Output(const char* fileName, int* data, const int& index) {
	// ファイルバッファー(コンストラクタで開く)
	std::ofstream fileBuff(fileName);

	// もしファイルが開かなかったり、なかったら1を返す
	if (!fileBuff) { return 1; }

	else
	{
		// 入力処理
		for (int i=0;i<index;i++)
		{
			fileBuff << data[i] << "," << std::endl;
		}

		return 0;
	}
}

int IOcsv::Output(const char* fileName, float* data, const int& index) {
	// ファイルバッファー(コンストラクタで開く)
	std::ofstream fileBuff(fileName);

	// もしファイルが開かなかったり、なかったら1を返す
	if (!fileBuff) { return 1; }

	else
	{
		// 入力処理
		for (int i = 0; i < index; i++)
		{
			fileBuff << data[i] << "," << std::endl;
		}

		return 0;
	}
}

int IOcsv::Output(const char* fileName, const char** data, const int& index) {
	// ファイルバッファー(コンストラクタで開く)
	std::ofstream fileBuff(fileName);

	// もしファイルが開かなかったり、なかったら1を返す
	if (!fileBuff) { return 1; }

	else
	{
		// 入力処理
		for (int i = 0; i < index; i++)
		{
			fileBuff << data[i] << "," << std::endl;
		}

		return 0;
	}
}

