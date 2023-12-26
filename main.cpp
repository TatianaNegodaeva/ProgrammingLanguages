#include 'sourse.h'


int main()
{
    setlocale(LC_ALL, "ru");

    List<int> lst;
    lst.push_back(57);
    lst.push_back(9);
    lst.push_back(17);

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

    cout << endl << "Элементов в списке" << lst.getsize() << endl;

        lst.clear();

    cout << endl << "Элементов в списке" << lst.getsize() << endl;

    return 0;
}