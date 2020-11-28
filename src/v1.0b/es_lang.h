#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <iostream>
#include <string>

using namespace std;

wstring version = L"1.0b";
wstring lang = L"Español";

const char* loc = "es_ES.UTF-8";

int LANG_NORMAL  = 0;
int LANG_TABBED  = 1;
int LANG_ERROR   = 2;
int LANG_OK      = 3;
int LANG_DICTYPE = 4;
int LANG_WRONGTP = 5;

//Translations
//responses
wstring MSG00_INVALIDCOM = L"Comando inválido";
wstring MSG01_NUMCHECKER = L"Tiene que ser un número";
wstring MSG02_BADMEMFUNC = L"Función de memoria incorrecta";
wstring MSG03_MEMCLEARED = L"Memoria limpia.";
wstring MSG04_GOODBYEAPP = L"La aplicación finalizó con éxito.";
wstring MSG05_UNKNOWNTYP = L"Tipo desconocido";
wstring MSG06_LACKOFPARA = L"Parámetros en falta";
wstring MSG07_NUMTOOLONG = L"Número demasiado grande";

//dictionary
wstring DC000_TITLE00000 = L"LISTA DE COMANDOS";
wstring DC000_TITLE00001 = L"OPERACIONES BÁSICAS";
wstring DC000_TITLE00002 = L"TRIGONOMETRÍA";
wstring DC000_TITLE00003 = L"OTROS";

wstring DC001_ADDOPABOUT = L"add [x1] [x2] [x3] ...  -> Añadir números o variables (similar a 1 + 1 + 1)";
wstring DC001_SUBOPABOUT = L"sub [x1] [x2] [x3] ...  -> Restar números o variables (similar a 1 - 1 - 1), el primer número es siempre positivo.";
wstring DC001_MULOPABOUT = L"mul [x1] [x2] [x3] ...  -> Multiplicar números o variables (similar a 1 * 1 * 1)";
wstring DC001_DIVOPABOUT = L"div [x1] [x2] [x3] ...  -> Dividir números o variables (similar a 1 / 1 / 1)";
wstring DC001_POWOPABOUT = L"pow [x] [y]             -> Función de potências (similar a x ^ y o 3 ^ 2 = 9)";
wstring DC001_RTOPRABOUT = L"rt  [x] [y]             -> Función de raíces (similar a x ^ (1 / y)";

wstring DC001_SINOPABOUT = L"sin  [type] [x]         -> Calcular el seno de un ángulo. El tipo predeterminado es grados (deg), [tipo] = deg, rad o gra";
wstring DC001_COSOPABOUT = L"cos  [type] [x]         -> Calcular el coseno de un ángulo. El tipo predeterminado es grados (deg), [tipo] = deg, rad o gra";
wstring DC001_TANOPABOUT = L"tan  [type] [x]         -> Calcular la tangente de un ángulo. El tipo predeterminado es grados (deg), [tipo] = deg, rad o gra";
wstring DC001_ASINPABOUT = L"asin [type] [x]         -> Calcular el arco seno. El tipo predeterminado es grados (deg), [tipo] = deg, rad o gra";
wstring DC001_ACOSPABOUT = L"acos [type] [x]         -> Calcular el arco coseno. El tipo predeterminado es grados (deg), [tipo] = deg, rad o gra";
wstring DC001_ATANPABOUT = L"atan [type] [x]         -> Calcular el arco tangente. El tipo predeterminado es grados (rad), [tipo] = deg, rad o gra";

wstring DC001_PRCVTTOOLS = L"cvt [type1] [type2] [x] -> Conversión entre sistemas numéricos. Los tipos son 'hex' para Hexadecimal, 'dec' para Decimal, 'oct' para Octal y 'bin' para Binario";

//about
wstring VER00_AUTHORWHAT = L"por tachikawa20";
wstring VER01_LICENSEWHO = L"Protegido por la licencia GPL v3.";
wstring VER02_RELEASEDAT = L"2020/11";
wstring VER03_MOTTOABOUT = L"Apuntando a la máxima compatibilidad. Siempre.";

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

		printhead(DC000_TITLE00003);

		printlang(LANG_TABBED, DC001_PRCVTTOOLS);
		printspc();
	}
}

void printabout()
{
	printspc();
	wcout << L"    JCALC " << version << L" - [" << lang << L"] " << endl;
	printlang(LANG_TABBED, VER00_AUTHORWHAT);
	printlang(LANG_TABBED, VER01_LICENSEWHO);
	printlang(LANG_TABBED, VER02_RELEASEDAT);
	printspc();
	printlang(LANG_TABBED, VER03_MOTTOABOUT);
	printspc();
}

#endif