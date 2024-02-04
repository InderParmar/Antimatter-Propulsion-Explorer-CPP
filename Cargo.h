/* #include "Payload.cpp"
#include "Weapons.cpp"
#include "Propulsion.cpp"
 */
#ifndef CARGO_H
#define CARGO_H
#include "Payload.h"
#include "Weapons.h"
#include "Propulsion.h"

#include <iostream> //the input/output stream library of C++


class Cargo
{
    private:
    Propulsion propulsion;
    Payload payload1, payload2;
    double speed_of_travel;
    double distance_travelled;
    
	/* int* mass;//Dynamic memory allocation. We don't know how many cards the player
	              //has taken until we run the program. We allocate memory once we know. */
public:
Cargo();
Cargo(const double _fuel_level, const double _light_level, const double _mass_of_passengers1,
             const double _mass_of_cargo1, const double _mass_of_workstations1);
~Cargo();
bool ChangeSpeed(const double _change_of_speed);
void Travel(const double _time_travelled, const double _light_level);
void Report(void);
};
#endif
