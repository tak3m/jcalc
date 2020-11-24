#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

#include "pt_lang.h"

#define PI 3.14159265

using namespace std;

vector<string> var = { "var0", "var1", "var2", "var3", "var4", "var5", "var6", "var7", "var8", "var9", "var10", "var11",  "var12", "var13", "var14", "var15" };
vector<string> cvar = { "pi" };

double mem[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
double cmem[] = { PI };

bool isNumber(string src)
{
	stringstream ss;
	ss << src;
	double d = 0;
	ss >> d;
	if (ss)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isUnsignedInt(string src)
{
	stringstream ss;
	ss << src;
	unsigned int i = 0;
	ss >> i;
	if (ss)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//MEM
void clearMem()
{
	for (int i = 0; i < 16; i++)
	{
		mem[i] = 0;
	}
}

void addMem(vector <string> com, int i)
{
	if (!isNumber(com[0]))
	{
		mem[i] = stod(com[1]);
	}
	else
	{
		cout << "	? Unknown type \"" << com[0] << "\"" << endl;
	}
}

//VAR CHECK
bool varExists(vector <string> v, string item)
{
	if (count(v.begin(), v.end(), item))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//MAIN FUNC
double add(vector <string> com)
{
	double n = 0;

	for (int i = 1; i < com.size(); i++)
	{
		if (isNumber(com[i]))
		{
			n = n + stod(com[i]);
		}
		else if (varExists(var, com[i]))
		{
			vector<string>::iterator it = find(var.begin(), var.end(), com[i]);

			int index = distance(var.begin(), it);

			n = n + mem[index];
		}
		else
		{
			printlang(LANG_WRONGTP, L"", com, i);
		}
	}

	return n;
}

double sub(vector <string> com)
{
	double n = 0;

	for (int i = 1; i < com.size(); i++)
	{
		if (isNumber(com[i]))
		{
			if (i == 1)
			{
				n = stod(com[i]);
			}
			else
			{
				n = n - stod(com[i]);
			}
		}
		else if (varExists(var, com[i]))
		{
			vector<string>::iterator it = find(var.begin(), var.end(), com[i]);

			int index = distance(var.begin(), it);

			if (i == 1)
			{
				n = mem[index];
			}
			else
			{
				n = n - mem[index];
			}

		}
		else
		{
			printlang(LANG_WRONGTP, L"", com, i);
		}
	}

	return n;
}

double mul(vector <string> com)
{
	double n;

	for (int i = 1; i < com.size(); i++)
	{
		if (isNumber(com[i]))
		{
			if (i == 1)
			{
				n = stod(com[i]);
			}
			else
			{
				n = n * stod(com[i]);
			}
		}
		else if (varExists(var, com[i]))
		{
			vector<string>::iterator it = find(var.begin(), var.end(), com[i]);

			int index = distance(var.begin(), it);

			if (i == 1)
			{
				n = mem[index];
			}
			else
			{
				n = n * mem[index];
			}

		}
		else
		{
			printlang(LANG_WRONGTP, L"", com, i);
		}
	}

	return n;
}

double div(vector <string> com)
{
	double n;

	for (int i = 1; i < com.size(); i++)
	{
		if (isNumber(com[i]))
		{
			if (i == 1)
			{
				n = stod(com[i]);
			}
			else
			{
				n = n / stod(com[i]);
			}
		}
		else if (varExists(var, com[i]))
		{
			vector<string>::iterator it = find(var.begin(), var.end(), com[i]);

			int index = distance(var.begin(), it);

			if (i == 1)
			{
				n = mem[index];
			}
			else
			{
				n = n / mem[index];
			}

		}
		else
		{
			printlang(LANG_WRONGTP, L"", com, i);
		}
	}

	return n;
}

double pow(vector <string> com)
{
	double n;

	if (com.size() == 3)
	{
		if (isNumber(com[1]))
		{
			if (isNumber(com[2]))
			{
				n = pow(stod(com[1]), stod(com[2]));
			}
			else
			{
				n = 0;
				printlang(LANG_WRONGTP, L"", com, 2);
			}
		}
		else if (varExists(var, com[1]) || varExists(var, com[2]))
		{
			vector<string>::iterator it1 = find(var.begin(), var.end(), com[1]);
			vector<string>::iterator it2 = find(var.begin(), var.end(), com[1]);

			int index1 = distance(var.begin(), it1);
			int index2 = distance(var.begin(), it1);

			n = pow(mem[index1], mem[index2]);

		}
		else
		{
			n = 0;
			printlang(LANG_WRONGTP, L"", com, 1);
		}
	}
	else
	{
		n = 0;
		printlang(LANG_ERROR, MSG06_LACKOFPARA);
	}

	return n;
}

double rt(vector <string> com)
{
	double n;

	if (com.size() == 3)
	{
		if (isNumber(com[1]))
		{
			if (isNumber(com[2]))
			{
				n = pow(stod(com[1]), 1 / stod(com[2]));
			}
			else
			{
				n = 0;
				printlang(LANG_WRONGTP, L"", com, 2);
			}
		}
		else if (varExists(var, com[1]) || varExists(var, com[2]))
		{
			vector<string>::iterator it1 = find(var.begin(), var.end(), com[1]);
			vector<string>::iterator it2 = find(var.begin(), var.end(), com[1]);

			int index1 = distance(var.begin(), it1);
			int index2 = distance(var.begin(), it1);

			n = pow(mem[index1], 1 / mem[index2]);

		}
		else
		{
			n = 0;
			printlang(LANG_WRONGTP, L"", com, 1);
		}
	}
	else
	{
		n = 0;
		printlang(LANG_ERROR, MSG06_LACKOFPARA);
	}

	return n;
}

double sin(vector <string> com)
{
	double n;

	if (com.size() == 2)
	{
		if (isNumber(com[1]))
		{
			n = sin(stod(com[1]) * PI / 180);
		}
		else if (varExists(var, com[1]))
		{
			vector<string>::iterator it1 = find(var.begin(), var.end(), com[1]);

			int index1 = distance(var.begin(), it1);

			n = sin(mem[index1] * PI / 180);
		}
		else
		{
			n = 0;
			printlang(LANG_WRONGTP, L"", com, 1);
		}
	}
	else if (com.size() == 3)
	{
		if (!isNumber(com[1]))
		{
			if (!varExists(var, com[1]))
			{
				if (com[1] == "deg")
				{
					n = sin(stod(com[2]) * PI / 180);
				}
				else if (com[1] == "rad")
				{
					n = sin(stod(com[2]));
				}
				else if (com[1] == "gra")
				{
					n = sin(stod(com[2]) * PI / 200);
				}
				else
				{
					n = 0;
					printlang(LANG_ERROR, MSG00_INVALIDCOM);
				}
			}
			else
			{
				vector<string>::iterator it1 = find(var.begin(), var.end(), com[1]);

				int index1 = distance(var.begin(), it1);

				n = sin(mem[index1] * PI / 180);
			}
		}
		else
		{
			n = 0;
			printlang(LANG_ERROR, MSG00_INVALIDCOM);
		}
	}
	else
	{
		n = 0;
		printlang(LANG_ERROR, MSG06_LACKOFPARA);
	}

	return n;
}


double cos(vector <string> com)
{
	double n;

	if (com.size() == 2)
	{
		if (isNumber(com[1]))
		{
			n = cos(stod(com[1]) * PI / 180);
		}
		else if (varExists(var, com[1]))
		{
			vector<string>::iterator it1 = find(var.begin(), var.end(), com[1]);

			int index1 = distance(var.begin(), it1);

			n = cos(mem[index1] * PI / 180);
		}
		else
		{
			n = 0;
			printlang(LANG_WRONGTP, L"", com, 1);
		}
	}
	else if (com.size() == 3)
	{
		if (!isNumber(com[1]))
		{
			if (!varExists(var, com[1]))
			{
				if (com[1] == "deg")
				{
					n = cos(stod(com[2]) * PI / 180);
				}
				else if (com[1] == "rad")
				{
					n = cos(stod(com[2]));
				}
				else if (com[1] == "gra")
				{
					n = cos(stod(com[2]) * PI / 200);
				}
				else
				{
					n = 0;
					printlang(LANG_ERROR, MSG00_INVALIDCOM);
				}
			}
			else
			{
				vector<string>::iterator it1 = find(var.begin(), var.end(), com[1]);

				int index1 = distance(var.begin(), it1);

				n = cos(mem[index1] * PI / 180);
			}
		}
		else
		{
			n = 0;
			printlang(LANG_ERROR, MSG00_INVALIDCOM);
		}
	}
	else
	{
		n = 0;
		printlang(LANG_ERROR, MSG06_LACKOFPARA);
	}

	return n;
}


double tan(vector <string> com)
{
	double n;

	if (com.size() == 2)
	{
		if (isNumber(com[1]))
		{
			n = tan(stod(com[1]) * PI / 180);
		}
		else if (varExists(var, com[1]))
		{
			vector<string>::iterator it1 = find(var.begin(), var.end(), com[1]);

			int index1 = distance(var.begin(), it1);

			n = tan(mem[index1] * PI / 180);
		}
		else
		{
			n = 0;
			printlang(LANG_WRONGTP, L"", com, 1);
		}
	}
	else if (com.size() == 3)
	{
		if (!isNumber(com[1]))
		{
			if (!varExists(var, com[1]))
			{
				if (com[1] == "deg")
				{
					n = tan(stod(com[2]) * PI / 180);
				}
				else if (com[1] == "rad")
				{
					n = tan(stod(com[2]));
				}
				else if (com[1] == "gra")
				{
					n = tan(stod(com[2]) * PI / 200);
				}
				else
				{
					n = 0;
					printlang(LANG_ERROR, MSG00_INVALIDCOM);
				}
			}
			else
			{
				vector<string>::iterator it1 = find(var.begin(), var.end(), com[1]);

				int index1 = distance(var.begin(), it1);

				n = tan(mem[index1] * PI / 180);
			}
		}
		else
		{
			n = 0;
			printlang(LANG_ERROR, MSG00_INVALIDCOM);
		}
	}
	else
	{
		n = 0;
		printlang(LANG_ERROR, MSG06_LACKOFPARA);
	}

	return n;
}


double asin(vector <string> com)
{
	double n;

	if (com.size() == 2)
	{
		if (isNumber(com[1]))
		{
			n = asin(stod(com[1])) * 180 / PI;
		}
		else if (varExists(var, com[1]))
		{
			vector<string>::iterator it1 = find(var.begin(), var.end(), com[1]);

			int index1 = distance(var.begin(), it1);

			n = asin(mem[index1]) * 180 / PI;
		}
		else
		{
			n = 0;
			printlang(LANG_WRONGTP, L"", com, 1);
		}
	}
	else if (com.size() == 3)
	{
		if (!isNumber(com[1]))
		{
			if (!varExists(var, com[1]))
			{
				if (com[1] == "deg")
				{
					n = asin(stod(com[2])) * 180 / PI;
				}
				else if (com[1] == "rad")
				{
					n = asin(stod(com[2]));
				}
				else if (com[1] == "gra")
				{
					n = asin(stod(com[2])) * 200 / PI;
				}
				else
				{
					n = 0;
					printlang(LANG_ERROR, MSG00_INVALIDCOM);
				}
			}
			else
			{
				vector<string>::iterator it1 = find(var.begin(), var.end(), com[1]);

				int index1 = distance(var.begin(), it1);

				n = asin(mem[index1]) * 180 / PI;
			}
		}
		else
		{
			n = 0;
			printlang(LANG_ERROR, MSG00_INVALIDCOM);
		}
	}
	else
	{
		n = 0;
		printlang(LANG_ERROR, MSG06_LACKOFPARA);
	}

	return n;
}


double acos(vector <string> com)
{
	double n;

	if (com.size() == 2)
	{
		if (isNumber(com[1]))
		{
			n = acos(stod(com[1])) * 180 / PI;
		}
		else if (varExists(var, com[1]))
		{
			vector<string>::iterator it1 = find(var.begin(), var.end(), com[1]);

			int index1 = distance(var.begin(), it1);

			n = acos(mem[index1]) * 180 / PI;
		}
		else
		{
			n = 0;
			printlang(LANG_WRONGTP, L"", com, 1);
		}
	}
	else if (com.size() == 3)
	{
		if (!isNumber(com[1]))
		{
			if (!varExists(var, com[1]))
			{
				if (com[1] == "deg")
				{
					n = acos(stod(com[2])) * 180 / PI;
				}
				else if (com[1] == "rad")
				{
					n = acos(stod(com[2]));
				}
				else if (com[1] == "gra")
				{
					n = acos(stod(com[2])) * 200 / PI;
				}
				else
				{
					n = 0;
					printlang(LANG_ERROR, MSG00_INVALIDCOM);
				}
			}
			else
			{
				vector<string>::iterator it1 = find(var.begin(), var.end(), com[1]);

				int index1 = distance(var.begin(), it1);

				n = acos(mem[index1]) * 180 / PI;
			}
		}
		else
		{
			n = 0;
			printlang(LANG_ERROR, MSG00_INVALIDCOM);
		}
	}
	else
	{
		n = 0;
		printlang(LANG_ERROR, MSG06_LACKOFPARA);
	}

	return n;
}


double atan(vector <string> com)
{
	double n;

	if (com.size() == 2)
	{
		if (isNumber(com[1]))
		{
			n = atan(stod(com[1])) * 180 / PI;
		}
		else if (varExists(var, com[1]))
		{
			vector<string>::iterator it1 = find(var.begin(), var.end(), com[1]);

			int index1 = distance(var.begin(), it1);

			n = atan(mem[index1]) * 180 / PI;
		}
		else
		{
			n = 0;
			printlang(LANG_WRONGTP, L"", com, 1);
		}
	}
	else if (com.size() == 3)
	{
		if (!isNumber(com[1]))
		{
			if (!varExists(var, com[1]))
			{
				if (com[1] == "deg")
				{
					n = atan(stod(com[2])) * 180 / PI;
				}
				else if (com[1] == "rad")
				{
					n = atan(stod(com[2]));
				}
				else if (com[1] == "gra")
				{
					n = atan(stod(com[2])) * 200 / PI;
				}
				else
				{
					n = 0;
					printlang(LANG_ERROR, MSG00_INVALIDCOM);
				}
			}
			else
			{
				vector<string>::iterator it1 = find(var.begin(), var.end(), com[1]);

				int index1 = distance(var.begin(), it1);

				n = atan(mem[index1]) * 180 / PI;
			}
		}
		else
		{
			n = 0;
			printlang(LANG_ERROR, MSG00_INVALIDCOM);
		}
	}
	else
	{
		n = 0;
		printlang(LANG_ERROR, MSG06_LACKOFPARA);
	}

	return n;
}

void digitsConverter(vector <string> com)
{
	int n;

	if (com.size() == 4)
	{
		if (!isNumber(com[1]))
		{
			if (com[1] == "hex")
			{
				if (com[2] == "hex")
				{
					cout << "	" << com[3] << "." << endl;
				}
				else if (com[2] == "dec")
				{
					unsigned long result = 0;
					string hex = com[3];
					for (int i = 0; i < hex.length(); i++) 
					{
						if (hex[i] >= 48 && hex[i] <= 57)
						{
							result += (hex[i] - 48)*pow(16, hex.length() - i - 1);
						}
						else if (hex[i] >= 65 && hex[i] <= 70) 
						{
							result += (hex[i] - 55)*pow(16, hex.length() - i - 1);
						}
						else if (hex[i] >= 97 && hex[i] <= 102) 
						{
							result += (hex[i] - 87)*pow(16, hex.length() - i - 1);
						}
					}
					cout << "	" << result << "." << endl;
				}
				else if (com[2] == "oct")
				{
					unsigned long result = 0;
					string hex = com[3];
					for (int i = 0; i < hex.length(); i++)
					{
						if (hex[i] >= 48 && hex[i] <= 57)
						{
							result += (hex[i] - 48)*pow(16, hex.length() - i - 1);
						}
						else if (hex[i] >= 65 && hex[i] <= 70)
						{
							result += (hex[i] - 55)*pow(16, hex.length() - i - 1);
						}
						else if (hex[i] >= 97 && hex[i] <= 102)
						{
							result += (hex[i] - 87)*pow(16, hex.length() - i - 1);
						}
					}
					stringstream stream;
					stream << oct << result;
					string res(stream.str());
					cout << "	" << res << "." << endl;
				}
				else if (com[2] == "bin")
				{
					stringstream stream;
					stream << hex << com[3];

					unsigned int num;
					while (stream >> num)
					{
						cout << "	";
						for (int i = 8 - 1; i >= 0; i--)
						{
							cout << ((num >> i) & 1) ? "1" : "0";
						}
						cout << "." << endl;
					}
				}
				else
				{
					n = 0;
					printlang(LANG_ERROR, MSG00_INVALIDCOM);
				}
			}
			else if (com[1] == "dec")
			{
				if (com[2] == "hex")
				{
					if (isUnsignedInt(com[3]))
					{
						stringstream stream;
						stream << hex << stoi(com[3]);
						string res(stream.str());
						cout << "	" << res << "." << endl;
					}
					else
					{
						n = 0;
						printlang(LANG_ERROR, MSG07_NUMTOOLONG);
					}
				}
				else if (com[2] == "dec")
				{
					cout << "	" << com[3] << "." << endl;
				}
				else if (com[2] == "oct")
				{
					if (isUnsignedInt(com[3]))
					{
						stringstream stream;
						stream << oct << stoi(com[3]);
						string res(stream.str());
						cout << "	" << res << "." << endl;
					}
					else
					{
						n = 0;
						printlang(LANG_ERROR, MSG07_NUMTOOLONG);
					}
				}
				else if (com[2] == "bin")
				{
					if (isUnsignedInt(com[3]))
					{
						string r;
						int num = stoi(com[3]);
						while (num != 0) { r = (num % 2 == 0 ? "0" : "1") + r; num /= 2; }
						cout << "	" << r << "." << endl;
					}
					else
					{
						n = 0;
						printlang(LANG_ERROR, MSG07_NUMTOOLONG);
					}
				}
				else
				{
					n = 0;
					printlang(LANG_ERROR, MSG00_INVALIDCOM);
				}
			}
			else if (com[1] == "oct")
			{
				if (com[2] == "hex")
				{
					if (isUnsignedInt(com[3]))
					{
						int decimal = 0;
						int octal = stoi(com[3]);
						int i = 0;
						while (octal != 0)
						{
							int rem = octal % 10;
							octal /= 10;
							int res = rem * pow(8, i);
							decimal += res;
							i++;
						}
						stringstream stream;
						stream << hex << decimal;
						string r(stream.str());
						cout << "	" << r << "." << endl;
					}
					else
					{
						n = 0;
						printlang(LANG_ERROR, MSG07_NUMTOOLONG);
					}
				}
				else if (com[2] == "dec")
				{
					if (isUnsignedInt(com[3]))
					{
						int decimal = 0;
						int octal = stoi(com[3]);
						int i = 0;
						while (octal != 0)
						{
							int rem = octal % 10;
							octal /= 10;
							int res = rem * pow(8, i);
							decimal += res;
							i++;
						}
						cout << "	" << decimal << "." << endl;
					}
					else
					{
						n = 0;
						printlang(LANG_ERROR, MSG07_NUMTOOLONG);
					}
				}
				else if (com[2] == "oct")
				{
					cout << "	" << com[3] << "." << endl;
				}
				else if (com[2] == "bin")
				{
					if (isUnsignedInt(com[3]))
					{
						int octalNumber = stoi(com[3]);
						int decimalNumber = 0, i = 0;
						long long binaryNumber = 0;

						while (octalNumber != 0)
						{
							decimalNumber += (octalNumber % 10) * pow(8, i);
							++i;
							octalNumber /= 10;
						}

						i = 1;

						while (decimalNumber != 0)
						{
							binaryNumber += (decimalNumber % 2) * i;
							decimalNumber /= 2;
							i *= 10;
						}

						cout << "	" << binaryNumber << "." << endl;
					}
					else
					{
						n = 0;
						printlang(LANG_ERROR, MSG07_NUMTOOLONG);
					}
				}
				else
				{
					n = 0;
					printlang(LANG_ERROR, MSG00_INVALIDCOM);
				}
			}
			else if (com[1] == "bin")
			{
				if (com[2] == "hex")
				{
					if (isUnsignedInt(com[3]))
					{
						unsigned long long value = stoull(com[3], 0, 2);
						stringstream stream;
						stream << hex << stoi(com[3]);
						string res(stream.str());
						cout << "	" << res << "." << endl;
					}
					else
					{
						n = 0;
						printlang(LANG_ERROR, MSG07_NUMTOOLONG);
					}
				}
				else if (com[2] == "dec")
				{
					if (isUnsignedInt(com[3]))
					{
						unsigned long long value = stoull(com[3], 0, 2);
						cout << "	" << value << "." << endl;
					}
					else
					{
						n = 0;
						printlang(LANG_ERROR, MSG07_NUMTOOLONG);
					}
				}
				else if (com[2] == "oct")
				{
					if (isUnsignedInt(com[3]))
					{
						unsigned long long value = stoull(com[3], 0, 2);
						stringstream stream;
						stream << oct << value;
						string res(stream.str());
						cout << "	" << res << "." << endl;
					}
					else
					{
						n = 0;
						printlang(LANG_ERROR, MSG07_NUMTOOLONG);
					}
				}
				else if (com[2] == "bin")
				{
					cout << "	" << com[3] << "." << endl;
				}
				else
				{
					n = 0;
					printlang(LANG_ERROR, MSG00_INVALIDCOM);
				}
			}
			else
			{
				n = 0;
				printlang(LANG_ERROR, MSG00_INVALIDCOM);
			}
			
		}

		else
		{
			n = 0;
			printlang(LANG_ERROR, MSG00_INVALIDCOM);
		}
	}
	else
	{
		n = 0;
		printlang(LANG_ERROR, MSG00_INVALIDCOM);
	}
}