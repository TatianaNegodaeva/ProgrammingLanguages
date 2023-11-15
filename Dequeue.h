#include <iostream>
using namespace std;

 
class Deque {
    int *arr;
    int front;
    int rear;
    int size;
 
public:
    Deque(int size);

    ~Deque();
    Deque(const Deque& deque);
    Deque(Deque&& deque) noexcept;

    Deque& operator=(const Deque& other);
    Deque& operator=(Deque&& other) noexcept;
 
    /**
     * @brief Добавить элемент вперёд деки
     * 
     * @param value Значение
     */
    void insertfront(int value);

    /**
     * @brief Добавить элемент в начало деки
     * 
     * @param value Значение
     */
    void insertrear(int value);

    /**
     * @brief Удалить первый элемент
     * 
     */
    void deletefront();

    /**
     * @brief Удалить последний элемент
     * 
     */
    void deleterear();

    /**
     * @brief Проверить нет ли пустых элементов
     * 
     * @return true Если нет пустых элементов
     * @return false Если есть пустые элементы
     */
    bool isFull();

    /**
     * @brief Проверить пустая ли дека
     * 
     * @return true Если все элементы пустые
     * @return false Если есть непустые элементы
     */
    bool isEmpty();

    /**
     * @brief Получить первый элемент
     * 
     * @return Первый элемент 
     */
    int getFront();

    /**
     * @brief Получить последний элемент
     * 
     * @return Последний элемент
     */
    int getRear();

    friend void swap(Deque& lha,Deque& rha);
};