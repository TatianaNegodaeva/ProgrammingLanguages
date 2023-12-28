#include <iostream>
using namespace std;

template<typename T> class List
{
public:
    List();
    ~List();

    void push_back(T data); /*добавить элемент в конец списка*/
    int getsize() {return size;}; /*возвращает количество элементов в списке*/
    T& operator[](const int index); /*по указанному индексу возвращает данные из списка*/
    int getsize() const {return size;}
    void push_front(T data);
    void insert(T value, int index);
    void removeAt(int index);
    void pop_back();

private:

    class Node
    {
    public:
        Node *next; /*указатель типа node на следющий элемент*/
        T data;

        /*констуктор*/ 
        Node(T dataVal, Node *nextNode = nullptr) : data(dataVal), next(nextNode) {}
    };
    int size; /*количество элементов*/
    Node *head; /*указатель на начало списка*/
};
