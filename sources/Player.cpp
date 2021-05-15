#include <stdexcept>
using namespace std;
#include "Player.hpp"

namespace pandemic{

	Player::Player(Board& b, City city) : current_city(city) { board = b.get_addr();}
	
	Player& Player::drive(City city)
	{
		if(city == current_city) { throw invalid_argument("cant drive to the same current city\n");}
		if(board->within_reach(current_city, city)){ current_city = city;}
		else { throw invalid_argument("the city is not in range\n"); }
		return *this;
	}
	
	int Player::card_location(City city)
	{
		for(int i = 0; i < hand.size(); i++)
		{
			if(hand.at(size_t(i)) == city){ return i;}
		}
		return -1;
	}
	
	Player& Player::fly_direct(City city)
	{
		if(city == current_city) { throw invalid_argument("cant fly to the same current city\n");}
		int loc = card_location(city);
		if(loc != -1)
		{
			current_city = city;
			hand.erase(hand.begin() + loc); 
		}
		else { throw invalid_argument(role() + " does not have the required card to fly\n"); }
		return *this;
	}
	Player& Player::fly_charter(City city)
	{
		if(city == current_city) { throw invalid_argument("cant fly to the same current city\n");}
		int loc = card_location(current_city);
		if (loc != -1) 
		{
			hand.erase(hand.begin() + loc);
			current_city = city;
		}
		else { throw invalid_argument(role() + " does not have the required card to fly\n"); }
		return *this;

	}
	Player& Player::fly_shuttle(City city)
	{
		if(city == current_city) { throw invalid_argument("cant fly to the same current city\n");}
		if (board->has_station(current_city) && board->has_station(city)) { current_city = city; }
		else { throw invalid_argument("there is no shuttle fliets\n"); }
		return *this;
	}
	Player& Player::build()
	{
		if(board->has_station(current_city)) { return *this;}
		int loc = card_location(current_city);
		if (loc != -1)
		{
			board->build(current_city);
			hand.erase(hand.begin() + loc);
		}
		else { throw invalid_argument(role() + " does not have the required card to build\n"); }
		return *this;
	}
	Player& Player::discover_cure(Color color)
	{
		if (board->has_cure(color)) { return *this;}
		if (!board->has_station(current_city)) { throw invalid_argument("there is no station in the city\n");} 
		vector<City> discard((size_t)card_req);
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
	Player& Player::treat(City city)
	{
		if (city != current_city) { throw invalid_argument(role() + " can only treat the city he is on\n"); }
		if((*board)[current_city] == 0){ throw invalid_argument("The city's desease level is 0\n"); }
		Color color = board->get_color(current_city);
		if (board->has_cure(color)) { (*board)[current_city] = 0; }
		else { (*board)[current_city]--; }
		return *this;
	}
	Player& Player::take_card(City city)
	{
		int loc = card_location(city);
		if(loc == -1) { hand.push_back(city);}
		return *this;
	}
	void Player::remove_cards()
	{
		hand.clear();
	}
}
