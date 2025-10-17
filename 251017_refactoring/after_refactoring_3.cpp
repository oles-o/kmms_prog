#include <cmath>
#include <iostream>

int main() {
	const int arr_size = 20;
    int arr[arr_size];
	
	std::cout << "Сгенерированный массив: ";
    for (int i = 0; i < arr_size; i++) {
        arr[i] = rand() % 10;
        std::cout << arr[i] << " ";
    }
	std::cout << std::endl;
	
	
    for (int i = 0; i < arr_size / 2; i++) {
        int element = arr[i];
        arr[i] = arr[arr_size - 1 - i];
        arr[arr_size - 1 - i] = element;
    }
	
	std::cout << "Перевернутый массив: ";
    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
