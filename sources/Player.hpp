#pragma once

#include <string>
#include <vector>
#include "Board.hpp"

namespace pandemic{
	class Player{
		protected:
			Board* board;
			int card_req = 5;
			City current_city;
			std::vector<City> hand;
			int card_location(City city);
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
