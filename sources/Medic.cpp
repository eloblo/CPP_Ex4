#include "Medic.hpp"
using namespace std;

namespace pandemic {
	void Medic::treat_free()
	{
		Color color = board->get_color(current_city);
		if (board->has_cure(color))
		{
			(*board)[current_city] = 0;
		}
	}
	Player& Medic::treat(City city)
	{
		if (city != current_city) { throw invalid_argument(role() + "can only treat the city he is on\n"); }
		if ((*board)[current_city] == 0) { throw invalid_argument("The city's desease level is 0\n"); }
		(*board)[current_city] = 0;
		return *this;
	}
	Player& Medic::drive(City city)
	{
		if(city == current_city) { throw invalid_argument("cant drive to the same current city\n");}
		if (board->within_reach(current_city, city))
		{ 
			current_city = city; 
			treat_free();
		}
		else { throw invalid_argument("the city is not in range\n"); }
		return *this;
	}
	Player& Medic::fly_direct(City city)
	{
		if(city == current_city) { throw invalid_argument("cant fly to the same current city\n");}
		int loc = card_location(city);
		if (loc != -1)
		{
			current_city = city;
			treat_free();
			hand.erase(hand.begin() + loc);
		}
		else { throw invalid_argument(role() + " does not have the required card to fly\n"); }
		return *this;
	}
	Player& Medic::fly_charter(City city)
	{
		if(city == current_city) { throw invalid_argument("cant fly to the same current city\n");}
		int loc = card_location(current_city);
		if (loc != -1)
		{
			hand.erase(hand.begin() + loc);
			current_city = city;
			treat_free();
		}
		return *this;
	}
	Player& Medic::fly_shuttle(City city)
	{
		if(city == current_city) { throw invalid_argument("cant fly to the same current city\n");}
		if (board->has_station(current_city) && board->has_station(city)) 
		{ 
			current_city = city;
			treat_free();
		}
		return *this;
	}
}
