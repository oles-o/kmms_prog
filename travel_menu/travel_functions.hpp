#pragma once
	
#include "travel.hpp"

namespace OLes {
	/*const TravelItem* main(const TravelItem* current);*/
	const TravelItem* travel(const TravelItem* current);
	const TravelItem* travel_menu(const TravelItem* current);
	
	const TravelItem* exit(const TravelItem* current);
	
	const TravelItem* travel_dalvost(const TravelItem* current);
	const TravelItem* travel_altay(const TravelItem* current);
	const TravelItem* travel_goldring(const TravelItem* current);
	const TravelItem* travel_back(const TravelItem* current);

	const TravelItem* travel_dalvost_vladivostok(const TravelItem* current);
	const TravelItem* travel_dalvost_sahalin(const TravelItem* current);
	const TravelItem* travel_dalvost_habarovsk(const TravelItem* current);
	const TravelItem* travel_dalvost_back(const TravelItem* current);

}	