#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "jmath.h"
#include "fr_lang.h"

using namespace std;

int main()
{
	changelang(loc);

	bool condition = true;

	while (condition == true)
	{
	beg:

		string line;

		cout << "JCALC> ";
		getline(cin, line);

		vector <string> command;
		stringstream check(line);
		string intermediate;

		if (!line.empty())
		{
			while (getline(check, intermediate, ' '))
			{
				command.push_back(intermediate);
			}
		}
		else
		{
			printlang(LANG_ERROR, MSG00_INVALIDCOM);
			goto beg;
		}
		
		if (command[0] == "add")
		{
			double sum = add(command);
			cout << "	" << sum << "." << endl;
		}

		else if (command[0] == "sub")
		{
			double subt = sub(command);
			cout << "	" << subt << "." << endl;
		}

		else if (command[0] == "mul")
		{
			double mult = mul(command);
			cout << "	" << mult << "." << endl;
		}

		else if (command[0] == "div")
		{
			double divi = div(command);
			cout << "	" << divi << "." << endl;
		}

		else if (command[0] == "pow")
		{
			double powr = pow(command);
			cout << "	" << powr << "." << endl;
		}

		else if (command[0] == "rt")
		{
			double root = rt(command);
			cout << "	" << root << "." << endl;
		}

		else if (command[0] == "sin")
		{
			double sine = sin(command);
			cout << "	" << sine << "." << endl;
		}

		else if (command[0] == "cos")
		{
			double cossine = cos(command);
			cout << "	" << cossine << "." << endl;
		}

		else if (command[0] == "tan")
		{
			double tangent = tan(command);
			cout << "	" << tangent << "." << endl;
		}

		else if (command[0] == "asin")
		{
			double asine = asin(command);
			cout << "	" << asine << "." << endl;
		}

		else if (command[0] == "acos")
		{
			double acossine = acos(command);
			cout << "	" << acossine << "." << endl;
		}

		else if (command[0] == "atan")
		{
			double atangent = atan(command);
			cout << "	" << atangent << "." << endl;
		}

		else if (command[0] == "cvt")
		{
			digitsConverter(command);
		}

		//MEM related
		//add mem
		else if (varExists(var, command[0]) && command.size() == 2)
		{
			if (isNumber(command[1]))
			{
				vector<string>::iterator it = find(var.begin(), var.end(), command[0]);

				int index = distance(var.begin(), it);

				addMem(command, index);
				cout << "	" << command[0] << " = " << command[1] << endl;
				printlang(LANG_OK);
			}
			else
			{
				printlang(LANG_ERROR, MSG01_NUMCHECKER);
				goto beg;
			}
		}

		//mem functions
		else if (command[0] == "mem" && command.size() == 2)
		{
			if (command[1] == "list")
			{
				int i = 0;
				for (vector<string>::const_iterator it = var.begin(); it != var.end(); it++)
				{
					cout << "	" << *it << " = ";
					cout << mem[i] << endl;
					i++;
				}
			}
			else if (command[1] == "clear")
			{
				clearMem();
				printlang(LANG_TABBED, MSG03_MEMCLEARED);
			}
			else
			{
				printlang(LANG_TABBED, MSG02_BADMEMFUNC);
				goto beg;
			}
		}

		else if (command[0] == "cls")
		{
			#ifdef _WIN32
				system("cls");
			#else
				system("clear");
			#endif
		}

		else if (command[0] == "exit")
		{
			condition = false;
		}

		else if (command[0] == "help")
		{
			if (command.size() == 1)
			{
				printdic();
			}
		}

		else if (command[0] == "about")
		{
			if (command.size() == 1)
			{
				printabout();
			}
		}

		else
		{
			printlang(LANG_ERROR, MSG00_INVALIDCOM);
			goto beg;
		}
		
	}
	
	printlang(LANG_NORMAL, MSG04_GOODBYEAPP);
}