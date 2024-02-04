#pragma once
#include<string>

class Person {
public:		
	Person() :name_("Tom"), surname_("Robbinson"), age_(24) { ++counter_; } // Конструктор объекта класса по умолчанию
	Person(std::string name, std::string surname, int age); // Прототип параметрического конструктора
	Person(const Person& other); // Прототип конструктора копирования
	// Сэттэры
	void SetName(std::string name) { this->name_ = name; }
	void SetSurname(std::string surename) { this->surname_ = surename; }
	void SetAge(int age) { this->age_ = age; }
	// Гэттэры
	static int GetCounter() { return counter_; }
	std::string GetName() { return name_; }
	std::string GetSurname() { return surname_; }
	int GetAge() { return age_; }
	~Person() { counter_--; } // Деструктор	
private:
	std::string name_;
	std::string surname_;
	int age_;
	static int counter_; // Кол-во жильцов в доме
};