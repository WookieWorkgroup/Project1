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
//#include "Polynomial.h"

using namespace std;

void displayMenu();
Polynomial getPolynomial(Polynomial p);
void clearScreen();

int main()
{
	displayMenu();

	system("pause");
	return 0;
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
	cout << "6:\tClear entries\n\n";
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
		if (p1 is empty) cout << "Polynomial One is empty, please enter a value before you add\n";
		if (p2 is empty) cout << "Polynomial Two is empty, please enter a value before you add\n";
		else
		{
			result = p1 + p2;
			cout << "The result is: " << result << endl;
		}
		break;
	case 4:
		cout << "Polynomial one is " << p1 << endl;
		break;
	case 5:
		cout << "Polynomial two is " << p2 << endl;
		break;
	case 6:
		p1 = p2 = result = Polynomial();
		cout << "Entries cleared\n\n";
		break;
	default:
		cout << "Invalid menu option\n\n";
	}
}

Polynomial getPolynomial(Polynomial p)
{

}

void clearScreen()
{

}