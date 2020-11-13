#include "TripPlanner.h"


MixedTrip::MixedTrip(Reservation* r) {
	this->setName(r->getName());
	this->setDate(r->getDate());
	this->setType(r->getType());
	this->setPrice(r->getPrice());
	this->setID(r->getID());
};

MixedTrip::MixedTrip(std::string f, std::string to, std::string t, std::string d, std::string id, float p) :
	Reservation(f, to, t, d, id, p) {};

void MixedTrip::drawSymbol() {
	std::cout << "                    ||  ||  ||                                  _             ___ " << std::endl;
	std::cout << "              ______||__||__||_________                        | \\           /  |" << std::endl;
	std::cout << "             /   ||||||||||||||||     |                 _______|__\\_________/   |" << std::endl;
	std::cout << "      \\_____/_________________________|     __       __//////    o  o  o  o  o  | " << std::endl;
	std::cout << "        \\     ...................    /   __|  |__   (___________    ____________|" << std::endl;
	std::cout << "         \\     ..................   /   |__    __|             \\  \\ " << std::endl;
	std::cout << "          \\________________________/       |__|                 \\  \\ " << std::endl;
	std::cout << "                                                                 \\__\\ " << std::endl;
}
