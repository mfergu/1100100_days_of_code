// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

bool checkParens(const vector< char> &);

int main()
{
	vector <char> buff { '(','(',')',')' };
	string solution;
	if (checkParens(buff)) {
		solution = "worked!";
	}
	else {
		solution = "failed!";
	}
	cout << buff.size() << endl;
	cout << solution << endl;
	cin.get();
    return 0;
}

bool checkParens(const vector < char> &buff) {

	vector <char> stack( buff.size());
	int index = 0;
	if (buff.size() < 1) {

		return true;
	}

	//increment through regex of parens
	for (const char &temp : buff) {
		
		//push to stack
		if (temp == '(') {
			stack.push_back('(');
		}
		//pop from stack
		else if (temp == ')') {
			if (stack.empty()) {
				cout << "empty stack!";
				return false;
			}
			else {
				stack.pop_back();
			}
		}

		if ( ( index == buff.size()) && ( !stack.empty() ) ) {
			cout << "too many open parens!";
			return false;
		}
		//increment index to compare to size of the stack in case of 
		//if more open parens than close parens
		++index;
	}
	return true;
}
