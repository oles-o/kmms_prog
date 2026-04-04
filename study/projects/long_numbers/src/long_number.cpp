#include "long_number.hpp"

using OLes::LongNumber;
		
// К по У
LongNumber::LongNumber() {
	numbers = new int[1];
	numbers[0] = 0;
	length = 1;
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
	int length_with_sign = get_length(str);
	
	if (str[0] == '-') {
		sign = -1;
		length = length_with_sign - 1;
	} else {
		sign = 1;
		length = length_with_sign;
	}
	
	numbers = new int[length];
	
	for (int i = 0; i < length; i++){
	numbers[i] = str[length_with_sign - 1 - i] - '0';
	
	}
}

// КК
LongNumber::LongNumber(const LongNumber& x) {
	length = x.length;
	sign = x.sign;
	numbers = new int[x.length];
	for (int i = 0; i < length; i++) {
		numbers[i] = x.numbers[i];
	}
}

//КП
LongNumber::LongNumber(LongNumber&& x) {
	numbers = x.numbers;
	length = x.length;
	sign = x.sign;

	x.numbers = nullptr;
	x.length = 0;
	x.sign = 1;
}

//деструктор
LongNumber::~LongNumber() {
	delete[] numbers;
	numbers = nullptr;
	length = 0;
	sign = 1;
}

// ОП от строки
LongNumber& LongNumber::operator = (const char* const str) {
	int length_with_sign = get_length(str);
	
	if (str[0] == '-') {
		sign = -1;
		length = length_with_sign - 1;
	} else {
		sign = 1;
		length = length_with_sign;
	}
	
	delete [] numbers;
	numbers = new int[length];
	
	for (int i = 0; i < length; i++){
	numbers[i] = str[length_with_sign - 1 - i] - '0';
	}
	return *this; 
}

// ОПК 
LongNumber& LongNumber::operator = (const LongNumber& x) {
	if (this == &x) return *this;
	
	delete [] numbers;
	length = x.length;
	sign = x.sign;
	numbers = new int[x.length];
	for (int i = 0; i < length; i++) {
		numbers[i] = x.numbers[i];
	}
	return *this; 
}

// ОПП
LongNumber& LongNumber::operator = (LongNumber&& x) {

	delete [] numbers;
	numbers = x.numbers;
	length = x.length;
	sign = x.sign;

	x.numbers = nullptr;
	x.length = 0;
	x.sign = 1;
	
	return *this;
}
	
bool LongNumber::operator == (const LongNumber& x) const {
	if (sign !=x.sign)
		return false;
	
	for (int i = 0; i < length; i++)
		if (numbers[i] != x.numbers[i])
			return false;
		return true;
}

bool LongNumber::operator != (const LongNumber& x) const {
	if (*this == x) {
		return false;
	} else {
		return !(*this == x);
	}
}

bool LongNumber::operator > (const LongNumber& x) const {
	if (this == &x) {
		return false;
	}
	
	if (sign != x.sign) {
        if (sign > x.sign) {
            return true;
        } else {
            return false;
        }
    } else {
		if (length != x.length) {
			if (sign == 1) { 
				if (length > x.length) {
					return true;
				} else { 
					return false;
				}
			} else { 
				if (length < x.length) {
					return true;
				} else { 
					return false;
				}
			}
		} else {
			for (int i = length-1; i >= 0; i--) {
				if (numbers[i] != x.numbers[i]) {
					if (sign == 1) {
						return numbers[i] > x.numbers[i];
					} else {
						return numbers[i] < x.numbers[i];
					}
				}
			}
		}		 
	}
	return false;
}

bool LongNumber::operator < (const LongNumber& x) const {
	return !(*this > x);
}


