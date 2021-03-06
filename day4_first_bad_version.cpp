// day4_first_bad_version.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

bool isBadVersion(int);

//given n as the total size
int fbv(int, int);

int main()
{
	std::cout << "first bad version " << fbv(1, 20) << std::endl;

	std::cin.get();
    return 0;
}

int fbv(int first, int last) {
	int id = ((first + last) / 2);
	while (first < last) {
		if (!isBadVersion(id)) {
			return fbv(id + 1, last);
		}
		if (isBadVersion(id)) {
			return fbv(first, id - 1);
		}
	}
	return first;
}

bool isBadVersion(int bad) {
	//return bad >= 3;
	return bad >= 17;
}
