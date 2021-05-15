#pragma once

#include "Player.hpp"

namespace pandemic {
	class Medic : public Player {
	private:
		void treat_free();
	public:
		Medic(Board board, City city) : Player(board, city) {}
		Player& treat(City city);
		Player& drive(City city);
		Player& fly_direct(City city);
		Player& fly_charter(City city);
		Player& fly_shuttle(City city);
		std::string role()
		{
			return "Medic";
		}
	};
}
