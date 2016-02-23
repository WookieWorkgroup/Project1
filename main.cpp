/*********************************************

Name:			Joshua Neustrom, jwnf7b@mail.umkc.edu, 10227835

Course:			CS303
Program:		Project1 (Wookie Workgroup)
Team:			Team1
Due Date:		22 Feb 2016
Description:	Polynomial Tool
Inputs:			User given polynomial
Outputs:		Result of polynomial adddition sorted by exponet with terms simplified

*********************************************/

#include <iostream>
#include <string> 
#include "Term.h"
#include "Polynomial.h"

using namespace std;

// Functions for the menu
void displayMenu(Polynomial& p1, Polynomial& p2, Polynomial& result);
void clearScreen();

// Gets user input and turns it into a polynomial
Polynomial getPolynomial(Polynomial& p);


int main()
{
	Polynomial p1, p2, result;

	// Continious display of menu
	while (true)
	{
		displayMenu(p1, p2, result);
	}
}


// A glorious menu and user interface
void displayMenu(Polynomial& p1, Polynomial& p2, Polynomial& result)
{
	// My choices
	int userSelection(-1);
	cout << "Please select one: \n\n";
	cout << "1:\tEnter Polynomial One\n";
	cout << "2:\tEnter Polynomial Two\n";
	cout << "3:\tAdd Polynomials\n";
	cout << "4:\tDisplay Polynomial One\n";
	cout << "5:\tDisplay Polynomial Two\n";
	cout << "6:\tDisplay Result\n";
	cout << "7:\tClear entries\n";
	cout << "8:\tExit\n\n";

	// Filter input so program accepts single digits only
	while (!(cin >> userSelection))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// Warn the user about an improper input
		cout << endl << "Single digits only" << endl;
		cout << "Make another selection: ";
	}
	
	// What happens when making a choice
	switch (userSelection)
	{
	// Give me poly1
	case 1:
		cout << endl << endl;
		cout << "Enter the first polynomial: ";

		// See if the polynomial is poperly entered
		try{
			getPolynomial(p1);
			cout << "Polynomial one successfully entered\n";
		}

		// Bad input, try again
		catch (exception e)
		{
			cout << endl << endl;
			cout << "Incorrect polynomial formatting entered, use formatting like 3X^3+1" << endl;
		}

		cout << endl << endl;
		break;

	// Give me poly2
	case 2:
		cout << endl << endl;
		cout << "Enter the second polynomial: ";

		// See if the polynomial is poperly entered
		try{
			getPolynomial(p2);
			cout << "Polynomial two successfully entered\n";
		}

		// Try again
		catch (exception e)
		{
			cout << endl << endl;
			cout << "Incorrect polynomial formatting entered, use formatting like 3X^3+1" << endl;
		}
		cout << endl << endl;
		break;
	
	// Add the polys
	case 3:
		cout << endl << endl;
		if (p1.is_empty()) cout << "Polynomial One is empty, please enter a value before you add\n";
		if (p2.is_empty()) cout << "Polynomial Two is empty, please enter a value before you add\n";
		else
		{
			result = p1 + p2;
			cout << "The result is: " << result << endl;
		}
		break;

	// Show what user entered for poly1
	case 4:
		cout << endl << endl;
		if (p1.is_empty()) cout << "Polynomial One is empty, please enter a value before you add\n";
		else cout << "Polynomial one is " << p1 << endl;
		break;

	// Show what user entered for poly2
	case 5:
		cout << endl << endl;
		if (p2.is_empty()) cout << "Polynomial Two is empty, please enter a value before you add\n";
		else cout << "Polynomial two is " << p2 << endl;
		break;

		// Show what user entered for poly2
	case 6:
		cout << endl << endl;
		if (result.is_empty()) cout << "No result found, please add some polynomials together\n";
		else cout << "Result of the last addition was " << result << endl;
		break;

	// Reset all polys
	case 7:
		p1.clear();
		p2.clear();
		result.clear();
		cout << endl << endl;
		cout << "Entries cleared\n\n";
		break;

	// Bah bye
	case 8:
		exit(0);

	// Bad choice, try that again
	default:
		cout << endl << endl;
		cout << "Invalid menu option" << endl;
		break;
	}
}


// Gets user input and turns it into a polynomail
Polynomial getPolynomial(Polynomial& p)
{
	p.clear();
	
	// Temp term to put into a list
	Term temp;

	// Line of input poly from user 
	string line;

	// Lists of terms and strings to build a poly
	list<Term> terms;
	list<string> strings;

	// User input
	cin.ignore();
	getline(cin, line);

	// Put + in front of any - as a delimiter for terms in a poly
	int stringSearchPosition(0);
	while (line.find('-', stringSearchPosition) != string::npos)
	{
		line.insert(line.find('-', stringSearchPosition), 1, '+');
		stringSearchPosition = line.find('-', stringSearchPosition) + 1;
	}

	// Position markers
	size_t prev(0), pos;

	// Break up the user input into substrings with + as the delimeter of terms
	while ((pos = line.find_first_of("+", prev)) != string::npos)
	{
		if (pos > prev)strings.push_back(line.substr(prev, pos - prev));
		prev = pos + 1;
	}

	// Take care of the end of the line
	if (prev < line.length())strings.push_back(line.substr(prev, std::string::npos));

	// Put the list of substrings into terms then into a poly
	for (std::list<std::string>::const_iterator i = strings.begin(); i != strings.end(); ++i)
	{
		Term t(*i);
		p.addTerm(t);
	}

	// Return the poly
	return p;
}

// Clear what the user sees on the screen
void clearScreen()
{
	system("pause");
	cout << string(100, '\n');
}

