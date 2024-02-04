# include <iostream>
#include"Person.hpp"
#include"Flat.hpp"
#include"House.hpp"

void Print_Data(int num, char my_Choise, House &h); // Прототип процедуры вывода информации о доме в консоль

int main() {	

	//--------------- Заполнение данными объектов классов -------------------
	House h; // Создаём объект "Дом"
	std::cout << "\033[91mStep 1. Filling in home parameters\033[0m" << std::endl << std::endl;
	int num; // Переменная для хранения данных от пользователя
	int max_person; // Переменная для хранения максимального кол-ва человек в квартире	
	std::cout<< "Enter the qauntity of flats in the house -> ";
	std::cin >> num;
	h.SetFlats(num);
	std::cout << "Indicate how many people can live in one flat -> ";
	std::cin >> max_person;
	h.fill_in_house(max_person);
	std::cout << std::endl << "\033[92mThe house is occupied by residents successfully!\033[0m\nThe house contains: \033[92m" \
		<< Flat::GetCounter() << "\033[0m flats and " << "\033[92m" << Person::GetCounter() << "\033[0m persons." << std::endl;	
	h.print_flats(max_person);		
	
	//--------------- Получение данных пользователем -------------------
	std::cout << std::endl << "\033[91mStep 2. Receiving data upon user request\033[0m" << std::endl;
	char my_Choise = '0'; // Переменная для хранения выбора пользователя	
	Print_Data(num, my_Choise, h);

	//--------------- Удаление жильца из квартиры -------------------
	std::cout << std::endl << "\033[91mStep 3. Deleting a resident\033[0m" << std::endl << std::endl << "Enter the flat number where you want to delete the person from -> ";
	std::cin >> num;
	Flat* pointer_Flat = h.GetMemory(num - 1); // Указатель на адресс массива жильцов квартиры num
	try {
		if (num < 1 || num > Flat::GetCounter() || (pointer_Flat == nullptr))
			throw std::exception("\033[91mInput error! The number of flat is outside the range of flats or flat is free (flat is unoccupied)!\033[0m");
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
		while (num < 1 || num > Flat::GetCounter() || (pointer_Flat == nullptr)) {
			std::cout << "Enter the \033[4mnumber of flat\033[0m one more time -> ";
			std::cin >> num;
			pointer_Flat = h.GetMemory(num - 1);
		}
	}
	PrintPersons(pointer_Flat);
	std::cout << "Select the number of the person you want to delete -> ";
	int num_person;
	std::cin >> num_person;
	try {
		if (num_person < 1 || num_person > FindQuantityPersons(pointer_Flat))
			throw std::exception("\033[91mInput error! The person's number is not listed!\033[0m");
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
		while (num_person < 1 || num_person > FindQuantityPersons(pointer_Flat)) {
			std::cout << "Enter the \033[4mnumber of person\033[0m one more time -> ";
			std::cin >> num_person;
		}
	}
	h.delete_Person(num_person-1, pointer_Flat); // Удаляем выбранного жильца из выбранной квартиры
	std::cout << std::endl << "\033[92mThe resident deleted successfully!\033[0m\nThe house contains: \033[92m" \
		<< Flat::GetCounter() << "\033[0m flats and " << "\033[92m" << Person::GetCounter() << "\033[0m persons." << std::endl;
	h.print_flats(max_person);	
	Print_Data(num, my_Choise, h);

	//--------------- Добавление нового жильца в квартиру -------------------
	std::cout << std::endl << "\033[91mStep 4. Adding a resident\033[0m" << std::endl << std::endl << "Enter the flat number where you want to add the person -> ";
	std::cin >> num;	
	try {
		if (h.GetSize(num-1) == max_person || h.GetSize(num-1)<0)
			throw std::exception("\033[91mInput error! There is no free meth in the flat!\033[0m");
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
		while (h.GetSize(num-1) == max_person || h.GetSize(num - 1) < 0) {
			std::cout << "Enter the \033[4mflat number\033[0m one more time -> ";
			std::cin >> num;						
		}
	}
	
	h.add_Person(h.GetObj(num-1));
	std::cout << std::endl << "The house contains: \033[92m" << Flat::GetCounter() << "\033[0m flats and " << "\033[92m" \
		<< Person::GetCounter() << "\033[0m persons." << std::endl;
	h.print_flats(max_person);
	Print_Data(num, my_Choise, h);

	return 0;
}

void Print_Data(int num, char my_Choise, House& h) {
	do {
		std::cout << "\nDo you want to get/update information about the residents and flats of the house?\nPress \033[91m0\033[0m if you don't want (go to the next step) \033[4mor\033[0m press \033[91many other key\033[0m if you want -> ";
		std::cin >> my_Choise;
		if (my_Choise != '0') {
			std::cout << "Enter the number of flat -> ";
			std::cin >> num;
			try {
				if (num < 1 || num > Flat::GetCounter())
					throw std::exception("\033[91mInput error! The number of flat is outside the range of flats!\033[0m");
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << std::endl;
				while (num < 1 || num > Flat::GetCounter()) {
					std::cout << "Enter the \033[4mnumber of flat\033[0m one more time -> ";
					std::cin >> num;
				}
			}
			PrintPersons(h.GetMemory(num - 1)); // -1 Для приведения физического номера квартиры к индексу массива
		}
	} while (my_Choise != '0');
}