LongNumber LongNumber::operator + (const LongNumber& x) const {
	LongNumber res;
	LongNumber min;
	LongNumber max;
	 
	if (sign == x.sign){
		// a + b
		if (*this > x) {
			res = LongNumber(length + 1, sign);
			min = x;
			max = *this;
		} else {
			res = LongNumber(x.length + 1, sign);			
			min = *this;
			max = x;
		}
			
		for (int i = 0; i < min.length; i++) {
			res.numbers[i] = min.numbers[i] + max.numbers[i];
		} 
        for (int i = min.length; i < max.length; i++) {
            if (length > x.length) {
				res.numbers[i] = max.numbers[i];
			}
		}
		
		for (int i = 0; i < res.length - 1; i++) {
			if (res.numbers[i] > 9) {
                res.numbers[i] -= 10;
                res.numbers[i + 1]++;
			}
		}	
	
	} else {
		// a - b
		
		LongNumber mod_x = x;
		LongNumber mod_this = *this;
		
		mod_x.sign = 1;
		mod_this.sign = 1;
		
		if (mod_this > mod_x) {
			res = LongNumber(length + 1, sign);
			min = x;
			max = *this;
		} else {	
			res = LongNumber(x.length + 1, x.sign);
			min = *this;
			max = x;
		}
		
		for (int i = 0; i < max.length; i++) {
			res.numbers[i] = max.numbers[i];
		}
		
		for (int i = 0; i < min.length; i++) {
			res.numbers[i] -= min.numbers[i];
		}
		
		for (int i = 0; i < res.length - 1; i++) {
			if (res.numbers[i] < 0) {
				res.numbers[i] += 10;
				res.numbers[i + 1]--;
			}
		}
	}

	while (res.numbers[res.length - 1] == 0 and res.length > 1) {
		res.length--;
	}
	if (res.length == 1 and res.numbers[0] == 0) {
		res.sign = 1;
	}
	return res;
}


LongNumber LongNumber::operator - (const LongNumber& x) const {
	LongNumber res = x;
	res.sign = -res.sign;
	return *this + res;
}


LongNumber LongNumber::operator * (const LongNumber& x) const {
	LongNumber res(length + x.length, sign * x.sign);
	
	for (int i = 0; i < x.length; i++) {
		for (int j = 0; j < length; j++) {
			res.numbers[i + j] += x.numbers[i] * numbers[j];
		}
	}
	for (int i = 0; i < res.length - 1; i++) {
		if (res.numbers[i] > 9) {
				res.numbers[i + 1] += res.numbers[i] / 10;
				res.numbers[i] = res.numbers[i] % 10;
		}
	}
	while (res.numbers[res.length - 1] == 0 and res.length > 1) {
		res.length--;
	}
	return res;
}

LongNumber LongNumber::operator / (const LongNumber& x) const {
	LongNumber mod_x = x;
	LongNumber dividend = *this;
	LongNumber mod_this = *this;

		
	mod_x.sign = 1;
	mod_this.sign = 1;
	
	if (mod_this < mod_x) {		
		return LongNumber("0");
	}
	
	LongNumber res(length - x.length + 1, sign * x.sign); 
		for(int i = 0; i < res.length; i++){
			LongNumber divisor = LongNumber(length - i, 1);
			
			for (int j = 0; j < x.length; j++) {
				divisor.numbers[length - x.length - i + j] = x.numbers[j];
			}
			int ch = 0;
			while (mod_this > divisor or mod_this == divisor) {
				ch++;
				mod_this = mod_this - divisor;
			}
			res.numbers[res.length - i - 1] = ch;
		}
	
	if (res.sign == -1 and dividend > 0) {
        LongNumber ooo(1, 1);
        res = res - ooo;
    }
	while (res.numbers[res.length - 1] == 0 and res.length > 1) {
		res.length--;
	}
	return res;
}


LongNumber LongNumber::operator % (const LongNumber& x) const {
	LongNumber r = *this - (*this / x) * x;
    if (r.is_negative()) {
        LongNumber mod_x = x;
        mod_x.sign = 1;
        r = r + mod_x;
    }
    return r;
}

bool LongNumber::is_negative() const noexcept {
	return (sign == -1);
}


// ----------------------------------------------------------
// PRIVATE
// ----------------------------------------------------------
int LongNumber::get_length(const char* const str) const noexcept {
	if (!str) return 0;
    int length = 0;
    while (str[length] != '\0') 
        length++;
    return length;
}

// ----------------------------------------------------------
// FRIENDLY
// ----------------------------------------------------------
namespace OLes {
	std::ostream& operator << (std::ostream &os, const LongNumber& x) {
		if (x.sign == -1) {
			os << "-";
		}
		for (int i = x.length - 1; i >= 0; i--) {
			os << x.numbers[i];
		}
		return os;
	}
}

