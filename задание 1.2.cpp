#include <iostream>

int main()
{
    int a;
    int n;
    std::cin >> a;
    std::cin >> n;
    const double b = n * a;
    std::cout << "S = " << a * b << ", P = " << 2 * (a + b);
}

/*
*brief
*/