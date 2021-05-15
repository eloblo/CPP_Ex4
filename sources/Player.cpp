#include <stdexcept>
using namespace std;
#include "Player.hpp"

namespace pandemic{

	Player::Player(Board& b, City city) : current_city(city) { board = b.get_addr();}     //get the address from the original board
	
	Player& Player::drive(City city)
	{
		if(city == current_city) { throw invalid_argument("cant drive to the same current city\n");}   //check if validity of given city
		if(board->within_reach(current_city, city)){ current_city = city;}                             //update location if city is within reach
		else { throw invalid_argument("the city is not in range\n"); }
		return *this;
	}
	
	int Player::card_location(City city)   //returns the cards location or -1 if not found
	{
		for(int i = 0; i < hand.size(); i++)
		{
			if(hand.at(size_t(i)) == city){ return i;}
		}
		return -1;
	}
	
	Player& Player::fly_direct(City city)
	{
		if(city == current_city) { throw invalid_argument("cant fly to the same current city\n");}  //check if validity of given city
		int loc = card_location(city);   //check if there is a fitting card
		if(loc != -1)                    //if there is remove the card and update location
		{
			current_city = city;
			hand.erase(hand.begin() + loc); 
		}
		else { throw invalid_argument(role() + " does not have the required card to fly\n"); }
		return *this;
	}
	Player& Player::fly_charter(City city)
	{
		if(city == current_city) { throw invalid_argument("cant fly to the same current city\n");}  //check if validity of given city
		int loc = card_location(current_city);   //check if there is a fitting card
		if (loc != -1)                           //if there is remove the card and update location
		{
			hand.erase(hand.begin() + loc);
			current_city = city;
		}
		else { throw invalid_argument(role() + " does not have the required card to fly\n"); }
		return *this;

	}
	Player& Player::fly_shuttle(City city)
	{
		if(city == current_city) { throw invalid_argument("cant fly to the same current city\n");}   //check if validity of given city
		if (board->has_station(current_city) && board->has_station(city)) { current_city = city; }   //if there are station update location
		else { throw invalid_argument("there is no shuttle fliets\n"); }
		return *this;
	}
	Player& Player::build()
	{
		if(board->has_station(current_city)) { return *this;}  //if there is already a station do nothing
		int loc = card_location(current_city);    //check if the player has the fitting card
		if (loc != -1)                            //remove card from hand and build the station
		{
			board->build(current_city);
			hand.erase(hand.begin() + loc);
		}
		else { throw invalid_argument(role() + " does not have the required card to build\n"); }
		return *this;
	}
	Player& Player::discover_cure(Color color)
	{
		if (board->has_cure(color)) { return *this;}   //if there is already a cure do nothing
		if (!board->has_station(current_city)) { throw invalid_argument("there is no station in the city\n");}   //check for station existence
		vector<City> discard((size_t)card_req); //a discard pile for removing the fitting cards
		size_t amount = 0;                      //discard size
		for (City card : hand)                  //loop for every card in hand
		{
			if (amount == card_req) { break; }   //if discard pile is full stop searching
			if (color == board->get_color(card)) //if the card is the right color put him in the discard pile
			{ 
				discard.at(amount) = card;
				amount++; 
			}
		}
		if (amount == card_req)   //if the discard is full remove the cards from the hand and set a cure to true
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
		if (city != current_city) { throw invalid_argument(role() + " can only treat the city he is on\n"); }  //check if validity of given city
		if((*board)[current_city] == 0){ throw invalid_argument("The city's desease level is 0\n"); }          //check for disease level
		Color color = board->get_color(current_city);                  //get city color
		if (board->has_cure(color)) { (*board)[current_city] = 0; }    //check for cure of current city color and update accordingly
		else { (*board)[current_city]--; }                             //reduce the disease level
		return *this;
	}
	Player& Player::take_card(City city)
	{
		int loc = card_location(city);          //check if given card is at hand
		if(loc == -1) { hand.push_back(city);}  //if not add the card
		return *this;
	}
	void Player::remove_cards()   //clears hand
	{
		hand.clear();
	}
}
