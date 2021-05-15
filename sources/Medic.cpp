#include "Medic.hpp"
using namespace std;

namespace pandemic {
	void Medic::treat_free()
	{       //check for a cure for the city
		Color color = board->get_color(current_city);   
		if (board->has_cure(color))
		{
			(*board)[current_city] = 0;  //if there is a cure treat the city
		}
	}
	Player& Medic::treat(City city)
	{
		if (city != current_city) { throw invalid_argument(role() + "can only treat the city he is on\n"); }   //check if validity of given city
		if ((*board)[current_city] == 0) { throw invalid_argument("The city's desease level is 0\n"); }        //check for disease level
		(*board)[current_city] = 0;                                                                            //update disease level
		return *this;
	}
	Player& Medic::drive(City city)
	{
		if(city == current_city) { throw invalid_argument("cant drive to the same current city\n");}   //check if validity of given city
		if (board->within_reach(current_city, city))                                                   
		{ 
			current_city = city;   //update location
			treat_free();          //treat automaticly if there is a cure
		}
		else { throw invalid_argument("the city is not in range\n"); }
		return *this;
	}
	Player& Medic::fly_direct(City city)
	{
		if(city == current_city) { throw invalid_argument("cant fly to the same current city\n");}     //check if validity of given city
		int loc = card_location(city);                //check if there is a fitting card
		if (loc != -1)                                //if there is remove the card and update location
		{
			current_city = city;
			treat_free();                         //treat automaticly if there is a cure
			hand.erase(hand.begin() + loc);       //remove card from hand
		}
		else { throw invalid_argument(role() + " does not have the required card to fly\n"); }
		return *this;
	}
	Player& Medic::fly_charter(City city)
	{
		if(city == current_city) { throw invalid_argument("cant fly to the same current city\n");}     //check if validity of given city
		int loc = card_location(current_city);     //check if there is a fitting card
		if (loc != -1)                             //if there is remove the card and update location
		{
			hand.erase(hand.begin() + loc);
			current_city = city;
			treat_free();                      //treat automaticly if there is a cure
		}
		return *this;
	}
	Player& Medic::fly_shuttle(City city)
	{
		if(city == current_city) { throw invalid_argument("cant fly to the same current city\n");}    //check if validity of given city
		if (board->has_station(current_city) && board->has_station(city))                             //if there are station update location
		{ 
			current_city = city;
			treat_free();         //treat automaticly if there is a cure
		}
		return *this;
	}
}
