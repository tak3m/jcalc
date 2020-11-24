#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <iostream>
#include <string>

using namespace std;

wstring version = L"1.0b";
wstring lang = L"Português";

const char* loc = "pt_PT.UTF-8";

int LANG_NORMAL  = 0;
int LANG_TABBED  = 1;
int LANG_ERROR   = 2;
int LANG_OK      = 3;
int LANG_DICTYPE = 4;
int LANG_WRONGTP = 5;

//Translations
//responses
wstring MSG00_INVALIDCOM = L"Comando inválido";
wstring MSG01_NUMCHECKER = L"Tem que ser um número";
wstring MSG02_BADMEMFUNC = L"Função de memória errada";
wstring MSG03_MEMCLEARED = L"Memória limpa.";
wstring MSG04_GOODBYEAPP = L"A aplicação encerrou com sucesso.";
wstring MSG05_UNKNOWNTYP = L"Tipo desconhecido";
wstring MSG06_LACKOFPARA = L"Parâmetros em falta";
wstring MSG07_NUMTOOLONG = L"Número demasiado grande";

//dictionary
wstring DC000_TITLE00000 = L"LISTA DE COMANDOS";
wstring DC000_TITLE00001 = L"OPERAÇÕES BÁSICAS";
wstring DC000_TITLE00002 = L"TRIGONOMETRIA";
wstring DC000_TITLE00003 = L"OUTROS";

wstring DC001_ADDOPABOUT = L"add [x1] [x2] [x3] ...  -> Adicionar números ou variáveis (semelhante a 1 + 1 + 1)";
wstring DC001_SUBOPABOUT = L"sub [x1] [x2] [x3] ...  -> Subtrair números ou variáveis (semelhante a 1 - 1 - 1), o primeiro número é sempre positivo.";
wstring DC001_MULOPABOUT = L"mul [x1] [x2] [x3] ...  -> Multiplicar números ou variáveis (semelhante a 1 * 1 * 1)";
wstring DC001_DIVOPABOUT = L"div [x1] [x2] [x3] ...  -> Dividir números ou variáveis (semelhante a 1 / 1 / 1)";
wstring DC001_POWOPABOUT = L"pow [x] [y]             -> Função de potências (semelhante a x ^ y or 3 ^ 2 = 9)";
wstring DC001_RTOPRABOUT = L"rt  [x] [y]             -> Função de raízes (semelhante a x ^ (1 / y)";

wstring DC001_SINOPABOUT = L"sin  [type] [x]         -> Calcular o seno de um ângulo. O tipo predefinido é graus (deg), [tipo] = deg, rad ou gra";
wstring DC001_COSOPABOUT = L"cos  [type] [x]         -> Calcular o cosseno de um ângulo. O tipo predefinido é graus (deg), [tipo] = deg, rad ou gra";
wstring DC001_TANOPABOUT = L"tan  [type] [x]         -> Calcular a tangente de um ângulo. O tipo predefinido é graus (deg), [tipo] = deg, rad ou gra";
wstring DC001_ASINPABOUT = L"asin [type] [x]         -> Calcular o arco seno. O tipo predefinido é graus (deg), [tipo] = deg, rad ou gra";
wstring DC001_ACOSPABOUT = L"acos [type] [x]         -> Calcular o arco cosseno. O tipo predefinido é graus (deg), [tipo] = deg, rad ou gra";
wstring DC001_ATANPABOUT = L"atan [type] [x]         -> Calcular o arco tangente. O tipo predefinido é graus (rad), [tipo] = deg, rad ou gra";

wstring DC001_PRCVTTOOLS = L"cvt [type1] [type2] [x] -> Conversão entre sistemas numéricos. Os tipos são 'hex' para Hexadecimal, 'dec' para Decimal, 'oct' para Octal e 'bin' para Binário";

//about
wstring VER00_AUTHORWHAT = L"por tachikawa20";
wstring VER01_LICENSEWHO = L"Protegido pela licença GPL v3.";
wstring VER02_RELEASEDAT = L"2020/11";
wstring VER03_MOTTOABOUT = L"Apontando para a máxima compatibilidade. Sempre.";

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