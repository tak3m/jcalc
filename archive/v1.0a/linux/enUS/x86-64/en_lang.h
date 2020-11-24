#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <iostream>
#include <string>

using namespace std;

wstring version = L"1.0a";
wstring lang = L"English";

const char* loc = "en_US.UTF-8";

int LANG_NORMAL  = 0;
int LANG_TABBED  = 1;
int LANG_ERROR   = 2;
int LANG_OK      = 3;
int LANG_DICTYPE = 4;
int LANG_WRONGTP = 5;

//Translations
//responses
wstring MSG00_INVALIDCOM = L"Invalid command";
wstring MSG01_NUMCHECKER = L"Must be a number";
wstring MSG02_BADMEMFUNC = L"Wrong mem function";
wstring MSG03_MEMCLEARED = L"Memory cleared.";
wstring MSG04_GOODBYEAPP = L"Application ended successfully.";
wstring MSG05_UNKNOWNTYP = L"Unknown type";
wstring MSG06_LACKOFPARA = L"Lack of parameters";

//dictionary
wstring DC000_TITLE00000 = L"LIST OF COMMANDS";
wstring DC000_TITLE00001 = L"BASIC OPERATIONS";
wstring DC000_TITLE00002 = L"TRIGONOMETRY";
wstring DC000_TITLE00003 = L"MISCELLANEOUS";

wstring DC001_ADDOPABOUT = L"add [x1] [x2] [x3] ...  -> Add numbers or variables (similar to 1 + 1 + 1)";
wstring DC001_SUBOPABOUT = L"sub [x1] [x2] [x3] ...  -> Subtract numbers or variables (similar to 1 - 1 - 1), the first number is always positive";
wstring DC001_MULOPABOUT = L"mul [x1] [x2] [x3] ...  -> Multiply numbers or variables (similar to 1 * 1 * 1)";
wstring DC001_DIVOPABOUT = L"div [x1] [x2] [x3] ...  -> Divide numbers or variables (similar to 1 / 1 / 1)";
wstring DC001_POWOPABOUT = L"pow [x] [y]             -> Function of powers (similar to x ^ y or 3 ^ 2 = 9)";
wstring DC001_RTOPRABOUT = L"rt  [x] [y]             -> Function of roots (similar to x ^ (1 / y)";

wstring DC001_SINOPABOUT = L"sin  [type] [x]         -> Calculate sine of an angle. Default type is degrees (deg), [type] = deg, rad or gra";
wstring DC001_COSOPABOUT = L"cos  [type] [x]         -> Calculate cossine of an angle. Default type is degrees (deg), [type] = deg, rad or gra";
wstring DC001_TANOPABOUT = L"tan  [type] [x]         -> Calculate tangent of an angle. Default type is degrees (deg), [type] = deg, rad or gra";
wstring DC001_ASINPABOUT = L"asin [type] [x]         -> Calculate arc sine. Default type is degrees (deg), [type] = deg, rad or gra";
wstring DC001_ACOSPABOUT = L"acos [type] [x]         -> Calculate arc cossine. Default type is degrees (deg), [type] = deg, rad or gra";
wstring DC001_ATANPABOUT = L"atan [type] [x]         -> Calculate arc tangent. Default type is degrees (rad), [type] = deg, rad or gra";

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