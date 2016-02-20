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
	// Is the term there already
	bool found(false);

	// Add the term to the result
	for (list<Term>::iterator itr = terms.begin(); itr != terms.end(); ++itr)
	{
		if (t == *itr)
		{
			*itr = t + *itr;
			found = true;
		}
	}

	// Push result onto the poly
	if (!found)terms.push_back(t);

	// Sort
	terms.sort();
}


// Add polynomials
Polynomial operator +(Polynomial& lhs, Polynomial& rhs)
{
	// Result and iterators for each operand
	Polynomial sum;

	// Go through poly and add each term
	for (list<Term>::iterator itr1 = lhs.terms.begin(); itr1 != lhs.terms.end(); ++itr1)
	{
		sum.addTerm(*itr1);
	}
	for (list<Term>::iterator itr2 = rhs.terms.begin(); itr2 != rhs.terms.end(); ++itr2)
	{
		sum.addTerm(*itr2);
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
	if (!itr->iszero())os << *itr;
	++itr;

	// Go through terms
	while (itr != P.terms.end())
	{
		if (itr->ispositive())
		{
			os << "+";
			os << *itr;
		}
		else if (itr->isnegative())
		{
			os << *itr;
		}
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

