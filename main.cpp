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

using namespace std;

int main()
{
	//Added in some quick tests to make sure that Term.h and Term.cpp work as expected...
	//All functions work, feel free to delete whenever

	Term a(1, 4);
	Term b(2, 3);
	Term c(3, 2);
	Term d(4, 2);

	//Greater than check
	cout << "Expected: 1\tActual: " << (a > b) << endl;
	cout << "Expected: 0\tActual: " << (b > a) << endl;
	cout << "Expected: 0\tActual: " << (c > d) << endl;

	//Less than check
	cout << "Expected: 0\tActual: " << (a < b) << endl;
	cout << "Expected: 1\tActual: " << (b < a) << endl;
	cout << "Expected: 0\tActual: " << (c < d) << endl;

	//Equal to check
	cout << "Expected: 0\tActual: " << (a == b) << endl;
	cout << "Expected: 1\tActual: " << (c == d) << endl;

	//I assume >= and <= work if the above three work.

	//Addition check
	cout << "Expected: 7X^2\tActual: " << (c+d) << endl;

	system("pause");
	return 0;
}