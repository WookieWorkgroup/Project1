#pragma once
#include<iostream>
#include<list>
#include"Term.h"
using namespace std;

class Polynomial
{
public:
	Polynomial();
	void sort();
	void clear();
	bool is_empty();
	void addTerm(Term t);
	friend Polynomial operator +(Polynomial& lhs, Polynomial& rhs);
	friend ostream& operator<<(ostream& os, const Polynomial& P);
	friend istream& operator>>(istream& is, Polynomial& P);
	
private:
	list<Term> terms;
};