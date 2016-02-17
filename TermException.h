#pragma once

#include <iostream>
#include <string>

using namespace std;
class TermException
{
public:
	// Create a exception with a message
	TermException(const string& M = " Exception") { message = M; }

	// Give the message
	string what() const { return message; }

private:
	string message;
};