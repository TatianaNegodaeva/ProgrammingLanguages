template<typename T>
class List
{
public:
    List();
    ~List();

    void push_back(T data); /*добавить элемент в конец списка*/
    int getsize() {return size;}; /*возвращает количество элементов в списке*/
    void push_front(T data);
    void insert(T value, int index);
    void removeAt(int index);
    void pop_back();

private:

    struct Node
    {
        Node* next;
        T data;

        explicit Node(const T data, Node* next = nullptr)
            : data{data}, next{next}
        {}
    };
    int size; /*количество элементов*/
    Node *head; /*указатель на начало списка*/
};
