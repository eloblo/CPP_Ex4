#include "FieldDoctor.hpp"
using namespace std;

namespace pandemic {
	Player& FieldDoctor::treat(City city) 
	{
		if (city != current_city && !board->within_reach(current_city, city)) { throw invalid_argument(role() + "can only treat the cities close to him\n"); }
		if ((*board)[city] == 0) { throw invalid_argument("The city's desease level is 0\n"); }
		Color color = board->get_color(city);
		if (board->has_cure(color)) { (*board)[city] = 0; }
		else { (*board)[city]--; }
		return *this;
	}
}
