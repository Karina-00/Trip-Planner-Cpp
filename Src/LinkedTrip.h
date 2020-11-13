#pragma once


class LinkedTrip : public Base <Reservation>, public Reservation {
public:
	void updateAttributes();
	void operator+=(Reservation* newTrip);
};
