#include"Polynomial.h"

Polynomial::Polynomial()
{
	Term temp;
	while (cin >> temp)
	{
		terms.push_back(temp);
	}
	sort();
}

void Polynomial::sort()
{
	list<Term>::iterator head = terms.begin();
	while (head != terms.end())
	{
		Term smallest = *head;
		for (list<Term>::iterator itr = terms.begin(); itr != terms.end(); ++itr)
		{
			if (smallest > *itr)
				smallest = *itr;
		}
		swap(smallest, *head);
		++head;
	}
}

void Polynomial::clear()
{
	terms.clear();
}

bool Polynomial::is_empty()
{
	return(terms.empty());
}

Polynomial operator +(Polynomial& lhs, Polynomial& rhs)
{
	Polynomial sum;
	list<Term>::iterator itr1 = lhs.terms.begin();
	list<Term>::iterator itr2 = rhs.terms.begin();
	while (itr1 != lhs.terms.end() && itr2 != rhs.terms.end())
	{
		if (*itr1 == *itr2)
			sum.terms.push_back(*itr1 + *itr2);
		else if (*itr1 > *itr2)
		{
			sum.terms.push_back(*itr1);
			++itr1;
		}
		else
		{
			sum.terms.push_back(*itr2);
			++itr2;
		}
	}
	if (itr1 != lhs.terms.end() && itr2 == rhs.terms.end())
	{
		sum.terms.push_back(*itr1);
		++itr1;
	}
	else if (itr1 == lhs.terms.end() && itr2 != rhs.terms.end())
	{
		sum.terms.push_back(*itr2);
		++itr2;
	}
	return sum;
}

ostream& operator<<(ostream& os, const Polynomial& P)
{
	list<Term>::const_iterator itr = P.terms.begin();
	os << *itr;
	++itr;
	while (itr != P.terms.end())
	{
		if (itr->ispositive())
			os << '+' << *itr;
		else if (itr->ispositive())
			os << *itr;
		++itr;
	}
	return os;
}
istream& operator>>(istream& is, Polynomial& P)
{
	Term temp;
	while (cin >> temp)
	{
		P.terms.push_back(temp);
	}
	P.sort();
	return is;
}

