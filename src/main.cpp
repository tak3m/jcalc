#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "jmath.h"
#include "langldr.h"

using namespace std;

int main()
{
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
			cout << "	? Invalid command" << endl;
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

		//MEM related
		//add mem
		else if (varExists(var, command[0]) && isNumber(command[1]) && command.size() == 2) //error here, vector out of range
		{
			vector<string>::iterator it = find(var.begin(), var.end(), command[0]);

			int index = distance(var.begin(), it);

			addMem(command, index);
			cout << "	" << command[0] << " = " << command[1] << endl;
			cout << "	OK." << endl;
		}

		//list mem
		else if (command[0] == "mem" && command[1] == "list" && command.size() == 2)
		{
			int i = 0;
			for (vector<string>::const_iterator it = var.begin(); it != var.end(); it++)
			{
				cout << "	" << *it << " = ";
				cout << mem[i] << endl;
				i++;
			}
		}

		//clear mem
		else if (command[0] == "mem" && command[1] == "clear" && command.size() == 2)
		{
			clearMem();
			cout << "	Memory cleared." << endl;
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

		else
		{
			cout << "	? Invalid command" << endl;
			goto beg;
		}
		
	}
	
	cout << "Application ended successfully." << endl;
}
