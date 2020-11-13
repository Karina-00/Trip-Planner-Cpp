#pragma once

class MixedTrip : public Reservation {
public:
	MixedTrip(Reservation* r);
	MixedTrip(std::string f, std::string to, std::string t, std::string d, std::string id, float p);
	void drawSymbol();
};
