#pragma once

#include "Player.hpp"

namespace pandemic {
	class Scientist : public Player {
	public:
		Scientist(Board board, City city) : Player(board, city) {}
		Scientist(Board board, City city, int num) : Player(board, city) 
		{
			if (num < 5) {
			 	card_req = num; 
			 }
			 else if(num < 1){
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
