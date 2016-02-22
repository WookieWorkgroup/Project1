#include "Term.h"

// Default constructor
Term::Term(int c, int e)
{
	coefficient = c;
	exponent = e;
}

// Copy Constructor
Term::Term(const Term &rhs)
{
	coefficient = rhs.coefficient;
	exponent = rhs.exponent;
}

// Take a string and extract coef and exponent
Term::Term(string s)
{
	// Variable for neg or pos term
	int negMult(1);

	// Initial term values
	exponent = 0;
	coefficient = 0;

	// String variables for reading user entered string
	stringstream ss;
	char c;
	string::size_type sz;

	// If find -, remove and make term coeff negative
	if (s[0] == '-')
	{
		s.erase(0, 1);
		negMult = -1;
	}

	c = s[0];
	
	// Put the coef into the string streams
	while (c != '^' && s != "")
	{
		c = s[0];
		// When see X, we know exponent is at least 1
		if (c == 'X' || c == 'x')
			exponent = 1;
		ss << c;
		s.erase(0, 1);
	}
	// Set a coef
	try{
		coefficient = negMult * stoi(ss.str(), &sz);
	}
	
	// Failed so is a -X
	catch (exception e)
	{
		exponent = 1;
		coefficient = negMult;
	}
	
	// Reset string stream
	ss.str("");
	c = s[0];

	//// Erase the ^ or X
	//if (c == 'X')
	//	s.erase(0, 1);
	//c = s[0];

	//if (c == '^')
	//	s.erase(0, 1);
	//c = s[0];
	
	// look for additional - or + with exponet
	if(!(s.find('-') == string::npos && s.find('+') == string::npos))
	{
		while (c != '+' && c != '-' && c != '\n')
		{
			c = s[0];
			ss << c;
			s.erase(0, 1);
		}
	}

	// Case where set number after X^ as the exponet
	else if (s != "")
	{
		ss.str(s);
		exponent = stoi(ss.str(), &sz);
	}

	// Case where term was X with no exponet
	else if (exponent == 1)
		return;

	// Case where only a ceof and no X
	else
		exponent = 0;
}

void Term::operator =(const Term &rhs)
{
	coefficient = rhs.coefficient;
	exponent = rhs.exponent;
}

ostream& operator<<(ostream& os, const Term& t)
{
	//make sure that if the coefficient is 1 or -1, it just show the X with exponent
	if (t.coefficient == 1)
	{
		if (t.exponent > 1)
			os << "X^" << t.exponent;
		else if (t.exponent == 1)
			os << "X";
		else
			os << t.coefficient;
	}
	else if (t.coefficient == -1)
	{
		if (t.exponent > 1)
			os << '-' << "X^" << t.exponent;
		else if (t.exponent == 1)
			os << '-' << "X";
		else
			os << t.coefficient;
	}
	else
	{
		if (t.exponent > 1)
			os << t.coefficient << "X^" << t.exponent;
		else if (t.exponent == 1)
			os << t.coefficient << "X";
		else
			os << t.coefficient;
	}
	return os;
}
istream& operator>>(istream& is, Term& t)
{
	int negMult(1), coeff(0), exp(0);
	stringstream ss;
	
	char c = is.get();


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


// Addition of two terms by adding coeffecients
Term operator +(const Term&lhs, const Term&rhs)
{
	//Assumes exponents are checked to be the same before this function is called.
	return Term(lhs.coefficient + rhs.coefficient, rhs.exponent);
}


// Reverse overload to allow for sorting with largest exponet term first
bool Term::operator > (Term &rhs)
{
	return exponent < rhs.exponent;
}
bool Term::operator >= (Term &rhs)
{
	return exponent <= rhs.exponent;
}
bool Term::operator < (Term &rhs)
{
	return exponent > rhs.exponent;
}
bool Term::operator <= (Term &rhs)
{
	return exponent >= rhs.exponent;
}

// Compare equality of individual term (used in addition of two polys)
bool Term::operator == (Term &rhs)
{
	return exponent == rhs.exponent;
}

bool Term::ispositive()const
{
	if (coefficient > 0)return true;
	else return false;
}

bool Term::isnegative()const
{
	if (coefficient < 0)return true;
	else return false;
}
bool Term::iszero()const
{
	if (coefficient == 0)return true;
	else return false;
}