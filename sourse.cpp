#include <iostream>
#include <string>
using namespace std;

/*
* односвязный список
*/

template<typename T> class List
{
public:
    List();
    ~List();

    void pop_front();
    void push_back(T data); /*добавить элемент в конец списка*/
    void clear();
    int getsize() {return size;}; /*возвращает количество элементов в списке*/
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
        Node(T data, Node *pNext = nullptr) /*указатель на следующий элемент по умолчанию указывает на nullprt, потому что pNext последнего элемента будет null*/ 
        {
            this->data = data; /*присваивание входящих параметров соответсвующим полям*/
            this->pNext = pNext;
        }
    };
    int size; /*количество элементов*/
    Node<T> *head; /*указатель на начало списка*/
};

template<typename T>
List<T>::List(size{0}, head{nullptr}) /*конструкто*/

template<typename T>
List<T>::~List() /*диструктор*/
{   
    clear();
}

template<typename T>
void List<T>::pop_front()
{
    Node<T> *temp = head;
    head = head->pNext;
    delete temp;
    --size;
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

    ++size;
}

template<typename T>
void List<T>::clear()
{
    while (size)
    {
        pop_front();
    }
    
}

template<typename T>
void List<T>::insert(T data , int index)
{

    if(index==0)
    {
        push_front(data);
    }
    else
    {
        Node<T> *previous = this->head;

        for (int i = 0; i < index - 1; ++i)
        {
            previous = previous->pNext;
        }

        previous->pNext = new Node<T>(data, previous->pNext);

        ++size;
    }
}

template<typename T>
void List()::pop_back()
{
    removeAt(size - 1);
}

template<typename T>
void List()::removeAt(int index)
{
    if(index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T> *previous = this->head;
        for (int i = 0; i < index - 1; ++i)
        {
            previous = previous->pNext;
        }

        Node<T> *toDelete = previous->pNext;

        previous->pNext = toDelete->pNext;

        delete toDelete;
        --size;
    }
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
        ++counter;
    }
}

template<typename T>
void List<T>::push_front(T data)
{
    head = new Node<T>(data, head);
    ++size;
}

int main()
{
    setlocale(LC_ALL, "ru");

    List<int> lst;
    lst.push_back(57);
    lst.push_back(9);
    lst.push_back(17);

    /*int numberscount;
    cin >> numberscount;
    for(int i = 0; i < numberscount; i++)
    {
        lst.push_back(rand() % 10);
    }

    cout << lst[1] << endl;*/

    for (int i = 0; i < lst.getsize(); i++)
    {
        cout << lst[i] << endl;
    }

    /*cout << endl << "Элементов в списке" << lst.getsize() << endl;

        lst.clear();

    cout << endl << "Элементов в списке" << lst.getsize() << endl;*/

    return 0;
}