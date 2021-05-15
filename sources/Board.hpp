#pragma once

#include <iostream>
#include <vector>
#include <map>
#include "Color.hpp"
#include "City.hpp"

namespace pandemic{
	class Board{
		private:
			struct city_struct {
				bool research_station;
				const Color color;
				const std::vector<City> neighbors;
				int level;
			};
			std::map<City, city_struct> cities;
			std::map<Color, bool> cures;
			Board* addr = this;
		public:
			Board();
			Board* get_addr(){
				return addr;
			}
			bool is_clean() const;
			bool within_reach(City src, City dst);
			bool has_station(City city);
			void build(City city);
			Color get_color(City city);
			bool has_cure(Color color);
			void set_cure(Color color);
			void remove_cures();
			void remove_stations();
			int& operator[] (City city);
			friend std::ostream& operator<< (std::ostream& os, const Board& board);
	};
}
