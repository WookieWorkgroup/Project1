#include "Term.h"

Term::Term(int c, int e)
{
	coefficient = c;
	exponent = e;
}

Term::Term(const Term &rhs)
{
	coefficient = rhs.coefficient;
	exponent = rhs.exponent;
}

void Term::operator =(const Term &rhs)
{
	coefficient = rhs.coefficient;
	exponent = rhs.exponent;
}

ostream& operator<<(ostream& os, const Term& t)
{
	os << t.coefficient << "X^" << t.exponent;
}

Term operator +(const Term&lhs, const Term&rhs)
{
	//Assumes exponents are checked to be the same before this function is called.
	return Term(lhs.coefficient + rhs.coefficient, rhs.exponent);
}

bool Term::operator > (Term &rhs)
{
	return exponent > rhs.exponent;
}

bool Term::operator >= (Term &rhs)
{
	return exponent >= rhs.exponent;
}

bool Term::operator < (Term &rhs)
{
	return exponent < rhs.exponent;
}

bool Term::operator <= (Term &rhs)
{
	return exponent <= rhs.exponent;
}

bool Term::operator == (Term &rhs)
{
	return exponent == rhs.exponent;
}