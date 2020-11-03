#include <iostream>
#include <string>
#include <map>
#include "TuringMachine.h"
#include "Tape.h"

using namespace std;



string ToLower(string s)
{
	string t;
	for (auto ch : s)
	{
		t += tolower(ch);
	}
	return t;
}

bool IsNumber(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}
int main()
{
	string operation;
	cout << "---------------------------------------------------------------------------------------------------------" << endl;
	cout << "			Welcome to the Turing Machine Experience! " << endl;
	cout << "---------------------------------------------------------------------------------------------------------" << endl;
	while (true)
	{
		cout << "Select an operation you would like the Turing Machine to do: " << endl;
		cout << "1. Add" << endl;
		cout << "4. Quit" << endl;

		cin >> operation;

		operation = ToLower(operation);

		if (operation == "1" || operation == "add")
		{
			string num1;
			string num2;

			cout << "Input 2 SMALL (<15) Numbers (integers) that you would like to add. Separate inputs by a single space." << endl;

			cin >> num1 >> num2;
			// if valid input
			if (IsNumber(num1) && IsNumber(num2))
			{
				// convert s to i
				int n1 = atoi(num1.c_str());
				int n2 = atoi(num2.c_str());

				CTape tape(n1, n2);
				CTuringMachine machine(tape);
				tape.PrintTapeRepresentation();

				cout << "#########################################################################" << endl;
				cout << "A bit set to 0 is the separation of number 1 and number 2." << endl;
				cout << "A bit set to 1 is part of the final representation of the number. " << endl;
				cout << "A bit set to 2 is used as a marker for addition." << endl;
				machine.PrintAddStateTable();
				cout << "#########################################################################" << endl;

				machine.Add();
			}

			else
			{
				if (!IsNumber(num1))
				{
					cout << "Invalid input \"" << num1 << "\"." << endl;
				}
				if (!IsNumber(num2))
				{
					cout << "Invalid input \"" << num2 << "\"." << endl;
				}
			}
		}

		//else if (operation == "2" || operation == "subtract")
		//{

		//}

		//else if (operation == "3" || operation == "multiply")
		//{

		//}
		else if (operation == "4" || operation == "quit")
		{
			cout << "Thanks for using the Turing Machine Simulator!" << endl;
			break;
		}

		else
		{
			cout << "Unrecognized operation \"" << operation << "\". Please try again." << endl << endl;;
		}

	}
	return 0;
}