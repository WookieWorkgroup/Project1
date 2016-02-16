/*********************************************



Name:			Joshua Neustrom, jwnf7b@mail.umkc.edu, 10227835

Course:			CS303
Program:		Project1 (Wookie Workgroup)
Team:			Team1
Due Date:		22 Feb 2016
Description:	Polynomial Tool
Inputs:			User given polynomial
Outputs:		Result of polynomial adddition sorted by exponet with terms simplified

Error Handling:
1)

Algorithm:
1) User interface
2) Option 1 - Ask for polynomial
- Parse
- Sort
- Combine terms
- Store as double linked list
3) Option 2 - Display last polynomail
4) Option 3 - Enter new polynomial (repeat option 1 process
5) Option 4 - Add polynomials
- Sort result
- Store Result
6) Option 5 - Display Result
7) Option 6 - Exit
8) Done and Done

Assumptions:
1) Only x variables used
2) No history stored past the last polynomial
3) Polynomials are sorted and simplified
4) Wookies rule

*********************************************/

#include <iostream>
#include <string> 
#include "Term.h"
#include "Polynomial.h"

using namespace std;

void displayMenu();
Polynomial getPolynomial(Polynomial p);
void clearScreen();

int main()
{
	while (true)
	{
		displayMenu();
	}
}

void displayMenu()
{
	Polynomial p1, p2, result;
	int userSelection(-1);
	cout << "Please select one: \n\n";
	cout << "1:\tEnter Polynomial One\n";
	cout << "2:\tEnter Polynomial Two\n";
	cout << "3:\tAdd Polynomials\n";
	cout << "4:\tDisplay Polynomial One\n";
	cout << "5:\tDisplay Polynomial Two\n";
	cout << "6:\tClear entries\n";
	cout << "7:\tExit\n\n";
	cin >> userSelection;
	
	switch (userSelection)
	{
	case 1:
		cout << "Enter the first polynomial: ";
		getPolynomial(p1);
		cout << endl << endl;
		break;
	case 2:
		cout << "Enter the second polynomial: ";
		getPolynomial(p2);
		cout << endl << endl;
		break;
	case 3:
		if (p1.is_empty()) cout << "Polynomial One is empty, please enter a value before you add\n";
		if (p2.is_empty()) cout << "Polynomial Two is empty, please enter a value before you add\n";
		else
		{
			result = p1 + p2;
			cout << "The result is: " << result << endl;
		}
		break;
	case 4:
		if (p1.is_empty()) cout << "Polynomial One is empty, please enter a value before you add\n";
		else cout << "Polynomial one is " << p1 << endl;
		break;
	case 5:
		if (p2.is_empty()) cout << "Polynomial Two is empty, please enter a value before you add\n";
		else cout << "Polynomial two is " << p2 << endl;
		break;
	case 6:
		p1.clear();
		p2.clear();
		result.clear();
		cout << "Entries cleared\n\n";
		break;
	case 7:
		exit(0);
	default:
		cout << "Invalid menu option\n\n";
	}
}
Polynomial getPolynomial(Polynomial p)
{
	string s;
	Term temp;
	string line;

	list<Term> terms;
	list<string> strings;
	cin.ignore();
	getline(cin, line);
	if (line.find('-') != string::npos)line.insert(line.find('-'), 1, '+');
	size_t prev(0), pos;
	while ((pos = line.find_first_of("+", prev)) != string::npos)
	{
		if (pos > prev)strings.push_back(line.substr(prev, pos - prev));
		prev = pos + 1;
	}
	if (prev < line.length())strings.push_back(line.substr(prev, std::string::npos));

	for (std::list<std::string>::const_iterator i = strings.begin(); i != strings.end(); ++i)
	{
		Term t(*i);
		p.addTerm(t);
	}
	return p;
}
void clearScreen()
{
	cout << string(100, '\n');
}

