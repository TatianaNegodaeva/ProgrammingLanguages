
template<typename T>
List<T>::List() : size{0}, head{nullptr} /*конструкто*/

template<typename T>
List<T>::~List() /*деструктор*/
{   
    clear();
}

template<typename T>
void List<T>::pop_front()
{
    Node<T> *temp = head;
    head = head->pNext;
    delete temp;
    --size_t;
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

    ++size_t;
}

template<typename T>
void List<T>::clear()
{
    while (size_t != 0)
    {
        pop_front();
    }
    
}

template<typename T>
void List<T>::insert(T data , int index)
{  
    if (index >= size) 
    {
        throw std::out << 'ошибка' << std::endl;
    }
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

        ++size_t;
    }
}

template<typename T>
void List()::pop_back()
{
    removeAt(size_t - 1);
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
        --size_t;
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
    ++size_t;
}