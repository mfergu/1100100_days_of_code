// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <string>
#include <math.h>
#include <bitset>

int intRev(int);
int main()
{
	std::string value;
	int temp1 = 12345;
	int temp2 = -12345;
	std::cout << intRev(temp1) << std::endl;
	std::cout << intRev(temp2) << std::endl;
	std::cin.get();
    return 0;
}

int intRev(int rev_me) {

	int revd = 0, width = 1, temp = 0;
	bool neg = false;

	if (rev_me < 0) {
		neg = true;
		rev_me *= -1;
	}

	temp = rev_me;
	while ( temp / 10 > 0) {
		++width;
		temp /= 10;
	}

	temp = rev_me;

	for (int i = 0; i < width; i++) {
		
		int buff = temp % 10;
		temp = temp / 10;
		revd += pow(10, (width - i - 1)) * buff;
	}

	if (neg) {
		return -revd;
	}
	return revd;
}