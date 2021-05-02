#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
using namespace pandemic;

#include <string>
using namespace std;

void draw(Player& player) {
	player.take_card(City::Sydney)
	      .take_card(City::Seoul)
	      .take_card(City::HoChiMinhCity)
	      .take_card(City::HongKong)
	      .take_card(City::Bangkok);
}

TEST_CASE("board functions"){
	Board b;
	CHECK(b.is_clean() == true);
	b[City::London] = 5;
	CHECK(b[City::London] == 5);
	CHECK(b.is_clean() == false);
	
	CHECK(b.within_reach(City::Tokyo,City::Seoul) == true);
	CHECK(b.within_reach(City::Tokyo,City::London) == false);
	
	b.build(City::London);
	CHECK(b.has_station(City::London) == true);
	CHECK(b.has_station(City::Essen) == false);
	
	CHECK(b.get_color(City::Tokyo) == Color::Red);
	
	CHECK(b.has_cure(Color::Red) == false);
	b.set_cure(Color::Red);
	CHECK(b.has_cure(Color::Red) == true);
}

TEST_CASE("player drive"){
	Board b;
	Player player(b, City::Atlanta);
	
	CHECK_THROWS(player.drive(City::London));
	CHECK_NOTHROW(player.drive(City::Miami));
}

TEST_CASE("player fly direct"){
	Board b;
	Player player(b, City::Atlanta);
	
	CHECK_THROWS(player.fly_direct(City::London));
	player.take_card(City::London).take_card(City::Seoul);
	CHECK_NOTHROW(player.fly_direct(City::London));
	CHECK_NOTHROW(player.fly_direct(City::Seoul));
	CHECK_THROWS(player.fly_direct(City::London));	
}

TEST_CASE("player fly charter"){
	Board b;
	Player player(b, City::Seoul);
	
	CHECK_THROWS(player.fly_charter(City::London));
	player.take_card(City::Seoul);
	CHECK_NOTHROW(player.fly_charter(City::London));
	CHECK_THROWS(player.fly_charter(City::Tokyo));	
}

TEST_CASE("player build"){
	Board b;
	Player player(b, City::Seoul);
	
	CHECK_THROWS(player.build());
	player.take_card(City::Seoul);
	CHECK_NOTHROW(player.build());
}

TEST_CASE("player fly shuttle"){
	Board b;
	Player player1(b, City::Seoul);
	Player player2(b, City::Essen);
	player1.take_card(City::Seoul).build();
	player2.take_card(City::Essen).build();
	
	CHECK_NOTHROW(player1.fly_shuttle(City::Essen).fly_shuttle(City::Seoul));
	CHECK_NOTHROW(player2.fly_shuttle(City::Seoul).fly_shuttle(City::Essen));
	CHECK_THROWS(player1.fly_shuttle(City::London));
}

TEST_CASE("player discover cure"){
	Board b;
	Player player(b, City::Seoul);
	draw(player);
	
	CHECK_THROWS(player.discover_cure(Color::Red));
	player.build();
	CHECK_THROWS(player.discover_cure(Color::Red));
	player.take_card(City::Seoul);
	CHECK_NOTHROW(player.discover_cure(Color::Red));
}

TEST_CASE("player treat"){
	Board b;
	b[City::Seoul] = 2;
	b[City::Tokyo] = 10;
	Player player(b, City::Seoul);
	
	player.treat(City::Seoul);
	CHECK(b[City::Seoul] == 1);
	player.treat(City::Seoul);
	CHECK(b[City::Seoul] == 0);
	CHECK_THROWS(player.treat(City::Seoul));
	
	player.drive(City::Tokyo);
	draw(player);
	player.take_card(City::Tokyo);
	player.build();
	player.discover_cure(Color::Red);
	player.treat(City::Tokyo);
	CHECK(b[City::Tokyo] == 0);
}

