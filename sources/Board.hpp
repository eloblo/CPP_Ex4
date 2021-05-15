#pragma once

#include <iostream>
#include <vector>
#include <map>
#include "Color.hpp"
#include "City.hpp"

namespace pandemic{
	class Board{
		private:
			struct city_struct {  //struct for city information
				bool research_station;              //existence of a station
				const Color color;                  //city color
				const std::vector<City> neighbors;  //list of neighboring cities
				int level;                          //disease level
			};
			std::map<City, city_struct> cities;   //map of all cities' structs 
			std::map<Color, bool> cures;          //map of cures 
			Board* addr = this;                   //address of created board. to help players' constructor recive the same board through a temporary refrence
		public:
			Board();
			Board* get_addr(){   //returns original board address
				return addr;
			}
			bool is_clean() const;                  //return if the board has no diseases
			bool within_reach(City src, City dst);  //check if a city src is neighboring city dst 
			bool has_station(City city);            //check for a station
			void build(City city);                  //build a station
			Color get_color(City city);             //return a city's color
			bool has_cure(Color color);             //return if there is a cure
			void set_cure(Color color);             //set a color's cure to true
			void remove_cures();                    //remove all cures
			void remove_stations();                 //remove all stations
			int& operator[] (City city);            //allows access to board's cities
			friend std::ostream& operator<< (std::ostream& os, const Board& board);  //prints boards information
	};
}
