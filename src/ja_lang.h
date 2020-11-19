#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <iostream>
#include <string>

using namespace std;

wstring version = L"1.0a";
wstring lang = L"日本語";

const char* loc = "ja_JP.UTF-8";

int LANG_NORMAL  = 0;
int LANG_TABBED  = 1;
int LANG_ERROR   = 2;
int LANG_OK      = 3;
int LANG_DICTYPE = 4;
int LANG_WRONGTP = 5;

//Translations
//responses
wstring MSG00_INVALIDCOM = L"間違ったコマンド";
wstring MSG01_NUMCHECKER = L"数字のみを入力して下さい";
wstring MSG02_BADMEMFUNC = L"間違ったメモリ関数";
wstring MSG03_MEMCLEARED = L"メモリがクリアされました。";
wstring MSG04_GOODBYEAPP = L"アプリケーションは正常に終了しました。";
wstring MSG05_UNKNOWNTYP = L"不明なタイプ";
wstring MSG06_LACKOFPARA = L"パラメータが不足しています";

//dictionary
wstring DC000_TITLE00000 = L"コマンドリスト";
wstring DC000_TITLE00001 = L"基本的な演算";
wstring DC000_TITLE00002 = L"三角法";
wstring DC000_TITLE00003 = L"雑多";

wstring DC001_ADDOPABOUT = L"add [x1] [x2] [x3] ...  -> 数字か変数を加えります (1 + 1 + 1)";
wstring DC001_SUBOPABOUT = L"sub [x1] [x2] [x3] ...  -> 数字か変数を引きます (1 - 1 - 1)、 一番の数字はいつも正数";
wstring DC001_MULOPABOUT = L"mul [x1] [x2] [x3] ...  -> 数字か変数をかけます (1 * 1 * 1)";
wstring DC001_DIVOPABOUT = L"div [x1] [x2] [x3] ...  -> 数字か変数を割ります (1 / 1 / 1)";
wstring DC001_POWOPABOUT = L"pow [x] [y]             -> 乗冪 (x ^ y か 3 ^ 2 = 9)";
wstring DC001_RTOPRABOUT = L"rt  [x] [y]             -> ～方根 (x ^ (1 / y)";

wstring DC001_SINOPABOUT = L"sin  [タイプ] [x]         -> 角度の正弦を計算します。 デフォルトのタイプは度です (deg)、 [タイプ] = deg, rad or gra";
wstring DC001_COSOPABOUT = L"cos  [タイプ] [x]         -> 角度の余弦を計算します。 デフォルトのタイプは度です (deg)、 [タイプ] = deg, rad or gra";
wstring DC001_TANOPABOUT = L"tan  [タイプ] [x]         -> 角度の正接を計算します。 デフォルトのタイプは度です (deg)、 [タイプ] = deg, rad or gra";
wstring DC001_ASINPABOUT = L"asin [タイプ] [x]         -> 角度のアークサインを計算します。 デフォルトのタイプは度です (deg)、 [タイプ] = deg, rad or gra";
wstring DC001_ACOSPABOUT = L"acos [タイプ] [x]         -> 角度のアークコサインを計算します。 デフォルトのタイプは度です (deg)、 [タイプ] = deg, rad or gra";
wstring DC001_ATANPABOUT = L"atan [タイプ] [x]         -> 角度のアークタンジェントを計算します。 デフォルトのタイプは度です (rad)、 [タイプ] = deg, rad or gra";

void changelang(const char* loc)
{
	setlocale(LC_ALL, loc);
}

void printlang(int type, wstring line = L"", vector<string> com = {}, int i = 1)
{
	if (type == LANG_NORMAL)
	{
		wcout << line << endl;
	}
	else if (type == LANG_TABBED)
	{
		wcout << "	" << line << endl;
	}
	else if (type == LANG_ERROR)
	{
		wcout << "	? " << line << endl;
	}
	else if (type == LANG_OK)
	{
		wcout << "	OK." << endl;
	}
	else if (type == LANG_DICTYPE)
	{
		wcout << " " << line << endl;
	}
	else if (type == LANG_WRONGTP)
	{
		wcout << "	? " << MSG05_UNKNOWNTYP << " \"";
		cout << com[i] << "\"" << endl;
	}
}

void printspc(int spaceNumber = 1)
{
	for (int i = 1; i <= spaceNumber; i++)
	{
		wcout << "" << endl;
	}
}

void printhead(wstring line)
{
	printspc();
	printlang(LANG_DICTYPE, line);
	printspc();
}

void printdic(int page = 0)
{
	if (page == 0)
	{
		wcout << L"JCALC " << version << L" - [" << lang << L"] " << DC000_TITLE00000 << endl;

		printhead(DC000_TITLE00001);

		printlang(LANG_TABBED, DC001_ADDOPABOUT);
		printlang(LANG_TABBED, DC001_SUBOPABOUT);
		printlang(LANG_TABBED, DC001_MULOPABOUT);
		printlang(LANG_TABBED, DC001_DIVOPABOUT);
		printlang(LANG_TABBED, DC001_POWOPABOUT);
		printlang(LANG_TABBED, DC001_RTOPRABOUT);
		
		printhead(DC000_TITLE00002);
		
		printlang(LANG_TABBED, DC001_SINOPABOUT);
		printlang(LANG_TABBED, DC001_COSOPABOUT);
		printlang(LANG_TABBED, DC001_TANOPABOUT);
		printlang(LANG_TABBED, DC001_ASINPABOUT);
		printlang(LANG_TABBED, DC001_ACOSPABOUT);
		printlang(LANG_TABBED, DC001_ATANPABOUT);
		printspc();
	}
}

#endif