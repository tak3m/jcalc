#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string version = "1.0a";
string lang = "English";

int LANG_NORMAL  = 0;
int LANG_TABBED  = 1;
int LANG_ERROR   = 2;
int LANG_OK      = 3;
int LANG_DICTYPE = 4;
int LANG_WRONGTP = 5;

//Translations
//responses
string MSG00_INVALIDCOM = "Invalid command";
string MSG01_NUMCHECKER = "Must be a number";
string MSG02_BADMEMFUNC = "Wrong mem function";
string MSG03_MEMCLEARED = "Memory cleared.";
string MSG04_GOODBYEAPP = "Application ended successfully.";
string MSG05_UNKNOWNTYP = "Unknown type";
string MSG06_LACKOFPARA = "Lack of parameters";

//dictionary
string DC000_TITLE00000 = "LIST OF COMMANDS";
string DC000_TITLE00001 = "BASIC OPERATIONS";
string DC000_TITLE00002 = "TRIGONOMETRY";
string DC000_TITLE00003 = "MISCELLANEOUS";

string DC001_ADDOPABOUT = "add [x1] [x2] [x3] ...  -> Add numbers or variables (similar to 1 + 1 + 1)";
string DC001_SUBOPABOUT = "sub [x1] [x2] [x3] ...  -> Subtract numbers or variables (similar to 1 - 1 - 1), the first number is always positive";
string DC001_MULOPABOUT = "mul [x1] [x2] [x3] ...  -> Multiply numbers or variables (similar to 1 * 1 * 1)";
string DC001_DIVOPABOUT = "div [x1] [x2] [x3] ...  -> Divide numbers or variables (similar to 1 / 1 / 1)";
string DC001_POWOPABOUT = "pow [x] [y]             -> Function of powers (similar to x ^ y or 3 ^ 2 = 9)";
string DC001_RTOPRABOUT = "rt  [x] [y]             -> Function of roots (similar to x ^ (1 / y)";

string DC001_SINOPABOUT = "sin  [type] [x]         -> Calculate sine of an angle. Default type is degrees (deg), [type] = deg, rad or gra";
string DC001_COSOPABOUT = "cos  [type] [x]         -> Calculate cossine of an angle. Default type is degrees (deg), [type] = deg, rad or gra";
string DC001_TANOPABOUT = "tan  [type] [x]         -> Calculate tangent of an angle. Default type is degrees (deg), [type] = deg, rad or gra";
string DC001_ASINPABOUT = "asin [type] [x]         -> Calculate arc sine. Default type is degrees (deg), [type] = deg, rad or gra";
string DC001_ACOSPABOUT = "acos [type] [x]         -> Calculate arc cossine. Default type is degrees (deg), [type] = deg, rad or gra";
string DC001_ATANPABOUT = "atan [type] [x]         -> Calculate arc tangent. Default type is degrees (rad), [type] = deg, rad or gra";


void printlang(int type, string line = "", vector<string> com = {}, int i = 1)
{
        if (type == LANG_NORMAL)
        {
                cout << line << endl;
        }
        if (type == LANG_TABBED)
        {
                cout << "       " << line << endl;
        }
        if (type == LANG_ERROR)
        {
                cout << "       ? " << line << endl;
        }
        if (type == LANG_OK)
        {
                cout << "       OK." << endl;
        }
        if (type == LANG_DICTYPE)
        {
                cout << " " << line << endl;
        }
        if (type == LANG_WRONGTP)
        {
                cout << "       ? " << MSG05_UNKNOWNTYP << " \"";
                cout << com[i] << "\"" << endl;
        }

}

void printspc(int spaceNumber = 1)
{
        for (int i = 1; i <= spaceNumber; i++)
        {
                cout << "" << endl;
        }
}

void printhead(string line)
{
        printspc();
        printlang(LANG_DICTYPE, line);
        printspc();
}

void printdic(int page = 0)
{
        if (page == 0)
        {
                cout << "JCALC " << version << " - [" << lang << "] " << DC000_TITLE00000 << endl;

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
