#include"Polynomial.h"
#include <sstream>

Polynomial::Polynomial()
{
	
}

// Clear the polynomial
void Polynomial::clear()
{
	terms.clear();
}


// Return true if empty or no terms
bool Polynomial::is_empty()
{
	return(terms.empty());
}


// Add a new term to the list in sorted order
void Polynomial::addTerm(Term t)
{
	bool found(false);
	for (list<Term>::iterator itr = terms.begin(); itr != terms.end(); ++itr)
	{
		if (t == *itr)
		{
			*itr = t + *itr;
			found = true;
		}
	}
	if (!found)terms.push_back(t);
	terms.sort();
}


// Add polynomials
Polynomial operator +(Polynomial& lhs, Polynomial& rhs)
{
	// Result and iterators for each operand
	Polynomial sum;
	list<Term>::iterator itr1 = lhs.terms.begin();
	list<Term>::iterator itr2 = rhs.terms.begin();

	// Go through and add terms
	while (itr1 != lhs.terms.end() && itr2 != rhs.terms.end())
	{
		
		// Add terms of same exponet
		if (*itr1 == *itr2)
		{
			sum.terms.push_back(*itr1 + *itr2);
			++itr1;
			++itr2;
		}
			

		// If exponet in lhs term is greater, add term to list
		else if (*itr1 > *itr2)
		{
			sum.terms.push_back(*itr1);
			++itr1;
		}

		// If exponet in rhs term is greater, add term to list
		else
		{
			sum.terms.push_back(*itr2);
			++itr2;
		}
	}

	// and the remainder of the lhs
	if (itr1 != lhs.terms.end() && itr2 == rhs.terms.end())
	{
		sum.terms.push_back(*itr1);
		++itr1;
	}

	// add the remainder of the rhs
	else if (itr1 == lhs.terms.end() && itr2 != rhs.terms.end())
	{
		sum.terms.push_back(*itr2);
		++itr2;
	}

	// Sort the result
	sum.terms.sort();

	// Bye
	return sum;
}


// Output a list of polys by seperating positive terms with a +
ostream& operator<<(ostream& os, const Polynomial& P)
{
	list<Term>::const_iterator itr = P.terms.begin();
	os << *itr;
	++itr;

	// Go through terms
	while (itr != P.terms.end())
	{
		if (itr->ispositive()) os << "+";
		os << *itr;
		++itr;
	}

	// Bye
	return os;
}


// Read in a term
istream& operator>>(istream& is, Polynomial& P)
{
	Term temp;
	cin >> temp;
	cout << temp;

	// Put term into the list
	P.terms.push_front(temp);

	// Sort list again
	P.terms.sort();

	// Bye
	return is;
}

