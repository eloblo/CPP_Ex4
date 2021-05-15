#include "FieldDoctor.hpp"
using namespace std;

namespace pandemic {
	Player& FieldDoctor::treat(City city) 
	{
		//allows the option to check if the given city is within reach to treat it
		if (city != current_city && !board->within_reach(current_city, city)) { throw invalid_argument(role() + "can only treat the cities close to him\n"); }
		if ((*board)[city] == 0) { throw invalid_argument("The city's desease level is 0\n"); }    //check for disease level
		Color color = board->get_color(city);
		if (board->has_cure(color)) { (*board)[city] = 0; }    //check for cure of current city color and update accordingly
		else { (*board)[city]--; }
		return *this;
	}
}
