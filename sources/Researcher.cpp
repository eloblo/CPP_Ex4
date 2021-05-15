#include "Researcher.hpp"
using namespace std;

namespace pandemic {
	Player& Researcher::discover_cure(Color color)
	{       //removed check for existing station
		if (board->has_cure(color)) { return *this;}     //if there is already a cure do nothing
		vector<City> discard((size_t)card_req);          //a discard pile for removing the fitting cards
		size_t amount = 0;                               //discard size
		for (City card : hand)                           //loop for every card in hand
		{
			if (amount == card_req) { break; }        //if discard pile is full stop searching
			if (color == board->get_color(card))      //if the card is the right color put him in the discard pile
			{ 
				discard.at(amount) = card;
				amount++; 
			}
		}
		if (amount == card_req)                          //if the discard is full remove the cards from the hand and set a cure to true
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
