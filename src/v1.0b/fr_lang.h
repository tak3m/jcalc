#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <iostream>
#include <string>

using namespace std;

wstring version = L"1.0b";
wstring lang = L"Français";

const char* loc = "fr_FR.UTF-8";

int LANG_NORMAL  = 0;
int LANG_TABBED  = 1;
int LANG_ERROR   = 2;
int LANG_OK      = 3;
int LANG_DICTYPE = 4;
int LANG_WRONGTP = 5;

//Translations
//responses
wstring MSG00_INVALIDCOM = L"Commande invalide";
wstring MSG01_NUMCHECKER = L"Devoir être un nombre";
wstring MSG02_BADMEMFUNC = L"Fonction de mémoire faux";
wstring MSG03_MEMCLEARED = L"Mémoire prope.";
wstring MSG04_GOODBYEAPP = L"L'application a été fermé avec succès.";
wstring MSG05_UNKNOWNTYP = L"Type inconnu";
wstring MSG06_LACKOFPARA = L"Paramètres manquants";
wstring MSG07_NUMTOOLONG = L"Nombre trop grand";

//dictionary
wstring DC000_TITLE00000 = L"LISTE DE COMMANDES";
wstring DC000_TITLE00001 = L"OPÉRATIONS BASIQUES";
wstring DC000_TITLE00002 = L"TRIGONOMÉTRIE";
wstring DC000_TITLE00003 = L"AUTRES";

wstring DC001_ADDOPABOUT = L"add [x1] [x2] [x3] ...  -> Additionner des nombres ou des variables (similaire à 1 + 1 + 1)";
wstring DC001_SUBOPABOUT = L"sub [x1] [x2] [x3] ...  -> Soustraire des nombres ou des variables  (similaire à 1 - 1 - 1), le primier nombre est toujours positif.";
wstring DC001_MULOPABOUT = L"mul [x1] [x2] [x3] ...  -> Multiplier des nombres ou des variables (similaire à 1 * 1 * 1)";
wstring DC001_DIVOPABOUT = L"div [x1] [x2] [x3] ...  -> Diviser des nombres ou des variables (similaire à 1 / 1 / 1)";
wstring DC001_POWOPABOUT = L"pow [x] [y]             -> Fonction de puissances (similaire à x ^ y or 3 ^ 2 = 9)";
wstring DC001_RTOPRABOUT = L"rt  [x] [y]             -> Fonction de racines (similaire à x ^ (1 / y)";

wstring DC001_SINOPABOUT = L"sin  [type] [x]         -> Calculer le sinus d’un angle. Le type prédéfini est degrés (deg), [type] = deg, rad ou gra";
wstring DC001_COSOPABOUT = L"cos  [type] [x]         -> Calculer le cosinus d’un angle. Le type prédéfini est degrés (deg), [type] = deg, rad ou gra";
wstring DC001_TANOPABOUT = L"tan  [type] [x]         -> Calculer la tangente d’un angle. Le type prédéfini est degrés (deg), [type] = deg, rad ou gra";
wstring DC001_ASINPABOUT = L"asin [type] [x]         -> Calculer l'arc sinus. Le type prédéfini est degrés (deg), [type] = deg, rad ou gra";
wstring DC001_ACOSPABOUT = L"acos [type] [x]         -> Calculer l'arc cosinus. Le type prédéfini est degrés (deg), [type] = deg, rad ou gra";
wstring DC001_ATANPABOUT = L"atan [type] [x]         -> Calculer l'arc tangente. Le type prédéfini est degrés (rad), [type] = deg, rad ou gra";

wstring DC001_PRCVTTOOLS = L"cvt [type1] [type2] [x] -> Conversion entre systèmes numériques. Les types sont 'hex' pour Hexadécimal, 'dec' pour Décimal, 'oct' pour Octal et 'bin' pour binaire";

wstring VER00_AUTHORWHAT = L"par tachikawa20";
wstring VER01_LICENSEWHO = L"Protégé pour la permis GPL v3.";
wstring VER02_RELEASEDAT = L"2020/11";
wstring VER03_MOTTOABOUT = L"Indiquant pour la maxime compatibilité. Toujours.";

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