#ifndef TERM_H
#define TERM_H

#include <iostream>
#include <sstream>

using namespace std;

class Term
{
public:
	//Constructors
	Term(int c = 0, int e = 0);
	Term(const Term &rhs);
	Term(string s);
	
	//Getters & Setters
	int getCoefficient() { return coefficient; }
	int getExponent() { return exponent; }

	void setCoefficient(int c){ coefficient = c; }
	void setExponent(int e){ exponent = e; }

	// Is it positive/negative
	bool ispositive()const;
	bool isnegative()const;
	bool iszero()const;

	//Overloaded operators
	void operator =(const Term &rhs);
	friend ostream& operator<<(ostream& os, const Term& t);
	friend istream& operator>>(istream& is, Term& t);
	friend Term operator +(const Term&lhs, const Term&rhs);
	bool operator > (Term &rhs);
	bool operator >= (Term &rhs);
	bool operator < (Term &rhs);
	bool operator <= (Term &rhs);
	bool operator == (Term &rhs);

private:
	// Varialbes for power and coef of a term
	int coefficient;
	int exponent;
};



#endif
