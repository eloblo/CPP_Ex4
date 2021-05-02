#include "Researcher.hpp"
using namespace std;

namespace pandemic {
	Player& Researcher::discover_cure(Color color)
	{
		if (board->has_cure(color)) { return *this;}
		vector<City> discard(card_req);
		size_t amount = 0;
		for (City card : hand)
		{
			if (amount == card_req) { break; }
			if (color == board->get_color(card)) 
			{ 
				discard.at(amount) = card;
				amount++; 
			}
		}
		if (amount == card_req)
		{
			for (City card : discard) 
			{ 
				int loc = card_location(card);
				hand.erase(hand.begin() + loc);
			}
			board->set_cure(color);
		}
		else { throw invalid_argument(role() + " does not have enough cards\n");}
		return *this;
	}
}
