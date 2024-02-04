#pragma once
#include"Person.hpp"

class Flat {
public:
	// Конструктор объекта класса по умолчанию	
	Flat() : size_(0), number_(0), pointer_darr_persons_(nullptr) { ++counter_; } 
	void fill_in(); // Прототип метода для создания динамического массива объектов Person в одном объекте Flat (семьи в одной квартире)	
	//Person* Delete_Person(int number, Flat* pointer); // Возврат адреса актуализированного массива жильцов квартиры
	//Гэттэры
	static int GetCounter() { return counter_; }
	Person* GetAdress() { return pointer_darr_persons_; }
	int GetSize() { return size_; }
	int GetNumber() { return number_; }
	// Блок сэттэров	
	void SetSize(int size) { this->size_ = size; }	
	void SetNumber(int number) { this->number_ = number; }	
	void SetAdress(Person* pointer) { this->pointer_darr_persons_ = pointer; }
	// Прототипы дружественных функций
	friend void PrintPersons(const Flat * pointer);// Вывод в консоль массива жильцов квартиры	
	friend int FindQuantityPersons(const Flat* pointer) { return pointer->size_; }	
	~Flat() {
		counter_--; // уменьшаем счётчик
		if (pointer_darr_persons_) // Если в поле pointer_darr_persons_ есть элементы, то сначала высвобождаем память
			delete[]pointer_darr_persons_;
	}
private:		
	int size_; // Кол-во жильцов в квартире
	int number_; // Номер квартиры
	Person* pointer_darr_persons_; // Указатель на адрес памяти, по которому хранится динамический массив объектов Person
	static int counter_; // Кол-во квартир в доме
};