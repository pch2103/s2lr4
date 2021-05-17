#pragma once

#include "fio.h"

class common
{
	fio inName; //Имя получателя
	char* inAddress; //Адрес получателя
	char* outAddress; //Адрес отправителя

public:
	common() : inName() //конструктор по-умолчанию
	{
		std::cout << "common::Kонструктор по-умолчанию" << std::endl;

		inAddress = new char[ONE_STRING_WITH];
		strcpy(inAddress, "");
		outAddress = new char[ONE_STRING_WITH];
		strcpy(outAddress, "");
	}

	//конструктор c параметрами
	common(fio _fio, const char* _inAddress, const char* _outAddress) :
		inAddress(new char[strlen(_inAddress) + 1]),
		outAddress(new char[strlen(_outAddress) + 1]),
		inName(_fio)
	{
		std::cout << "common::Kонструктор c параметрами" << std::endl;
		strcpy(inAddress, _inAddress);
		strcpy(outAddress, _outAddress);
	}

	virtual ~common() {
		std::cout << "~common::Виртуальный деструктор" << std::endl;
		delete[] inAddress;
		delete[] outAddress;
	}
	
	//сеттеры переменных базового класса
	void setFio(fio _f) { 
		inName = _f;
	}

	void setInAddress(char* _a) 
	{
		delete[] inAddress;
		inAddress = new char[strlen(_a) + 1];
		strcpy(inAddress, _a);
	}//setInAddress

	void setOutAddress(char* _a)
	{
		delete[] outAddress;
		outAddress = new char[strlen(_a) + 1];
		strcpy(outAddress, _a);
	}//setOutAddress

	//геттеры переменных базового класса
	fio getFio() const { return fio(inName); }
	char* getInAddress() const { return inAddress; }
	char* getOutAddress() const { return outAddress; }

	virtual void enterNewRecord() = 0; //ввод новой записи в единичную структуру потом она будет записана в addNewRecord()
	virtual int get_count() = 0; //получить количество записей в памяти
	virtual void add_count() = 0; //увеличить количество записей в памяти на 1 (при добавлении записи)
	virtual void showOneRecord(int) = 0; //показывает одну запись в памяти 
	virtual void exitAndSave() = 0;  // запись данных из памяти на диск при выходе
	//virtual common* addNewRecord(common*) = 0;
};

