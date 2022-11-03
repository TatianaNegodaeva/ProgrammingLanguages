#include <iostream>

int main()
{
	int a;
	int b;
	std::cin >> a;
	std::cin >> b;
	if (((a + b) / 2) % 2 == 0)
	{
		std::cout << "среднее арифметическое этих чисел является целым числом";
	}
	else
	{
		std::cout << "среднее арифметическое этих чисел не является целым числом";
	}
}

/*
*brief 
*/