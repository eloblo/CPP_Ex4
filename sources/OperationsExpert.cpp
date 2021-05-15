#include "OperationsExpert.hpp"

namespace pandemic {
	Player& OperationsExpert::build()
	{
		board->build(current_city);    //build with no limitations
		return *this;
	}
}
