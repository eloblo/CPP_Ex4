#include "Virologist.hpp"
using namespace std;

namespace pandemic {
	Player& Virologist::treat(City city)
	{       //removed requiment to be near the city to treat it for discarding a fitting card
		if ((*board)[city] == 0) { throw invalid_argument("The city's desease level is 0\n"); }    //check for disease level
		Color color = board->get_color(city);                                                      //get city color
		if (city != current_city)                                                                  //check if treating current city
		{
			int loc = card_location(city);                                                     //if not check if there is a fitting card
			if (loc != -1)                                                                     //treat the city and remove the card
			{
				if (board->has_cure(color)) { (*board)[city] = 0; }
				else { (*board)[city]--; }
				hand.erase(hand.begin() + loc); 
			}
			else { throw invalid_argument(role() + " does not have a card to treat\n"); }
		}
		else                                                                                       //if the given city is the current one treat it normaly
		{
			if (board->has_cure(color)) { (*board)[current_city] = 0; }                        //check for cure of current city color and update accordingly
			else { (*board)[current_city]--; }
		}
		return *this;
	}
}
