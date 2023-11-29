#include <iostream>
#include <string>
using namespace std;

/*
* односвязный список
*/

template<typename T>
class List
{
public:
    List();
    ~List();

    void push_back(T data);
    int GetSize() {return Size;}

    T& operator[](const int index);

private:

    template<typename T>
    class Node
    {
    public:
        Node *pNext; /*указатель типа node на следющий элемент*/
        T data;

        /*констуктор*/ 
        Node(T data = T(), Node *pNext = nullptr) /*указатель на следующий элемент по умолчанию указывает на nullprt, потому что pNext последнего элемента будет null*/ 
        {
            this->data = data; /*присваивание входящих параметров соответсвующим полям*/
            this->pNext = pNext;
        }
    };
    int Size; /*количество элементов*/
    Node<T> *head; /*указатель на начало списка*/
};

template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List()
{

}

template<typename T>
void List<T>::push_back(T data) /*вставить элемент в конец списка*/
{
    if (head == nullptr) /*если список пустой*/
    {
        head = new Node<T>(data); /*создаём новый элемент и передать в конструктор данные*/
    }
    else /*если список не пустой*/
    {
        Node<T> *current = this->head;
        while (current->pNext != nullptr) /*если указатель на следующий элемент не нулевой*/
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }

    Size++;
}

template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T> *current = this->head;
    while(current != nullptr)
    {
        if (counter == index) /*если счётчик равен нужному элементу*/
        {
            return current->data; /*вывести значение в искомом индексе*/
        }
        current = current->pNext; /*взять следующие значение*/
        counter++;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    List<int> lst;

    int numbersCount;
    cin >> numbersCount;
    for(int i = 0; i < numbersCount; i++)
    {
        lst.push_back(rand() % 10);
    }

    cout << lst.GetSize() << endl;
    cout << lst[1] << endl;
    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << endl;
    }

    return 0;
}