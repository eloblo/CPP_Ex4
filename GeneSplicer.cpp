#include "GeneSplicer.hpp"
using namespace std;

namespace pandemic {
	Player& GeneSplicer::discover_cure(Color color)
	{
		if (board->has_cure(color)) { return *this;}
		if (!board->has_station(current_city)) { throw invalid_argument("there is no station in the city\n");} 
		if (hand.size() < card_req) {throw invalid_argument(role() + " does not have enough cards\n");}
		board->set_cure(color);
		hand.erase(hand.begin(), hand.begin() + long(card_req));
		return *this;
	}
}
