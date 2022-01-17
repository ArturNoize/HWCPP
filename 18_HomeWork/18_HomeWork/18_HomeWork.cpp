#include <iostream>
#include <Windows.h>
#include <time.h>
#include <string>

using namespace std;

/** Домашнее задание № 18
* Доработать структуру STUDENT, начатую на уроке следующим функционалом:
* - добавить поля:
*		массив оценок студента ( до 10 оценок),
*		средний балл студента (расчетное поле).
* - добавить функции:
*		заполнение массива оценок (можно рандомно),
*		расчет среднего балла студентов.
* - продемонстрировать работу функций в main().
*/

struct Date_ //Структура даты
{
	int day; //День
	int month; //Месяц
	int year; //Год
	string week_day; //День недели

	void print_date() //Функция вывода
	{
		cout << year << " " << month << " " << day << " " << week_day << endl;
	}
};

struct Student //Структура студента
{
	string name; //Имя студента
	string surname; //Фамилия студента

	Date_ bd; //ДР студента
	Date_ day_st; //Дата начала обучения студента

	int average = 0; //Средний балл студента (по умолчанию принимает 0)
	const int randMin = 1; //Минимальный балл
	const int randMax = 12; //Максимальный балл
	static const int maxGradesCount = 10; //Кол-во оценок
	int grades[maxGradesCount]; //Массив оценок
	string group = "BV111"; //Группа принадлежности

	void set_grd() //Заполнение массива оценок
	{
		for (size_t i = 0; i < maxGradesCount; i++)
		{
			average += grades[i] = rand() % randMax + randMin;
		}
		average /= maxGradesCount; //Считаем средний балл
	}

	void print_st() //Вывод студента
	{
		cout
			<< "| "
			<< group
			<< "\t| "
			<< name
			<< "  \t| "
			<< surname
			<< " \t| "
			<< bd.day << "." << bd.month << "." << bd.year
			<< "\t| "
			<< day_st.year
			<< "\t  | ";

		for (size_t i = 0; i < maxGradesCount; i++)
		{
			cout << grades[i];

			if (i == 9)
				cout << "\t| " << average << " \t|\n";
			else
				cout << ", ";
		}

	}
};

void get_st() //Заполнение данных о студентах
{
	int const maxSudents = 20; //Максимальное кол-во студентов в группе

	Student st1 = { "Vasiliy", "Vasin", {1,2,1990,"Friday"}, {17,1,2022,"Monday"} };
	Student st2 = { "Ivan", "Ivanov", {9,12,1985,"Sunday"}, {17,1,2022,"Monday"} };
	Student st3 = { "Petr", "Petrov", {16,8,2005,"Friday"}, {17,1,2022,"Monday"} };
	Student st4 = { "Andrey", "Andreev", {1,3,1990,"Saturday"}, {17,1,2022,"Monday"} };
	Student st5 = { "Denis", "Denisov", {8,11,1997,"Wednesday"}, {17,1,2022,"Monday"} };
	Student st6 = { "Artem", "Artemov", {1,12,2001,"Thursday"}, {17,1,2022,"Monday"} };
	Student st7 = { "Egor", "Egorov", {19,9,1998,"Friday"}, {17,1,2022,"Monday"} };
	Student st8 = { "Mark", "Markov", {2,2,2002,"Mondey"}, {17,1,2022,"Monday"} };
	Student st9 = { "Alex", "Sanych", {4,12,2003,"Monday"}, {17,1,2022,"Monday"} };
	Student st10 = { "Victor", "Vitin", {12,12,2000,"Thursday"}, {17,1,2022,"Monday"} };
	Student st11 = { "Sara", "Samara", {6,10,1999,"Tuesday"}, {17,1,2022,"Monday"} };
	Student st12 = { "Stephen", "Strange", {28,4,1999,"Wednesday"}, {17,1,2022,"Monday"} };
	Student st13 = { "Boris", "Borisov", {18,6,1999,"Wednesday"}, {17,1,2022,"Monday"} };
	Student st14 = { "Stepan", "Stepanov", {28,7,1999,"Friday"}, {17,1,2022,"Monday"} };
	Student st15 = { "Michael ", "Hzhz ", {22,10,1999,"Saturday"}, {17,1,2022,"Monday"} };
	Student st16 = { "Inna", "Innet", {23,11,1999,"Sunday"}, {17,1,2022,"Monday"} };
	Student st17 = { "Sebastian", "Sebin", {18,1,1994,"Tuesday"}, {17,1,2022,"Monday"} };
	Student st18 = { "Oleg", "Snickers", {18,4,1996,"Monday"}, {17,1,2022,"Monday"} };
	Student st19 = { "Elena", "Kamen", {21,6,1997,"Monday"}, {17,1,2022,"Monday"} };
	Student st20 = { "Julia", "July ", {17,11,1998,"Friday"}, {17,1,2022,"Monday"} };

	Student st_arr[maxSudents] = { st1, st2, st3, st4, st5, st6, st7, st8, st9, st10,
									st11, st12, st13, st14, st15, st16, st17, st18, st19, st20 };

	cout << "+-------+---------------+---------------+---------------+---------+-------------------------------------+-------+\n";
	cout << "| Group\t| Name  \t| Surname \t| Birth Date \t| St.Date | Grades\t\t\t\t| Ave. \t|\n";
	cout << "+-------+---------------+---------------+---------------+---------+-------------------------------------+-------+\n";
	for (size_t i = 0; i < maxSudents; i++)
	{
		st_arr[i].set_grd(); //Назначаем оценки каждому из студентов
		st_arr[i].print_st(); //Междела и выводим
	}
	cout << "+-------+---------------+---------------+---------------+---------+-------------------------------------+-------+\n";
}

void main()
{
	SetConsoleCP(1251); //Кодировка консоли
	SetConsoleOutputCP(1251); //Кодировка вывода консоли
	srand(time(0)); //Псевдорандом

	get_st();
}