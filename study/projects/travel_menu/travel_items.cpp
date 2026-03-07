#include "travel_items.hpp"

#include <cstddef>

#include "travel_functions.hpp"

// 3-ий уровень для "1 - Дальний Восток"
const OLes::TravelItem OLes::TRAVEL_DALVOST_VLADIVOSTOK = {
	"1 - Владивосток", OLes::travel_dalvost_vladivostok, &OLes::TRAVEL_DALVOST
};
const OLes::TravelItem OLes::TRAVEL_DALVOST_SAHALIN = {
	"2 - Сахалин", OLes::travel_dalvost_sahalin, &OLes::TRAVEL_DALVOST
};
const OLes::TravelItem OLes::TRAVEL_DALVOST_HABAROVSK = {
	"3 - Хабаровск", OLes::travel_dalvost_habarovsk, &OLes::TRAVEL_DALVOST
};
const OLes::TravelItem OLes::TRAVEL_DALVOST_BACK = {
	"0 - Выйти в предыдущее меню", OLes::travel_dalvost_back, &OLes::TRAVEL_DALVOST
};

namespace {
	const OLes::TravelItem* const travel_dalvost_children[] = { 
		&OLes::TRAVEL_DALVOST_BACK,
		&OLes::TRAVEL_DALVOST_VLADIVOSTOK,
		&OLes::TRAVEL_DALVOST_SAHALIN,
		&OLes::TRAVEL_DALVOST_HABAROVSK
	};
	const int travel_dalvost_size = sizeof(travel_dalvost_children) / sizeof(travel_dalvost_children[0]);
}


// 2-ий уровень для "1 - Путешествовать по России"
const OLes::TravelItem OLes::TRAVEL_DALVOST = {
	"1 - Дальний Восток", OLes::travel_dalvost, &OLes::TRAVEL, travel_dalvost_children, travel_dalvost_size
};
const OLes::TravelItem OLes::TRAVEL_ALTAY = {
	"2 - Алтай", OLes::travel_altay, &OLes::TRAVEL
};
const OLes::TravelItem OLes::TRAVEL_GOLDRING = {
	"3 - Золотое Кольцо России", OLes::travel_goldring, &OLes::TRAVEL
};
const OLes::TravelItem OLes::TRAVEL_BACK = {
	"0 - Выйти в главное меню", OLes::travel_back, &OLes::TRAVEL
};

namespace {
	const OLes::TravelItem* const travel_children[] = { 
		&OLes::TRAVEL_BACK,
		&OLes::TRAVEL_DALVOST,
		&OLes::TRAVEL_ALTAY,
		&OLes::TRAVEL_GOLDRING
	};
	const int travel_size = sizeof(travel_children) / sizeof(travel_children[0]);
}


// 1-ий уровень 
const OLes::TravelItem OLes::TRAVEL = {
	"1 - Путешествовать по России", OLes::travel, &OLes::MAIN, travel_children, travel_size
};
const OLes::TravelItem OLes::EXIT = {
	"0 - Закончить путешествия", OLes::exit, &OLes::MAIN
};

namespace {
	const OLes::TravelItem* const main_children[] = { 
		&OLes::EXIT,
		&OLes::TRAVEL
	};
	const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}


const OLes::TravelItem OLes::MAIN = {
	nullptr, OLes::travel_menu, nullptr, main_children, main_size 
};
	





