#pragma once
#include<iostream>
#include<list>
#include"Term.h"
using namespace std;

class Polynomial
{
public:
	// Constructor
	Polynomial();

	// Functions to edit polynomials (sort, clear, empty)
	void sort();
	void clear();
	bool is_empty();

	// Add the polynomials
	void addTerm(Term t);

	// Overloaded operators for our epic convenience 
	friend Polynomial operator +(Polynomial& lhs, Polynomial& rhs);
	friend ostream& operator<<(ostream& os, const Polynomial& P);
	friend istream& operator>>(istream& is, Polynomial& P);
	
private:
	// A list of terms (ie a poly)
	list<Term> terms;
};