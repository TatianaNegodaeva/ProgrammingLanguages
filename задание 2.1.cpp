#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

int main()
{
	int r;
	std::cin >> r;
	std::cout << "V = " << (4 * M_PI * pow(r, 3)) / 3 << ", S = " << 4 * M_PI * pow(r, 2);
}

/*
*brief 
*/