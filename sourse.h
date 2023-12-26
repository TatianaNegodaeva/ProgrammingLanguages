#include <iostream>
#include <string>
using namespace std;

/*
* односвязный список
*/

template<typename T> class List
{
public:
    List()=default;
    ~List();

    T peek()
    void pop_front();
    void push_back(T data); /*добавить элемент в конец списка*/
    void clear();
    int getsize() {return size_t;}; /*возвращает количество элементов в списке*/
    T& operator[](const int index); /*по указанному индексу возвращает данные из списка*/

    void push_front(T data);
    void insert(T value, int index);
    void removeAt(int index);
    void pop_back();

private:

    template<typename T>
    class Node
    {
    public:
        Node *pNext; /*указатель типа node на следющий элемент*/
        T data;

        /*констуктор*/ 
        Node(T data, Node *pNext = nullptr) : data(data), next(pNext) /*указатель на следующий элемент по умолчанию указывает на nullprt, потому что pNext последнего элемента будет null*/ 
        {
            this->data = data; /*присваивание входящих параметров соответсвующим полям*/
            this->pNext = pNext;
        }
    };
    int size_t; /*количество элементов*/
    Node<T> *head; /*указатель на начало списка*/
};