TEST_CASE("Roles") {
	Board b;
	Player player(b, City::Atlanta);
	Researcher researcher(b, City::Atlanta);
	Scientist scientist(b, City::Atlanta);
	FieldDoctor fieldDoctor(b, City::Atlanta);
	GeneSplicer geneSplicer(b, City::Atlanta);
	OperationsExpert operationsExpert(b, City::Atlanta);
	Medic medic(b, City::Atlanta);
	Virologist virologist(b, City::Atlanta);
	Dispatcher dispatcher(b, City::Atlanta);
	CHECK(player.role() == "Player");
	CHECK(dispatcher.role() == "Dispatcher");
	CHECK(researcher.role() == "Researcher");
	CHECK(scientist.role() == "Scientist");
	CHECK(fieldDoctor.role() == "FieldDoctor");
	CHECK(geneSplicer.role() == "GeneSplicer");
	CHECK(operationsExpert.role() == "OperationsExpert");
	CHECK(medic.role() == "Medic");
	CHECK(virologist.role() == "Virologist");
}

TEST_CASE("dispatcher"){
	Board b;
	Dispatcher player(b, City::Seoul);
	b.build(City::Seoul);
	CHECK_NOTHROW(player.fly_direct(City::London));
	CHECK_THROWS(player.fly_direct(City::Miami));
}

TEST_CASE("field doctor"){
	Board b;
	b[City::Tokyo] = 3;
	b[City::London] = 3;
	FieldDoctor player(b, City::Seoul);
	CHECK_NOTHROW(player.treat(City::Tokyo));
	CHECK(b[City::Tokyo] == 2);
	CHECK_THROWS(player.treat(City::London));
	b.set_cure(Color::Red);
	player.treat(City::Tokyo);
	CHECK(b[City::Tokyo] == 0);
}

TEST_CASE("gene splicer"){
	Board b;
	b.build(City::Seoul);
	GeneSplicer player(b, City::Seoul);
	player.take_card(City::London).take_card(City::Tokyo).take_card(City::Cairo).take_card(City::Seoul).take_card(City::Essen);
	CHECK_NOTHROW(player.discover_cure(Color::Red));
	CHECK_THROWS(player.discover_cure(Color::Blue));
}

TEST_CASE("medic"){
	Board b;
	b[City::Seoul] = 10;
	b[City::London] = 10;
	b[City::Tokyo] = 10;
	b[City::Essen] = 10;
	b[City::Cairo] = 10;
	Medic player(b, City::Seoul);
	player.treat(City::Seoul);
	CHECK(b[City::Seoul] == 0);
	b.set_cure(Color::Red);
	b.set_cure(Color::Blue);
	b.set_cure(Color::Black);
	player.drive(City::Tokyo);
	player.take_card(City::Tokyo).take_card(City::Cairo);
	player.fly_charter(City::Essen);
	player.fly_direct(City::Cairo);
	b.build(City::Cairo);
	b.build(City::London);
	player.fly_shuttle(City::London);
	CHECK(b[City::London] == 0);
	CHECK(b[City::Tokyo] == 0);
	CHECK(b[City::Essen] == 0);
	CHECK(b[City::Cairo] == 0);
}

TEST_CASE("operations expert"){
	Board b;
	OperationsExpert player(b, City::Seoul);
	CHECK_NOTHROW(player.build());
}

TEST_CASE("researcher"){
	Board b;
	Researcher player(b, City::Seoul);
	draw(player);
	CHECK_NOTHROW(player.discover_cure(Color::Red));
	CHECK(b.has_cure(Color::Red) == true);
}

TEST_CASE("scientist"){
	Board b;
	Scientist player(b, City::Seoul,2);
	b.build(City::Seoul);
	player.take_card(City::Seoul).take_card(City::Tokyo);
	CHECK_NOTHROW(player.discover_cure(Color::Red));
	CHECK(b.has_cure(Color::Red) == true);
}

TEST_CASE("virologist"){
	Board b;
	b[City::London] = 5;
	b[City::Essen] = 5;
	Virologist player(b, City::Seoul);
	player.take_card(City::London);
	CHECK_NOTHROW(player.treat(City::London));
	CHECK(b[City::London] == 4);
	CHECK_THROWS(player.treat(City::Essen));
}



