#include "House.hpp"
#include<iostream>
#include<ctime>
#include<cstdlib>

Flat* House::GetMemory(int num) {
	if (pointer_darr_flats_[num].GetAdress() == nullptr)
		return nullptr;
	return &pointer_darr_flats_[num];
}

void House::fill_in_house(int max_person) {
	pointer_darr_flats_ = new Flat[flats_]; // Выделяем память динамический массив объектов типа Flat
	srand(time(NULL));	
	for (int i = 0; i < flats_; ++i) {
		int size = rand() % (max_person + 1);
		pointer_darr_flats_[i].SetNumber(i+1);
		pointer_darr_flats_[i].SetSize(size);
		if (size) // Если в квартире кто-то живёт, то в элементе массива "квартира" создаём массив жильцов					 
			pointer_darr_flats_[i].fill_in(); // Заполянем каждую квартиру жильцами
	}
}

void House::print_flats(int max_person) {
	std::cout << "\n\033[92mThe following flats are unoccupied (numbers of empty flats):\033[0m " << std::endl;
	int counter = 0;	
	for (int i = 0; i < Flat::GetCounter(); ++i)
		if (pointer_darr_flats_[i].GetAdress() == nullptr) {
			std::cout << pointer_darr_flats_[i].GetNumber() << ", ";
			counter++;
		}
	if (counter)
		std::cout << "\b\b." << std::endl;
	else
		std::cout << "There are no empty flats." << std::endl;
	counter = 0;
	std::cout << "\033[92mThe following flats are fully occupied (numbers of fully flats):\033[0m " << std::endl;	
	for (int i = 0; i < Flat::GetCounter(); ++i)
		if (pointer_darr_flats_[i].GetSize() == max_person) {
			std::cout << pointer_darr_flats_[i].GetNumber() << ", ";
			counter++;
		}
	if (counter)
		std::cout << "\b\b." << std::endl;
	else
		std::cout << "There are no fully flats." << std::endl;
}

void House::delete_Person(int num_person, Flat* pointer) {
	if (pointer->GetSize() == 1) { // Если в квартире живёт только один человек, то	
		pointer->SetSize(0);// устанавливаем новое кол-во жильцов
		delete[] pointer->GetAdress(); // Освобождаем память, выделенную под дин.массив жильцов, деструктор вызывается автоматически
		pointer_darr_flats_[pointer->GetNumber() - 1].SetAdress(nullptr); // Указатель на опустевшую квартиру переводим в нейтральный статус
		pointer->SetAdress(nullptr); // Указатель на удалённый массив жильцов квартиры переводим в нейтральный статус
		return; // Выходим из метода
	}
	int length = pointer->GetSize() - 1; // Размер актуализированного массива Person
	Person* tmp = new Person[length]; // Выделяем память под новый массив жильцов квартиры
	for (int i = 0; i < pointer->GetSize(); ++i) { // Цикл формирования нового динамического массива Person
		if (i == num_person)
			continue;
		if (i < num_person) {
			tmp[i] = pointer->GetAdress()[i];			
		}
		if (i > num_person) {
			tmp[i - 1] = pointer->GetAdress()[i];			
		}
	}		
	pointer->SetSize(length); // Меняем поле объекта
	delete[] pointer->GetAdress(); // Освобождаем память из под неактуального массива объектов Person, деструктор вызывается автоматически
	pointer_darr_flats_[pointer->GetNumber() - 1].SetAdress(tmp); // Указатель на массив жильцов квартиры num_person переводим на актуализированный массив жильцов
	pointer->SetAdress(tmp); // Перенаправляем указатель актуализированной квартиры на новый массив	
}

void House::add_Person(Flat& obj) {
	if (obj.GetAdress() == nullptr) {
		obj.SetSize(1); // Меняем значение поля
		obj.fill_in(); // Заполянем квартиру жильцом		
	}
	else {
		int length = obj.GetSize() + 1; // Размер актуализированного массива Person
		Person p(obj.GetAdress()[0]); // Создаём новый объект класса Person оператором копирования
		Person* tmp = new Person[length]; // Выделяем память под новый массив жильцов квартиры
		for (int i = 0; i < length; ++i) // Цикл формирования нового динамического массива Person
			if (i != length - 1)
				tmp[i] = obj.GetAdress()[i];
			else
				tmp[i] = p;
		obj.SetSize(length);
		delete[] obj.GetAdress(); // Освобождаем память из под неактуального массива объектов Person, деструктор вызывается автоматически
		obj.SetAdress(tmp); // Указатель на массив жильцов квартиры num_person переводим на актуализированный массив жильцов
	}
	std::cout << std::endl << "\033[92mThe resident added successfully!\033[0m" << std::endl << "Person data: \033[94m" << \
		obj.GetAdress()->GetName() << ' ' << obj.GetAdress()->GetSurname() << ", " << obj.GetAdress()->GetAge() << "\033[0m" << std::endl\
		<< "Do you want to change person's data? Press \033[91m1\033[0m to yes \033[4mor\033[0m press \033[91many other key\033[0m to no -> ";
	char my_Choise;
	std::cin >> my_Choise;
	if (my_Choise == '1') {
		std::cout << "Enter the name -> ";
		std::string my_Text;
		std::cin >> my_Text;
		obj.GetAdress()->SetName(my_Text);
		std::cout << "Enter the surname -> ";
		std::cin >> my_Text;
		obj.GetAdress()->SetSurname(my_Text);
		int age;
		std::cout << "Enter the age -> ";
		std::cin >> age;
		while (age < 0 || age > 90) {
			std::cout << "\033[91mInput error!\033[0m Enter the age one more time -> ";
			std::cin >> age;
		}
		obj.GetAdress()->SetAge(age);
	}
}

