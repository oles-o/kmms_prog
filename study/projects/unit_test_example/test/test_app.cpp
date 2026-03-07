#include <gtest/gtest.h>

#include <vector>
#include "sortings.hpp"
#include "io.hpp"


TEST(ArraysEqual, AnyElementsCount) {
    int actual[] = {1, 8, 2, 5, 3, 11};
    int expected[] = {1, 2, 3, 5, 8, 11};
	const int actual_size = sizeof(actual) / sizeof(actual[0]);
	const int expected_size = sizeof(expected) / sizeof(expected[0]);

    oles::sortings::bubble_sort(actual, actual_size);


    ASSERT_EQ(expected_size, actual_size)	
		<< "Разные размеры ожидаемого и отсортированного массивов";
		
	for (int i = 0; i < actual_size; i++) {
		ASSERT_EQ(expected[i], actual[i])
			<< "Массив ожидаемый и отсортированный отличаются в элементе с индексом "
			<< i;
	}
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

