#include "long_number.hpp"

using OLes::LongNumber;
		
// К по У
LongNumber::LongNumber() {
	numbers = new int[1];
	numbers[0] = 0;
	lenght = 1;
	sign = 1;
}

// консьруктор с параметром
LongNumber::LongNumber(int length, int sign) {
	this->length = length;
    this->sign = sign;
    numbers = new int[length];
	
	for (int i = 0; i < length; i++) {
		numbers[i] = 0;
	}
}

// констр от строки
LongNumber::LongNumber(const char* const str) {
	int lenght_with_sign = get_lenght(str);
	
	if (str[0] == "-") {
		sign = -1;
		lenght = lenght_with_sign - 1;
	} else {
		sign = 1;
		lenght = lenght_with_sign;
	}
	
	numbers = new int[lenght];
	
	for (int i = 0; i < lenght; i++){
	numbers[i] = str[lenght_with_sign - 1 - i] - "0";
	
	}
}

// КК
LongNumber::LongNumber(const LongNumber& x) {
	numbers = new int[x.length];
	for (i = 0; i < lenght; i++) {
		numbers[i] = x.numbers[i];
	}
	lenght = x.lenght;
	sign = x.sign;
}

//КП
LongNumber::LongNumber(LongNumber&& x) {
	numbers = x.numbers;
	x.numbers = nullptr;
	
	lenght = x.lenght;
	x.lenght = 0;
	
	sign = x.sign;
	x.sign = 1;
}

//деструктор
LongNumber::~LongNumber() {
	delete[] numbers;
	numbers = nullptr
	lenght = 0;
	sign = 1;
}

// ОП от строки
LongNumber& LongNumber::operator = (const char* const str) {
	int lenght_with_sign = get_lenght(str);
	
	if (str[0] == "-") {
		sign = -1;
		lenght = lenght_with_sign - 1;
	} else {
		sign = 1;
		lenght = lenght_with_sign;
	}
	
	delete [] numbers;
	numbers = new int[lenght];
	
	for (int i = 0; i < lenght; i++){
	numbers[i] = str[lenght_with_sign - 1 - i] - "0";
	}
	return *this; 
}

// ОПК 
LongNumber& LongNumber::operator = (const LongNumber& x) {
	if (this == &x) return *this;
	
	delete [] numbers;
	numbers = new int[x.lenght];
	for (int i = 0; i < lenght; i++) {
		numbers[i] = x.numbers[i];
	}
	lenght = x.lenght;
	sign = x.sign;
	return *this; 
}

// ОПП
LongNumber& LongNumber::operator = (LongNumber&& x) {
	delete [] numbers;
	numbers = x.numbers;
	x.numbers = nullptr;
	
	lenght = x.lenght;
	x.lenght = 0;
	
	sign = x.sign;
	x.sign = 1;
	
	return *this;
}
	


bool LongNumber::operator == (const LongNumber& x) const {
	// TODO
}

bool LongNumber::operator != (const LongNumber& x) const {
	// TODO
}

bool LongNumber::operator > (const LongNumber& x) const {
	// TODO
}

bool LongNumber::operator < (const LongNumber& x) const {
	// TODO
}

LongNumber LongNumber::operator + (const LongNumber& x) const {
	// TODO
}

LongNumber LongNumber::operator - (const LongNumber& x) const {
	// TODO
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
	// TODO
}

LongNumber LongNumber::operator / (const LongNumber& x) const {
	// TODO
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
	// TODO
}

bool LongNumber::is_negative() const noexcept {
	// TODO
}

// ----------------------------------------------------------
// PRIVATE
// ----------------------------------------------------------
int LongNumber::get_length(const char* const str) const noexcept {
	// TODO
}

// ----------------------------------------------------------
// FRIENDLY
// ----------------------------------------------------------
namespace OLes {
	std::ostream& operator << (std::ostream &os, const LongNumber& x) {
		// TODO
	}
}
