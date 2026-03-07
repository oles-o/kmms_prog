#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

// 1й уровень
const OLes::MenuItem* OLes::show_menu(const MenuItem* current) {
	std::cout << "Обучайка приветствует тебя, мой юный ученик!" << std::endl;
	for (int i = 1; i < current->children_count; i++) {
		std::cout << current->children[i]->title << std::endl;
	}
	std::cout << current->children[0]->title << std::endl;		
	std::cout << "Обучайка > " ;
	
	int user_input;
	std::cin >> user_input;
	std::cout << std::endl;
	
	return current->children[user_input];
}

const OLes::MenuItem* OLes::exit(const MenuItem* current) {
	std::exit(0);
}



// 2й уровень для "учиться матем"

const OLes::MenuItem* OLes::study_algebra(const MenuItem* current) {
	
	std::cout << "АЛГЕБРА " << std::endl;
	std::cout << "Алексей Юрьевич приветствует тебя, юный ученик!" << std::endl;
	for (int i = 1; i < current->children_count; i++) {
		std::cout << current->children[i]->title << std::endl;
	}
	std::cout << current->children[0]->title << std::endl;		
	std::cout << "Обучайка > " ;
	
	int user_input;
	std::cin >> user_input;
	std::cout << std::endl;
	
	return current->children[user_input];
}

const OLes::MenuItem* OLes::study_matan(const MenuItem* current) {
	// TODO

	std::cout << "МАТЕМАТИЧЕСКИЙ АНАЛИЗ " << std::endl;
	std::cout << "Анатолий Олеговия приветствует тебя, юный ученик!" << std::endl;
	for (int i = 1; i < current->children_count; i++) {
		std::cout << current->children[i]->title << std::endl;
	}
	std::cout << current->children[0]->title << std::endl;		
	std::cout << "Обучайка > " ;
	
	int user_input;
	std::cin >> user_input;
	std::cout << std::endl;
	
	return current->children[user_input];
}

const OLes::MenuItem* OLes::study_go_back(const MenuItem* current) {
	// TODO
	std::cout << current->title << std::endl;
	return current->parent->parent;
}



// 3й уровень для "изучать алгебру"
	
const OLes::MenuItem* OLes::algebra_summ(const MenuItem* current) {
	// TODO
	std::cout << current->title << std::endl;
	return current->parent;
}

const OLes::MenuItem* OLes::algebra_substract(const MenuItem* current) {
	// TODO
	std::cout << current->title << std::endl;
	return current->parent;
}

const OLes::MenuItem* OLes::algebra_multiply(const MenuItem* current) {
	// TODO
	std::cout << current->title << std::endl;
	return current->parent;
}

const OLes::MenuItem* OLes::algebra_divide(const MenuItem* current) {
	// TODO
	std::cout << current->title << std::endl;
	return current->parent;
}

const OLes::MenuItem* OLes::algebra_go_back(const MenuItem* current) {
	// TODO
	std::cout << current->title << std::endl;
	return current->parent->parent;
}





// 3й уровень для "изучать матан"

const OLes::MenuItem* OLes::matan_diff(const MenuItem* current) {
	// TODO
	std::cout << current->title << std::endl;
	return current->parent;
}

const OLes::MenuItem* OLes::matan_int(const MenuItem* current) {
	// TODO
	std::cout << current->title << std::endl;
	return current->parent;
}

const OLes::MenuItem* OLes::matan_go_back(const MenuItem* current) {
	// TODO
	std::cout << current->title << std::endl;
	return current->parent->parent;
}