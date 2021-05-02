#include "Board.hpp"
using namespace std;

namespace pandemic{
	Board::Board()
	{
		cures = { {Color::Red, false}, {Color::Black, false}, {Color::Blue, false}, {Color::Yellow, false} };
		
		cities.insert(pair<City,city_struct> (City::Algiers, city_struct{ false, Color::Black, vector<City>{City::Madrid, City::Paris, City::Istanbul, City::Cairo}, 0 }));
		cities.insert(pair<City,city_struct> (City::Atlanta, city_struct{ false, Color::Blue, vector<City>{City::Chicago, City::Miami, City::Washington}, 0 }));
		cities.insert(pair<City,city_struct> (City::Baghdad, city_struct{ false, Color::Black, vector<City>{City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi}, 0 }));
		cities.insert(pair<City,city_struct> (City::Bangkok, city_struct{ false, Color::Red, vector<City>{City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong}, 0 }));
		cities.insert(pair<City,city_struct> (City::Beijing, city_struct{ false, Color::Red, vector<City>{City::Shanghai, City::Seoul}, 0 }));
		cities.insert(pair<City,city_struct> (City::Bogota, city_struct{ false, Color::Yellow, vector<City>{City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires}, 0 }));
		cities.insert(pair<City,city_struct> (City::BuenosAires, city_struct{ false, Color::Yellow, vector<City>{City::Bogota, City::SaoPaulo}, 0 }));
		cities.insert(pair<City,city_struct> (City::Cairo, city_struct{ false, Color::Black, vector<City>{City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh}, 0 }));
		cities.insert(pair<City,city_struct> (City::Chennai, city_struct{ false, Color::Black, vector<City>{City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta}, 0 }));
		cities.insert(pair<City,city_struct> (City::Chicago, city_struct{ false, Color::Blue, vector<City>{City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal}, 0 }));
		cities.insert(pair<City,city_struct> (City::Delhi, city_struct{ false, Color::Black, vector<City>{City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata}, 0 }));
		cities.insert(pair<City,city_struct> (City::Essen, city_struct{ false, Color::Blue, vector<City>{City::London, City::Paris, City::Milan, City::StPetersburg}, 0 }));
		cities.insert(pair<City,city_struct> (City::HoChiMinhCity, city_struct{ false, Color::Red, vector<City>{City::Jakarta, City::Bangkok, City::HongKong, City::Manila}, 0 }));
		cities.insert(pair<City,city_struct> (City::HongKong, city_struct{ false, Color::Red, vector<City>{City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei}, 0 }));
		cities.insert(pair<City,city_struct> (City::Istanbul, city_struct{ false, Color::Black, vector<City>{City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow}, 0 }));
		cities.insert(pair<City,city_struct> (City::Jakarta, city_struct{ false, Color::Red, vector<City>{City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney}, 0 }));
		cities.insert(pair<City,city_struct> (City::Johannesburg, city_struct{ false, Color::Yellow, vector<City>{City::Kinshasa, City::Khartoum}, 0 }));
		cities.insert(pair<City,city_struct> (City::Karachi, city_struct{ false, Color::Black, vector<City>{City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi}, 0 }));
		cities.insert(pair<City,city_struct> (City::Khartoum, city_struct{ false, Color::Yellow, vector<City>{City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg}, 0 }));
		cities.insert(pair<City,city_struct> (City::Kinshasa, city_struct{ false, Color::Yellow, vector<City>{City::Lagos, City::Khartoum, City::Johannesburg}, 0 }));
		cities.insert(pair<City,city_struct> (City::Kolkata, city_struct{ false, Color::Black, vector<City>{City::Delhi, City::Chennai, City::Bangkok, City::HongKong}, 0 }));
		cities.insert(pair<City,city_struct> (City::Lagos, city_struct{ false, Color::Yellow, vector<City>{City::SaoPaulo, City::Khartoum, City::Kinshasa}, 0 }));
		cities.insert(pair<City,city_struct> (City::Lima, city_struct{ false, Color::Yellow, vector<City>{City::MexicoCity, City::Bogota, City::Santiago}, 0 }));
		cities.insert(pair<City,city_struct> (City::London, city_struct{ false, Color::Blue, vector<City>{City::NewYork, City::Madrid, City::Essen, City::Paris}, 0 }));
		cities.insert(pair<City,city_struct> (City::LosAngeles, city_struct{ false, Color::Yellow, vector<City>{City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney}, 0 }));
		cities.insert(pair<City,city_struct> (City::Madrid, city_struct{ false, Color::Blue, vector<City>{City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers}, 0 }));
		cities.insert(pair<City,city_struct> (City::Manila, city_struct{ false, Color::Red, vector<City>{City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney}, 0 }));
		cities.insert(pair<City,city_struct> (City::MexicoCity, city_struct{ false, Color::Yellow, vector<City>{City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota}, 0 }));
		cities.insert(pair<City,city_struct> (City::Miami, city_struct{ false, Color::Yellow, vector<City>{City::Atlanta, City::MexicoCity, City::Washington, City::Bogota}, 0 }));
		cities.insert(pair<City,city_struct> (City::Milan, city_struct{ false, Color::Blue, vector<City>{City::Essen, City::Paris, City::Istanbul}, 0 }));
		cities.insert(pair<City,city_struct> (City::Montreal, city_struct{ false, Color::Blue, vector<City>{City::Chicago, City::Washington, City::NewYork}, 0 }));
		cities.insert(pair<City,city_struct> (City::Moscow, city_struct{ false, Color::Black, vector<City>{City::StPetersburg, City::Istanbul, City::Tehran}, 0 }));
		cities.insert(pair<City,city_struct> (City::Mumbai, city_struct{ false, Color::Black, vector<City>{City::Karachi, City::Delhi, City::Chennai}, 0 }));
		cities.insert(pair<City,city_struct> (City::NewYork, city_struct{ false, Color::Blue, vector<City>{City::Montreal, City::Washington, City::London, City::Madrid}, 0 }));
		cities.insert(pair<City,city_struct> (City::Osaka, city_struct{ false, Color::Red, vector<City>{City::Taipei, City::Tokyo}, 0 }));
		cities.insert(pair<City,city_struct> (City::Paris, city_struct{ false, Color::Blue, vector<City>{City::Algiers, City::Essen, City::Madrid, City::Milan, City::London}, 0 }));
		cities.insert(pair<City,city_struct> (City::Riyadh, city_struct{ false, Color::Black, vector<City>{City::Baghdad, City::Cairo, City::Karachi}, 0 }));
		cities.insert(pair<City,city_struct> (City::SanFrancisco, city_struct{ false, Color::Blue, vector<City>{City::LosAngeles, City::Chicago, City::Tokyo, City::Manila}, 0 }));
		cities.insert(pair<City,city_struct> (City::Santiago, city_struct{ false, Color::Yellow, vector<City>{City::Lima}, 0 }));
		cities.insert(pair<City,city_struct> (City::SaoPaulo, city_struct{ false, Color::Yellow, vector<City>{City::Bogota, City::BuenosAires, City::Lagos, City::Madrid}, 0 }));
		cities.insert(pair<City,city_struct> (City::Seoul, city_struct{ false, Color::Red, vector<City>{City::Beijing, City::Shanghai, City::Tokyo}, 0 }));
		cities.insert(pair<City,city_struct> (City::Shanghai, city_struct{ false, Color::Red, vector<City>{City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo}, 0 }));
		cities.insert(pair<City,city_struct> (City::StPetersburg, city_struct{ false, Color::Blue, vector<City>{City::Essen, City::Istanbul, City::Moscow}, 0 }));
		cities.insert(pair<City,city_struct> (City::Sydney, city_struct{ false, Color::Red, vector<City>{City::Jakarta, City::Manila, City::LosAngeles}, 0 }));
		cities.insert(pair<City,city_struct> (City::Taipei, city_struct{ false, Color::Red, vector<City>{City::Shanghai, City::HongKong, City::Osaka, City::Manila}, 0 }));
		cities.insert(pair<City,city_struct> (City::Tehran, city_struct{ false, Color::Black, vector<City>{City::Baghdad, City::Moscow, City::Karachi, City::Delhi}, 0 }));
		cities.insert(pair<City,city_struct> (City::Tokyo, city_struct{ false, Color::Red, vector<City>{City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco}, 0 }));
		cities.insert(pair<City,city_struct> (City::Washington, city_struct{ false, Color::Blue, vector<City>{City::Atlanta, City::NewYork, City::Montreal, City::Miami}, 0 }));
	}
	bool Board::is_clean() const
	{
		for (const pair<const City,city_struct> &it : cities)
		{
			if (it.second.level != 0) { return false; }
		}
		return true;
	}
	bool Board::within_reach(City src, City dst)
	{
		for (City ct : cities.at(src).neighbors)
		{
			if (ct == dst) { return true; }
		}
		return false;
	}
	bool Board::has_station(City city)
	{
		return cities.at(city).research_station;
	}
	void Board::build(City city)
	{
		cities.at(city).research_station = true;
	}
	Color Board::get_color(City city)
	{
		return cities.at(city).color;
	}
	bool Board::has_cure(Color color)
	{
		return cures.at(color);
	}
	void Board::set_cure(Color color)
	{
		cures.at(color) = true;
	}
	unsigned int& Board::operator[](City city)
	{
		return cities.at(city).level;
	}
	std::ostream& operator<<(std::ostream& os, const Board& board)
	{
		os << boolalpha;
		os << "The board is clear: " << board.is_clean() << "\n";
		cout << "Avaible cures : Red - " << board.cures.at(Color::Red) << ", Yellow - " << board.cures.at(Color::Yellow) << ", Black - " << board.cures.at(Color::Black) << ", Blue - " << board.cures.at(Color::Blue) << "\n";
		return os;
	}
}
