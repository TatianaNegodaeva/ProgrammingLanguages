#include <cmath>
#include <iostream>

int main()
{
	const int a = 2.5;
	double x;
	std::cin >> x;
	if (x > a)
	{
		auto y = x * pow(x - a, 1.0 / 3);
		std::cout << y;
	}
	else
	{
		auto y = x * sin(a * x) ;
		std::cout << y;
	}
}

/*
*brief 
*/