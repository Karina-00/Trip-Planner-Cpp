#pragma once


class Cruise : public Reservation {
public:
	Cruise(std::string f, std::string to, std::string t, std::string d, std::string id, float p);
	Cruise(Reservation* r);
	void drawSymbol();
};