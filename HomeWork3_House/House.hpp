#pragma once
#include"Flat.hpp"

class House {
public:
	// Конструктор по умолчанию
	House() :adress_("First avenue, 18"), flats_(0), pointer_darr_flats_(nullptr) {};
	// Сэттэры	
	void SetFlats(int flats) { this->flats_ = flats; }		
	// Гэттэры	
	Flat* GetMemory(int num); // для получения адреса с массивом жильцов квартиры	
	int GetSize(int num) { return pointer_darr_flats_[num].GetSize(); } // для получения кол-ва жильцов в квартире num
	Flat& GetObj(int num) { return pointer_darr_flats_[num]; } // для получения ссылки на квартиру, в которую добааляется житель
	// Метод для заполенения дома квартирами с жильцами
	void fill_in_house(int max_person); 
	// Метод вывода в консоль номеров квартир по кол-ву жильцов
	void print_flats(int max_person);		
	// Метод удаления жильца num_person из квартиры с адресом pointer_flat
	void delete_Person(int num_person, Flat *pointer);
	// Метод добавления жильца в квартиру с адресом pointer_flat
	void add_Person(Flat &obj);
	~House() {
		if (pointer_darr_flats_) // Если в поле pointer_darr_flats_ есть элементы, то сначала высвобождаем память
			delete[]pointer_darr_flats_;
	}
private:
	std::string adress_; // Адресс дома		
	int flats_; // Кол-во квартир в доме
	Flat* pointer_darr_flats_; // Динамический массив квартир в доме
};