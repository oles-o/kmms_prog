#include "travel_items.hpp"
#include "travel_functions.hpp"

const OLes::TravelItem OLes::TRAVEL_DALVOST = {
	"1 - Дальний Восток", OLes::travel_dalvost, &OLes::TRAVEL
};

const OLes::TravelItem OLes::TRAVEL_ALTAY = {
	"2 - Алтай", OLes::travel_altay, &OLes::TRAVEL
};

const OLes::TravelItem OLes::TRAVEL_GOLDRING = {
	"3 - Золотое Кольцо России", OLes::travel_goldring, &OLes::TRAVEL
};

const OLes::TravelItem OLes:: = TRAVEL_BACK {
	"0 - Выйти в главное меню", OLes::travel_back, &OLes::TRAVEL
};

namespace {
	const OLes::TravelItem* const travel_rus[] = {
		&OLes::TRAVEL_BACK,
		&OLes::TRAVEL_DALVOST,
		&OLes::TRAVEL_ALTAY,
		&OLes::TRAVEL_GOLDRING
	};
	const int travel_size = sizeof(travel_rus) / sizeof(study_rus[0]);
}

const OLes::TravelItem OLes::TRAVEL = {
	"1 - Путешествовать по России", OLes::show_regs, &OLes::MAIN, travel_rus, travel_size
};
const OLes::TravelItem OLes::EXIT = {
	"0 - Закончить путешествия", OLes::exit, &OLes::MAIN
};









