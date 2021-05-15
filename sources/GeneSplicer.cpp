#include "GeneSplicer.hpp"
using namespace std;

namespace pandemic {
	Player& GeneSplicer::discover_cure(Color color)
	{
		if (board->has_cure(color)) { return *this;}                                                            //if there is already a cure do nothing
		if (!board->has_station(current_city)) { throw invalid_argument("there is no station in the city\n");}  //check for station existence
		if (hand.size() < card_req) {throw invalid_argument(role() + " does not have enough cards\n");}         //check if tge player has enough cards to discard
		board->set_cure(color);                                                                                 //update color's cure
		hand.erase(hand.begin(), hand.begin() + long(card_req));                                                //discard cards
		return *this;
	}
}
