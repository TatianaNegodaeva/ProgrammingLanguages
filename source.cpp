#include "source.h"
using namespace std;

template<typename T>
List<T>::List() : size(0), head(nullptr) {} /*конструктор*/

template<typename T>
List<T>::~List() /*деструктор*/
{   
    if (head == nullptr)
    {
        return; 
        Node* temp = head;
        head = head->next;
        delete temp;
        --size;
    }
}

template<typename T>
void List<T>::push_back(T data) /*вставить элемент в конец списка*/
{
    if (head == nullptr) /*если список пустой*/
    {
        head = new Node(data); /*создаём новый элемент и передать в конструктор данные*/
    }
    else /*если список не пустой*/
    {
        Node* current = head;
        while (current->next != nullptr) /*если указатель на следующий элемент не нулевой*/
        {
            current = current->next;
        }
        current->next = new Node(data);
    }
++size;
}

template<typename T>
void List<T>::insert(T data, int index)
{
    if (index > size) 
    {
        throw std::out_of_range("Index out of range"); // Правильный выброс исключения.
    }
    if(index == 0)
    {
        push_front(data);
    }
    else
    {
        Node* previous = head;

        for (int i = 0; i < index - 1; ++i)
        {
            previous = previous->next;
        }

        Node* newNode = new Node(data, previous->next);
        previous->next = new Node(data, previous->next);
        ++size;
    }
}

// template<typename T>
// T& List<T>::operator[](const int index)
// {
//     if (index < 0 || index >= size)
//     {
//         throw std::out_of_range("Index out of range");
//     }
    
    
//     if(index == 0)
//     {
//         push_front(data);
//     }
//     else
//     {
//         Node* previous = head;

//         for (int i = 0; i < index - 1; ++i)
//         {
//             previous = previous->next;
//         }

//         previous->next = new Node(data, previous->next);

//         ++size;
//     }
// }

template<typename T>
void List<T>::pop_back()
{
    removeAt(size - 1);
}

template<typename T>
void List<T>::removeAt(int index)
{
    if(index == 0)
    {
        if (head == nullptr)
        {
            return; 
            Node* temp = head;
            head = head->next;
            delete temp;
            --size;
        }     
    }
    else
    {
        Node* 
        previous = head;
        for (int i = 0; i < index - 1; ++i)
        {
            previous = previous->next;
        }

        Node* toDelete = previous->next;

        previous->next = toDelete->next;

        delete toDelete;
        --size;
    }
}

template<typename T>
void List<T>::push_front(T data)
{
    head = new Node(data, head);
    ++size;
}