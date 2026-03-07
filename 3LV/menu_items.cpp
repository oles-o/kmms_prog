#include "menu_items.hpp"

#include <cstddef>

#include "menu_functions.hpp"

// 3-ий уровень для "1 - Хочу изучать алгебру!"
const OLes::MenuItem OLes::ALGEBRA_SUMM = {
	"1 - Хочу научиться складывать!", OLes::algebra_summ, &OLes::STUDY_ALGEBRA
};
const OLes::MenuItem OLes::ALGEBRA_SUBSTRACT = {
	"2 - Хочу научиться вычитать!", OLes::algebra_substract, &OLes::STUDY_ALGEBRA
};
const OLes::MenuItem OLes::ALGEBRA_MULTIPLY = {
	"3 - Хочу научиться умножать!", OLes::algebra_multiply, &OLes::STUDY_ALGEBRA
};
const OLes::MenuItem OLes::ALGEBRA_DIVIDE = {
	"4 - Хочу научиться делить!", OLes::algebra_divide, &OLes::STUDY_ALGEBRA
};
const OLes::MenuItem OLes::ALGEBRA_GO_BACK = {
	"0 - Вернуться к выбору предметов.", OLes::algebra_go_back, &OLes::STUDY_ALGEBRA
};

namespace {
	const OLes::MenuItem* const algebra_children[] = { 
		&OLes::ALGEBRA_GO_BACK,
		&OLes::ALGEBRA_SUMM,
		&OLes::ALGEBRA_SUBSTRACT,
		&OLes::ALGEBRA_MULTIPLY,
		&OLes::ALGEBRA_DIVIDE
	};
	const int algebra_size = sizeof(algebra_children) / sizeof(algebra_children[0]);
}


// 3-ий уровень для "2 - Хочу изучать математический анализ!!"
const OLes::MenuItem OLes::MATAN_DIFF = {
	"1 - Хочу изучить дифференциальное исчисление!", OLes::matan_diff, &OLes::STUDY_MATAN
};
const OLes::MenuItem OLes::MATAN_INT = {
	"2 - Хочу изучить интегральное исчисление!", OLes::matan_int, &OLes::STUDY_MATAN
};
const OLes::MenuItem OLes::MATAN_GO_BACK = {
	"0 - Вернуться к выбору предметов.", OLes::matan_go_back, &OLes::STUDY_MATAN
};

namespace {
	const OLes::MenuItem* const matan_children[] = { 
		&OLes::MATAN_GO_BACK,
		&OLes::MATAN_DIFF,
		&OLes::MATAN_INT
	};
	const int matan_size = sizeof(matan_children) / sizeof(matan_children[0]);
}


// 2-ий уровень для "1 - Хочу учиться математике!""
const OLes::MenuItem OLes::STUDY_ALGEBRA = {
	"1 - Хочу изучать алгебру!", OLes::study_algebra, &OLes::STUDY, algebra_children, algebra_size
};
const OLes::MenuItem OLes::STUDY_MATAN = {
	"2 - Хочу изучать математический анализ!", OLes::study_matan, &OLes::STUDY, matan_children, matan_size
};
const OLes::MenuItem OLes::STUDY_GO_BACK = {
	"0 - Выйти в главное меню", OLes::study_go_back, &OLes::STUDY
};

namespace {
	const OLes::MenuItem* const study_children[] = { 
		&OLes::STUDY_GO_BACK,
		&OLes::STUDY_ALGEBRA,
		&OLes::STUDY_MATAN
	};
	const int study_size = sizeof(study_children) / sizeof(study_children[0]);
}


// 1-ий уровень 
const OLes::MenuItem OLes::STUDY = {
	"1 - Хочу учиться математике!", OLes::show_menu, &OLes::MAIN, study_children, study_size
};
const OLes::MenuItem OLes::EXIT = {
	"0 - Я лучше пойду полежу...", OLes::exit, &OLes::MAIN
};

namespace {
	const OLes::MenuItem* const main_children[] = { 
		&OLes::EXIT,
		&OLes::STUDY
	};
	const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const OLes::MenuItem OLes::MAIN = {
	nullptr, OLes::show_menu, nullptr, main_children, main_size 
};
	