#ifndef TERM_H
#define TERM_H

#include <iostream>

using namespace std;

class Term
{
public:
	Term(int c = 0, int e = 0);
	Term(const Term &rhs);
	void operator =(const Term &rhs);
	friend ostream& operator<<(ostream& os, const Term& t);
	friend Term operator +(const Term&lhs, const Term&rhs);
	bool operator > (Term &rhs);
	bool operator >= (Term &rhs);
	bool operator < (Term &rhs);
	bool operator <= (Term &rhs);
	bool operator == (Term &rhs);
private:
	int coefficient;
	int exponent;
};

#endif