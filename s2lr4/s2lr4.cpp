#include <iostream>
#include <Windows.h>

#include "fio.h"
#include "letter.h"

#pragma warning (disable : 4996) //��� ����� �������� �� fopen � strcpy https://stackoverflow.com/questions/14386/fopen-deprecated-warning

#define ONE_STRING_WITH 20
#define MAX_WIDTH 60


//FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
// ��������� �������
//FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF

char menu(); //���� ������� ����


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char choice;

	letter* tmpLetter = new letter(); //��������� ���������� - ��������� �� ������
	letter* baseL = nullptr; //���� ����� � ������ � ��������

	baseL = baseL->loadRecords(); //������ ������ �� ����� � ������

	do {
		choice = menu();

		switch (choice)
		{
		case '1': //1 - �������� ����� ������ � ���� (Class letter)
			tmpLetter->enterNewRecord();
			baseL = tmpLetter->addNewRecord(baseL);
			break;
		case '2': //2 - �������� ��� ������
			if(baseL != nullptr) baseL->showAllRecords();
			break;
	//	case '3': //3 -  ����� ��� ������ ������������� ����������
	//		myLetter->inNameSearch();
	//		break;
	//	case '4': //4 -  ���������� ����� �� ���������� ���������
	//		myLetter = priceSort(myLetter);
	//		showAllRecords(myLetter);
	//		break;
	//	case '5': //5 -  ���������� ����� �� �������� - ������ ����������� (���������� ��������� !)
	//		!(*myLetter);
	//		showAllRecords(myLetter);
	//		break;

		default:
			break;
		}
	} while (choice != '0');

	if (baseL != nullptr) baseL->exitAndSave(); // ������ ���� �� ������ �� ���� ��� ������
}

//FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
// ���������� �������
//FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF

char menu() //���� ������� ����
{
	char select;
	std::cout << "==================================" << std::endl;
	std::cout << "����:" << std::endl;
	std::cout << "==================================" << std::endl;
	std::cout << "1 - �������� ����� ������ � ����" << std::endl;
	std::cout << "2 - P��������� ������ � ��������� ����" << std::endl;
	std::cout << "3 - ����� ��� ������ ������������� ����������" << std::endl;
	std::cout << "4 - ����������� ����� �� ���������� ���������" << std::endl;
	std::cout << "5 - ���������� � ���������� ������� (�� ������ �����������)" << std::endl;
	std::cout << "0 - ����� �� ��������� � ������ ���� �� ����. ����: " << BASE_NAME << std::endl;
	std::cout << "----------------------------------" << std::endl;

	do
	{
		std::cout << "������� ����� ������ ����: ";
		std::cin >> select;
		std::cin.ignore(32767, '\n'); // https://ravesli.com/urok-72-obrabotka-nekorrektnogo-vvoda-cherez-std-cin/

	} while (select < '0' || select > '5');

	return select;
} // menu()


