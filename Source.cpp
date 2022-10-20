#include <exception>
#include <random>
#include <string>
#include <iostream>

using namespace std;


/**
*\brief Пользовательский ввод выбора набора массива
*\param MANUAL Ручной ввод данных
*\param RANDOM Ввод данных с помощбю рандома
*/
enum class input_type
{
	MANUAL = 1,
	RANDOM
};

/**
*\brief Получение значения параметра массива (строки, столбцы)
*\param name_of_param Название параметра массива (строка, столбец)
*\throw Если введено отрицательное число
*\return Значение параметра
*/
size_t get_massive_param(string name_of_param);

/**
*\brief Проверяет номер строки на четность
*\param string Номер строки
*\return true если строка по номеру нечётная и false, если чётная
*/
bool is_string_not_even_and_not_first(const size_t string);

/**
*\brief Создание двумерного массива по заданным параметрам
*\param strings_count Колличество строчек в массиве
*\param columns_count Колличество столбцов в массиве
*\return Массив заполненый случайными числами
*/
int** create_two_dimensional_arr(const size_t strings_count, const size_t columns_count);

/**
*\brief Заполение массива случайными числами
*\param array Массив
*\param strings_count Колличество строчек в массиве
*\param column_count Колличество столбцов в массиве
*/
void array_random_fill(int** array, const size_t strings_count, const size_t columns_count);

/**
*\brief Заполение массива в ручную
*\param array Массив
*\param strings_count Колличество строчек в массиве
*\param columns_count Колличество столбцов в массиве
*/
void array_manual_fill(int** array, const size_t strings_count, const size_t columns_count);

/**
*\brief Поиск максимального по модолю элемента в массиве
*\param array Массив
*\param columns_count Колличество столбцов в массиве
*\return Максимальный по модулю элемент
*/
int get_max_element(int* array, const size_t columns_count);

/**
*\brief Возведение в квадрат всех чисел в массиве
*\param array Массив
*\param strings_count Колличество строчек в массиве
*\param columns_count Колличество столбцов в массиве
*/
void get_resault_1(int** array, int** new_array, const size_t strings_count, const size_t columns_count);

/**
*\brief Вставляет первую строчку после каждей нечетной
*\param array Массив
*\param strings_count Колличество строчек в массиве
*\param columns_count Колличество столбцов в массиве
*/
void get_resault_2(int** array, int** new_array, const size_t strings_count, const size_t columns_count);

/**
* \brief Вывод ответа на первую часть задания
*\param strings_count Колличество строчек в массиве
*\param columns_count Колличество столбцов в массиве
*/
void draw_answer(int** array, const size_t strings_count, const size_t columns_count);

/**
*\brief Удаление двухмерного массива
*\param strings_count Колличество строчек (массивов)
*/
void delete_array(int**& array, const size_t strings_count);

/**
* \brief вход в программу
* \return 0 При успехе
*/
int main()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		size_t strings_count = get_massive_param("Строк");
		size_t columns_count = get_massive_param("Столбцов");

		cout << "Метод заполнения массива\n" << static_cast<int>(input_type::MANUAL) << " - Ввод вручную\n"
			<< static_cast<int>(input_type::RANDOM) << " - Ввод рандомом\n";

		int user_choise = 0;
		cin >> user_choise;

		const auto choise = static_cast<input_type>(user_choise);
		int** array_default = create_two_dimensional_arr(strings_count, columns_count);

		switch (choise)
		{
		case input_type::MANUAL:
		{
			array_manual_fill(array_default, strings_count, columns_count);
			break;
		}
		case input_type::RANDOM:
		{
			array_random_fill(array_default, strings_count, columns_count);
			break;
		}
		default:
		{
			throw out_of_range("Invalid number");
		}
		}
		cout << "\n------------Изначальный массив----------" << endl;
		draw_answer(array_default, strings_count, columns_count);
		delete_array(array_default, strings_count);
	}
	catch (exception& err)
	{
		cout << err.what();
	}
	return 0;
}

bool is_string_not_even_and_not_first(const size_t string)
{
	return ((string != 0) && (string + 1) % 2 == 0);
}
size_t get_massive_param(string name_of_param)
{
	cout << name_of_param << ":";
	int param;
	cin >> param;
	if (param <= 1)
	{
		throw out_of_range("Вы ввели неверный параметр");
	}
	

	return param;
}
void array_random_fill(int** array, const size_t strings_count, const size_t columns_count)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> uniformIntDistribution(-100, 100);
	for (size_t string = 0; string < strings_count; string++) {
		for (size_t column = 0; column < columns_count; column++) {
			array[string][column] = uniformIntDistribution(gen);
		}
	}
}

void array_manual_fill(int** array, const size_t strings_count, const size_t columns_count)
{
	for (size_t string = 0; string < strings_count; string++) {
		for (size_t column = 0; column < columns_count; column++) {
			cout << "Номер " << string + 1 << "." << column + 1 << ": ";
			int user_input = 0;
			cin >> user_input;
			array[string][column] = user_input;
		}
	}
}
int** create_two_dimensional_arr(const size_t strings_count, const size_t columns_count)
{
	int** ptrarr = new int* [strings_count];
	for (size_t i = 0; i < strings_count; i++) {
		ptrarr[i] = new int[columns_count];
	}
	return ptrarr;
}

void draw_answer(int** array, const size_t strings_count, const size_t columns_count)
{
	for (size_t string = 0; string < strings_count; string++)
	{
		for (size_t column = 0; column < columns_count; column++)
		{
			cout << array[string][column] << "	";
		}
		cout << endl;
	}
}
void delete_array(int**& array, const size_t strings_count)
{
	for (size_t string = 0; string < strings_count; string++)
	{
		delete[] array[string];
	}
	delete[] array;
	array = nullptr;
}