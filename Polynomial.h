#pragma once
#include<iostream>
#include<list>
#include"Term.h"
using namespace std;

class polynomial
{
public:
	polynomial();
	friend polynomial operator +(const polynomial&lhs, const polynomial&rhs);
	friend ostream& operator<<(ostream& os, const polynomial& t);
	friend istream& operator>>(istream& is, polynomial& t);
	
private:
	list<Term> terms;
}