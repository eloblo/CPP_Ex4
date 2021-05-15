#include "Virologist.hpp"
using namespace std;

namespace pandemic {
	Player& Virologist::treat(City city)
	{
		if ((*board)[city] == 0) { throw invalid_argument("The city's desease level is 0\n"); }
		Color color = board->get_color(city);
		if (city != current_city)
		{
			int loc = card_location(city);
			if (loc != -1)
			{
				if (board->has_cure(color)) { (*board)[city] = 0; }
				else { (*board)[city]--; }
				hand.erase(hand.begin() + loc); 
			}
			else { throw invalid_argument(role() + " does not have a card to treat\n"); }
		}
		else
		{
			if (board->has_cure(color)) { (*board)[current_city] = 0; }
			else { (*board)[current_city]--; }
		}
		return *this;
	}
}
