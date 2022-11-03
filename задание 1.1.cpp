#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

 double GetA(const double x, const double y)
{
	 return ((2 * cos(x - M_PI / 6)) / (static_cast<double>(1 / 2) + pow(sin(y), 2)));
}

double GetB(const double z)
{
	return (1 + ((pow(z, 2)) / (3 + pow(z, 2) / 5)));
}

int main()
{
	const double x = 1.426;
	const double y = -1.22;
	const double z = 3.5;
	auto a = GetA(x, y);
	auto b = GetB(z);
	std::cout << "a = " << a << ", b = " << b;
}

/*
*brief 
*/