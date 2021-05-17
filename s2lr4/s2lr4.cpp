#include <iostream>
#include <Windows.h>

#include "fio.h"
#include "letter.h"

#pragma warning (disable : 4996) //Без этого ругается на fopen и strcpy https://stackoverflow.com/questions/14386/fopen-deprecated-warning

#define ONE_STRING_WITH 20
#define MAX_WIDTH 60


//FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
// ПРОТОТИПЫ МЕТОДОВ
//FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF

char menu(); //Меню функций базы


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char choice;

	letter* tmpLetter = new letter(); //временная переменная - указатель на письмо
	letter* baseL = nullptr; //база писем в памяти и доставок

	baseL = baseL->loadRecords(); //чтение данных из файла в память

	do {
		choice = menu();

		switch (choice)
		{
		case '1': //1 - Добавить новое письмо в базу (Class letter)
			tmpLetter->enterNewRecord();
			baseL = tmpLetter->addNewRecord(baseL);
			break;
		case '2': //2 - Показать все записи
			if(baseL != nullptr) baseL->showAllRecords();
			break;
	//	case '3': //3 -  Найти все письма определенного получателя
	//		myLetter->inNameSearch();
	//		break;
	//	case '4': //4 -  Сортировка писем по увелечению стоимости
	//		myLetter = priceSort(myLetter);
	//		showAllRecords(myLetter);
	//		break;
	//	case '5': //5 -  Сортировка писем по алфавиту - адресу отправителя (перегрузка оператора !)
	//		!(*myLetter);
	//		showAllRecords(myLetter);
	//		break;

		default:
			break;
		}
	} while (choice != '0');

	if (baseL != nullptr) baseL->exitAndSave(); // запись базы из памяти на диск при выходе
}

//FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
// РЕАЛИЗАЦИЯ МЕТОДОВ
//FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF

char menu() //Меню функций базы
{
	char select;
	std::cout << "==================================" << std::endl;
	std::cout << "Меню:" << std::endl;
	std::cout << "==================================" << std::endl;
	std::cout << "1 - Добавить новое письмо в базу" << std::endl;
	std::cout << "2 - Pаспечатка данных в табличном виде" << std::endl;
	std::cout << "3 - Найти все письма определенного получателя" << std::endl;
	std::cout << "4 - Сортировать писем по увелечению стоимости" << std::endl;
	std::cout << "5 - Сортировка в алфавитном порядке (по адресу отправителя)" << std::endl;
	std::cout << "0 - Выход из программы и запись базы на диск. Файл: " << BASE_NAME << std::endl;
	std::cout << "----------------------------------" << std::endl;

	do
	{
		std::cout << "Введите номер пункта меню: ";
		std::cin >> select;
		std::cin.ignore(32767, '\n'); // https://ravesli.com/urok-72-obrabotka-nekorrektnogo-vvoda-cherez-std-cin/

	} while (select < '0' || select > '5');

	return select;
} // menu()


