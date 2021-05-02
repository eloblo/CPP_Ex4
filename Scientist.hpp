#pragma once

#include "Player.hpp"

namespace pandemic {
	class Scientist : public Player {
	public:
		Scientist(Board board, City city) : Player(board, city) {}
		Scientist(Board board, City city, size_t num) : Player(board, city) 
		{
			if (num < card_req) { card_req = num; }
		}
		std::string role()
			{
				return "Scientist";
			}
	};
}
