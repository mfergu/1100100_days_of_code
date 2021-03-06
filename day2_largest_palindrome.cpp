// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

int lrgPld(int);
int genMax(int);
bool isPal(const int&);

int main()
{
	//isPal test
	/* 
	int temp1 = 323;
	isPal(temp1);
	*/
	//lrgPld test
	int temp2 = 2;
	lrgPld(temp2);
	std::cin.get();
    return 0;
}

//finds the largest palindrome for the product of two nums of max width n
int lrgPld(int n) {
	int max = genMax(n);
	std::vector <int> myPals {};

	for (int i = 0; i <= max; i++) {
		for (int j = max; j >= max - i; j--) {
			//std::cout << "max - i: " << max - i	<< " j: " << j << std::endl; //works
			int test = (max - i) * j;
			if (isPal(test)) {
				myPals.push_back(test);
			}
		}
	}
	//sort the vector
	std::sort(myPals.begin(), myPals.end());
	//return the largest element of the vector
	//std::cout << myPals[myPals.size() - 1]; //works
	return myPals[myPals.size()-1];
}

int genMax(int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		max += pow(10, i) * 9;
	}
	return max;
}

//returns if a number is a palindrome or not
bool isPal(const int &n) {
	std::string buff = std::to_string(n); //works
	int width = buff.size() - 1;
	int index = 0;
	do {
		if (buff[index] != buff[width]) { // works
			//std::cout << "not a pal!\n " << buff[index] << " does not equal " << buff[width] << std::endl;
			return false;
		}
	} while (index++ < width--); //works
	//std::cout << "is a pal!\n " << buff << std::endl;
	return true;
}