#include <exception>
#include <random>
#include <string>
#include <iostream>

using namespace std;


/**
*\brief ���������������� ���� ������ ������ �������
*\param MANUAL ������ ���� ������
*\param RANDOM ���� ������ � ������� �������
*/
enum class input_type
{
	MANUAL = 1,
	RANDOM
};

/**
*\brief ��������� �������� ��������� ������� (������, �������)
*\param name_of_param �������� ��������� ������� (������, �������)
*\throw ���� ������� ������������� �����
*\return �������� ���������
*/
size_t get_massive_param(string name_of_param);

/**
*\brief ��������� ����� ������ �� ��������
*\param string ����� ������
*\return true ���� ������ �� ������ �������� � false, ���� ������
*/
bool is_string_not_even_and_not_first(const size_t string);

/**
*\brief �������� ���������� ������� �� �������� ����������
*\param strings_count ����������� ������� � �������
*\param columns_count ����������� �������� � �������
*\return ������ ���������� ���������� �������
*/
int** create_two_dimensional_arr(const size_t strings_count, const size_t columns_count);

/**
*\brief ��������� ������� ���������� �������
*\param array ������
*\param strings_count ����������� ������� � �������
*\param column_count ����������� �������� � �������
*/
void array_random_fill(int** array, const size_t strings_count, const size_t columns_count);

/**
*\brief ��������� ������� � ������
*\param array ������
*\param strings_count ����������� ������� � �������
*\param columns_count ����������� �������� � �������
*/
void array_manual_fill(int** array, const size_t strings_count, const size_t columns_count);

/**
*\brief ����� ������������� �� ������ �������� � �������
*\param array ������
*\param columns_count ����������� �������� � �������
*\return ������������ �� ������ �������
*/
int get_max_element(int* array, const size_t columns_count);

/**
*\brief ���������� � ������� ���� ����� � �������
*\param array ������
*\param strings_count ����������� ������� � �������
*\param columns_count ����������� �������� � �������
*/
void get_resault_1(int** array, int** new_array, const size_t strings_count, const size_t columns_count);

/**
*\brief ��������� ������ ������� ����� ������ ��������
*\param array ������
*\param strings_count ����������� ������� � �������
*\param columns_count ����������� �������� � �������
*/
void get_resault_2(int** array, int** new_array, const size_t strings_count, const size_t columns_count);

/**
* \brief ����� ������ �� ������ ����� �������
*\param strings_count ����������� ������� � �������
*\param columns_count ����������� �������� � �������
*/
void draw_answer(int** array, const size_t strings_count, const size_t columns_count);

/**
*\brief �������� ����������� �������
*\param strings_count ����������� ������� (��������)
*/
void delete_array(int**& array, const size_t strings_count);

/**
* \brief ���� � ���������
* \return 0 ��� ������
*/
int main()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		size_t strings_count = get_massive_param("�����");
		size_t columns_count = get_massive_param("��������");

		cout << "����� ���������� �������\n" << static_cast<int>(input_type::MANUAL) << " - ���� �������\n"
			<< static_cast<int>(input_type::RANDOM) << " - ���� ��������\n";

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
		cout << "\n------------����������� ������----------" << endl;
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
		throw out_of_range("�� ����� �������� ��������");
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
			cout << "����� " << string + 1 << "." << column + 1 << ": ";
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