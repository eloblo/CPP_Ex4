#pragma once

#include <string>
#include <vector>
#include "Board.hpp"

namespace pandemic{
	class Player{
		protected:
			Board* board;                  //pointer to the given board
			int card_req = 5;              //minimum number of cards to discover a cure
			City current_city;             //player current location
			std::vector<City> hand;        //the cards the player has
			int card_location(City city);  //the location of a card in player's hand
		public:
			Player(Board& b, City city);                   
			virtual Player& drive(City city);
			virtual Player& fly_direct(City city);
			virtual Player& fly_charter(City city);
			virtual Player& fly_shuttle(City city);
			virtual Player& build();
			virtual Player& discover_cure(Color color);
			virtual Player& treat(City city);
			virtual std::string role()
			{
				return "Player";
			}
			Player& take_card(City city);
			void remove_cards();
	};
}
