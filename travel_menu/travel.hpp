	#pragma once
	
namespace OLes {
	struct TravelItem {
		const char* const title;
		const TravelItem* (*func)(const TravelItem* current);
		
		const TravelItem* parent;
		
		const TravelItem* const *children;
		const int children_count;
	};
}
