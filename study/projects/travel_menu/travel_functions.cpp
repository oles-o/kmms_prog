#include "travel_functions.hpp"

#include <cstdlib>
#include <iostream>

namespace {
	const OLes::TravelItem* show_children(const OLes::TravelItem* current) {
		for (int i = 1; i < current->children_count; i++) {
			std::cout << current->children[i]->title << std::endl;
		}
		std::cout << current->children[0]->title << std::endl;		
	
		int user_input;
		std::cin >> user_input;
		std::cout << std::endl;
	
		return current->children[user_input];
	}
}

// 0й уровень
const OLes::TravelItem* OLes::travel_menu(const TravelItem* current) {
	std::cout << "Главное меню" << std::endl;
	return show_children(current);
}


// 1й уровень
const OLes::TravelItem* OLes::travel(const TravelItem* current) {
	std::cout << "Второй уровень меню" << std::endl;
	return show_children(current);
}

const OLes::TravelItem* OLes::exit(const TravelItem* current) {
	std::exit(0);
}



// 2-ий уровень для "1 - Путешествовать по России"

const OLes::TravelItem* OLes::travel_dalvost(const TravelItem* current) {
	
	std::cout << "Третий уровень Дальний Восток" << std::endl;
	return show_children(current);
}

const OLes::TravelItem* OLes::travel_altay(const TravelItem* current) {
	// TODO
	std::cout << current->title << std::endl;
	return current->parent;
}

const OLes::TravelItem* OLes::travel_goldring(const TravelItem* current) {
	// TODO
	std::cout << current->title << std::endl;
	return current->parent;
}

const OLes::TravelItem* OLes::travel_back(const TravelItem* current) {
	// TODO
	std::cout << current->title << std::endl;
	return current->parent->parent;
}



// 3-ий уровень для "1 - Дальний Восток"
	
const OLes::TravelItem* OLes::travel_dalvost_vladivostok(const TravelItem* current) {
	// TODO
	std::cout << current->title << std::endl;
	return current->parent;
}

const OLes::TravelItem* OLes::travel_dalvost_sahalin(const TravelItem* current) {
	// TODO
	std::cout << current->title << std::endl;
	return current->parent;
}

const OLes::TravelItem* OLes::travel_dalvost_habarovsk(const TravelItem* current) {
	// TODO
	std::cout << current->title << std::endl;
	return current->parent;
}

const OLes::TravelItem* OLes::travel_dalvost_back(const TravelItem* current) {
	// TODO
	std::cout << current->title << std::endl;
	return current->parent->parent;
}
