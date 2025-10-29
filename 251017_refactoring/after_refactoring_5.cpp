#include <cmath>
#include <iostream>

int main(int argc, char* argv[]){
	int day, month, year;

	std::cout << "Введите день: " << std::endl;
	std::cin >> day;
	std::cout << "Введите номер месяца: " << std::endl;
	std::cin >> month;
	std::cout << "Введите год: " << std::endl;
	std::cin >> year;

	int year_centure = year % 100;
	int centure_count = year / 100;
	int day_week = (day
				+ (13*month - 1) / 5
				+ year_centure / 4
				+ centure_count / 4
				- 2*centure_count
				+ 777)
			% 7;

	std::cout << "День недели: " << std::endl;

	switch(day_week){
		case 0:
			std::cout << "Воскресенье" << std::endl;
			break;
		case 1:
			std::cout << "Понедельник" << std::endl;
			break;
		case 2:
			std::cout << "Вторник" << std::endl;
			break;
		case 3:
			std::cout << "Среда" << std::endl;
			break;
		case 4:
			std::cout << "Четверг" << std::endl;
			break;
		case 5:
			std::cout << "Пятница" << std::endl;
			break;
		case 6:
			std::cout << "Суббота" << std::endl;
			break;
	}
	 
	system("pause");
	return 0;
}
