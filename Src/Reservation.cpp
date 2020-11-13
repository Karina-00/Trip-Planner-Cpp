#include "TripPlanner.h"


Reservation::Reservation(std::string f, std::string to, std::string t, std::string d, std::string id, float p) :
	from(f), to(to), type(t), date(d), tripId(id), price(p) {};

std::string Reservation::getName() {
	return name;
}

std::string Reservation::getType() {
	return type;
}

std::string Reservation::getDate() {
	return date;
}

std::string Reservation::getID() {
	return tripId;
}

float Reservation::getPrice() {
	return price;
}

void Reservation::setName(std::string newName) {
	name = newName;
}

void Reservation::setType(std::string newType) {
	type = newType;
}

void Reservation::setDate(std::string newDate) {
	date = newDate;
}

void Reservation::setID(std::string newId) {
	tripId = newId;
}

void Reservation::setPrice(float newPrice) {
	price = newPrice;
}
