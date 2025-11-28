#include <locale>
#include <iostream>

#include "travel.hpp"
#include "travel_func.hpp"
#include "travel_items.hpp"

int main() {
	std:setlocale(LC_ALL, "");
	
	const OLes::TravelItem* current = &OLes::MAIN
	do {
		current = current->func(current);
	} while (true)
	
 	return 0;
}