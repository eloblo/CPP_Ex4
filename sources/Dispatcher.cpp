#include "Dispatcher.hpp"
using namespace std;

namespace pandemic {
	Player& Dispatcher::fly_direct(City city)
	{
		if(city == current_city) { throw invalid_argument("cant fly to the same current city\n");}
		if (board->has_station(current_city)) { current_city = city; }
		else 
		{
			int loc = card_location(city);
			if (loc != -1)
			{
				current_city = city;
				hand.erase(hand.begin() + loc);
			}
			else { throw invalid_argument(role() + " does not have the required card to fly\n"); }
		}
		return *this;
	}
}
