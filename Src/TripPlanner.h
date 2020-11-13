#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include <set>

#include "Reservation.h"
#include "User.h"
#include "Base.h"
#include "ReservationsBase.h"
#include "UsersBase.h"
#include "LinkedTrip.h"
#include "Cruise.h"
#include "Flight.h"
#include "MixedTrip.h"


void generateSpecialLinkedTrip(ReservationsBase* tripsBase);
int inputValidInteger();
void readTripsFile(ReservationsBase* tripsBase);
void readUsersFile(UsersBase* usersBase, ReservationsBase* tripsBase);
std::string inputPassword();
User* login(UsersBase* usersBase);
void seeMyReservations(User* user);
void cancelTrip(User* user);
void bookTrip(ReservationsBase* tripsBase, User* user);
void updateFile(UsersBase* usersBase);
void initialOperations(ReservationsBase* tripsBase, UsersBase* usersBase);
int main();
