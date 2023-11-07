#include <stdexcept>
#include "Dequeue.h"


bool Deque::isFull()
{
    return ((front == 0 && rear == size - 1)
            || front == rear + 1);
}
 
bool Deque::isEmpty() { return (front == -1); }

Deque::Deque(int size)
    : front(-1), rear(0), size(size), arr(new int[size])
{}

Deque::~Deque()
{
    delete[]arr;
}

Deque::Deque(const Deque &deque)
{
    this->arr = deque.arr;
    this->front = deque.front;
    this->rear = deque.rear;
    this->size = deque.size;
}

Deque::Deque(Deque &&deque) noexcept
{
    swap(*this, deque);
}

Deque &Deque::operator=(const Deque &other)
{
    if (this==&other)
    {
        return *this;
    }
   Deque temp(other);
   swap(*this, temp);
   return *this;
}

Deque &Deque::operator=(Deque &&other) noexcept
{
    if (this==&other)
    {
        return *this;
    }
    delete[] arr;
   swap(*this, other);
   return *this;
}

void Deque::insertfront(int key)
{
    if (isFull())
        throw std::overflow_error("Слишком много элементов!");
 
    if (front == -1) {
        front = 0;
        rear = 0;
    }
 
    else if (front == 0)
        front = size - 1;
 
    else
        front = front - 1;
 
    arr[front] = key;
}
 
void Deque ::insertrear(int key)
{
    if (isFull())
        throw std::overflow_error("Слишком много элементов!");

 
    if (front == -1) {
        front = 0;
        rear = 0;
    }
 
    else if (rear == size - 1)
        rear = 0;
    else
        rear = rear + 1;
 
    arr[rear] = key;
}
 
void Deque ::deletefront()
{
    if (isEmpty()) throw std::overflow_error("Нет элементов!");
 
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else
        if (front == size - 1)
        front = 0;
 
    else
        front = front + 1;
}
 
void Deque::deleterear()
{
    if (isEmpty()) throw std::overflow_error("Нет элементов!");
 
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = size - 1;
    else
        rear = rear - 1;
}
 
int Deque::getFront()
{
    if (isEmpty()) throw std::overflow_error("Нет элементов!");

    return arr[front];
}
 
int Deque::getRear()
{
    if (isEmpty() || rear < 0) throw std::overflow_error("Нет элементов!");

    return arr[rear];
}

void swap(Deque &lha, Deque &rha)
{
    std::swap(lha.arr, rha.arr);
    std::swap(lha.front, rha.front);
    std::swap(lha.rear, rha.rear);
    std::swap(lha.size, rha.size);
}
