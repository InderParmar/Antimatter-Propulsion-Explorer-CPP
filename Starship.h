#ifndef STARSHIP_H
#define STARSHIP_H
#include "Payload.h"
#include "Weapons.h"
#include "Propulsion.h"

#include <iostream> //the input/output stream library of C++


class Starship
{
    private:
    Propulsion propulsion;
    Payload payload;
    Weapons weapon;
    double speed_of_travel;
    double distance_travelled;
    
	/* int* mass;//Dynamic memory allocation. We don't know how many cards the player
	              //has taken until we run the program. We allocate memory once we know. */
public:
Starship();
Starship(const double _fuel_level, const double _light_level, const double _mass_of_passengers, 
const double _mass_of_cargo, const double _mass_of_workstations,const int _number_of_torpedoes,
 const int _number_of_laser_cannons);
~Starship();
bool ChangeSpeed(const double _change_of_speed);
void Travel(const double _time_travelled, const double _light_level);
bool FireTorpedoes(int _number_of_torpedoes);
bool FireLaser(double _time_duration);
void Report(void);
};
#endif
