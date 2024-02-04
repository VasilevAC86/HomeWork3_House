#include "Flat.hpp"
#include<ctime>
#include<cstdlib>
#include<iostream>

int Flat::counter_{};

// Статтические массивы для работы рандома
std::string arr_Name[12]{ "Sohia", "Maison", "Sem", "Anna", "Bob", "Nataly", "Jack", "Isabella", "James", "Emily", "Oscar", "Mia" };
std::string arr_Surname[12]{ "Adamson", "Backer", "Brown", "Charlson", "Cook", "Daniels", "Davidson", "Dickinson", "Douglas", "Hailey", "Jenkins", "Mason" };

void Flat::fill_in() {
	pointer_darr_persons_ = new Person[size_]; // Выделяем память под динамический массив из жильцов в квартире	
	std::string surname = arr_Surname[rand() % 11]; // Рандомно выбираем фамилию	
	for (int i = 0; i < size_; ++i) { // Цикл заполнения полей объектов Person в объекте Flat
		pointer_darr_persons_[i].SetSurname(surname); // Фамилия общая для всех жильцов одной квартиры (семья)
		pointer_darr_persons_[i].SetName(arr_Name[rand() % 12]);
		pointer_darr_persons_[i].SetAge(rand() % 90);
	}
}

void PrintPersons(const Flat* pointer) {
	if (pointer == nullptr) {
		std::cout << "\033[94mThis flat is free (flat is unoccupied)!\033[0m" << std::endl;
		return;
	}
	std::cout << "\033[92mThe following pesons live in the flat:\033[0m" << std::endl;
	for (int i = 0; i < pointer->size_; ++i)
		std::cout << "\033[96m" << i + 1 << ". " << pointer->pointer_darr_persons_[i].GetName() << ", " << \
		pointer->pointer_darr_persons_[i].GetSurname() << ", "	<< pointer->pointer_darr_persons_[i].GetAge() << "\033[0m years old" << std::endl;
}



