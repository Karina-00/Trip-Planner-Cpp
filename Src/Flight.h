#pragma once

class Flight : public Reservation {
public:
	Flight(Reservation* r);
	Flight(std::string f, std::string to, std::string t, std::string d, std::string id, float p);
	void drawSymbol();
};