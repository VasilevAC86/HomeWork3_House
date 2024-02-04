#include "Person.hpp"

int Person::counter_{};

Person::Person(std::string name, std::string surname, int age) {
	this->name_ = name;
	this-> surname_ = surname;
	this->age_ = age;
	++counter_;
}

Person::Person(const Person& other) {
	this->name_ = other.name_;
	this->surname_ = other.surname_;
	this->age_ = other.age_;
	++counter_; // При создании нового объекта увеличиваем счётчик объектов
}


