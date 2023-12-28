#include "sourse.h"
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    List<int> lst;

    int numberscount;
    cin >> numberscount;
    for(int i = 0; i < numberscount; i++)
    {
        lst.push_back(rand() % 10);
    }

    cout << lst[1] << endl;

    for (int i = 0; i < lst.getsize(); i++)
    {
        cout << lst[i] << endl;
    }

    cout << "Элементов в списке" << lst.getsize() << endl;

    return 0;
}