#pragma once


class Reservation {
	std::string from, to, type, date, tripId;
	std::string name = from + " - " + to;
	float price;

public:
	Reservation() {};
	Reservation(std::string f, std::string to, std::string t, std::string d, std::string id, float p);

	std::string getName();
	std::string getType();
	std::string getDate();
	std::string getID();
	float getPrice();
	void setName(std::string newName);
	void setType(std::string newType);
	void setDate(std::string newDate);
	void setID(std::string newId);
	void setPrice(float newPrice);
	virtual void drawSymbol() {};
};
