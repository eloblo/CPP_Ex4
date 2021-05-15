#pragma once

#include "Player.hpp"

namespace pandemic {
	class Scientist : public Player {
	public:
		Scientist(Board board, City city) : Player(board, city) {}
		Scientist(Board board, City city, int num) : Player(board, city)   //new constructor to set required number of cards to discover
		{
			if (num < card_req) {            //update only if bum is lower than the default number
			 	card_req = num; 
			 }
			 else if(num < 1){               //number of cards need to be at least 1
			 	card_req = 1;
			 }
		}
		Player& discover_cure(Color color);
		std::string role()
			{
				return "Scientist";
			}
	};
}
