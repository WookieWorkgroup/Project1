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

Term::Term(string s)
{

	int negMult(1);
	stringstream ss;
	char c;
	string::size_type sz;

	if (s[0] == '+')s.erase(0,1);
	else if (s[0] == '-')
	{
		s.erase(0, 1);
		negMult = -1;
	}

	c = s[0];
	while (c != 'X')
	{
		c = s[0];
		ss << c;
		s.erase(0, 1);
	}

	coefficient = negMult * stoi(ss.str(), &sz);

	ss.str("");
	s.erase(0, 1);
	c = s[0];

	if(!(s.find('-') == string::npos && s.find('+') == string::npos))
	{
		while (c != '+' && c != '-' && c != '\n')
		{
			c = s[0];
			ss << c;
			s.erase(0, 1);
		}
	}
	else ss.str(s);
	exponent = stoi(ss.str(), &sz);
}

void Term::operator =(const Term &rhs)
{
	coefficient = rhs.coefficient;
	exponent = rhs.exponent;
}

ostream& operator<<(ostream& os, const Term& t)
{
	os << t.coefficient << "X^" << t.exponent;
	return os;
}
istream& operator>>(istream& is, Term& t)
{
	int negMult(1), coeff(0), exp(0);
	stringstream ss;
	
	char c = is.get();
	int val;

	if (c == '-')
	{
		negMult = -1;
		cout << "NEGATIVE\n";
	}
	else if (c == '+')
	{
		negMult = 1;
		cout << "POSITIVE\n";
	}
	else
	{
		//loop until we hit the x
		while (c != 'X')
		{
			ss << c;
			c = is.get();
		}

		//turn our string into an int
		string::size_type sz;
		coeff = stoi(ss.str(), &sz);
		coeff *= negMult;

		c = is.get(); //toss X
		c = is.get(); //toss ^
				
		//clear the input from the coefficient
		ss.str(string()); 

		//iterate until the end of the line or the next term
		while (c != '+' && c != '-' && c != '\n') 
		{
			ss << c;
			c = is.get();
		}
		
		//turn our string into an int
		exp = stoi(ss.str(), &sz);

		//modify the Term values
		t.coefficient = coeff; 
		t.exponent = exp;
	}
	return is;
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

bool Term::ispositive()const
{
	if (coefficient>0)
		return true;
	else
		return false;
	return false;
}