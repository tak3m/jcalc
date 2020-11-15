#include <vector>
#include <stdlib.h>
#include <math.h>

using namespace std;

vector<string> var = {"var0", "var1", "var2", "var3", "var4", "var5", "var6", "var7", "var8", "var9", "var10", "var11",  "var12", "var13", "var14", "var15"};
double mem[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

//NUM CHECK
bool isNumber(string& s)
{
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it))
	{
		it++;
	}
	return !s.empty() && it == s.end();
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
			cout << "	? Unknown type \"" << com[i] << "\"" << endl;
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
			cout << "	? Unknown type \"" << com[i] << "\"" << endl;
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
			cout << "	? Unknown type \"" << com[i] << "\"" << endl;
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
			cout << "	? Unknown type \"" << com[i] << "\"" << endl;
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
				cout << "	? Unknown type \"" << com[2] << "\"" << endl;
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
			cout << "	? Unknown type \"" << com[1] << "\"" << endl;
		}
	}
	else
	{
		n = 0;
		cout << "	? Lack of parameters" << endl;
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
				cout << "	? Unknown type \"" << com[2] << "\"" << endl;
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
			cout << "	? Unknown type \"" << com[1] << "\"" << endl;
		}
	}
	else
	{
		n = 0;
		cout << "	? Lack of parameters" << endl;
	}

	return n;
}

