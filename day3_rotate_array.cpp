// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>

void rota(std::vector<int> &, int);

int main()
{
	std::vector<int> temp{ 1, 2, 3 };
	int val = 1;
	rota(temp, val);
	std::cin.get();
    return 0;
}

void rota(std::vector<int>& buff, int chunk) {
	std::queue<int> temp;
	if (buff.size()) {
		while (chunk--) {
			int temp = buff.back();
			buff.pop_back();
			buff.insert(buff.begin(),temp);
		}
		for (int i : buff) {
			std::cout << i << std::endl;
		}
	}
}
