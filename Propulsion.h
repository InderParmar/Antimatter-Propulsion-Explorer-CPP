#ifndef PROPULSION_H
#define PROPULSION_H
#include <iostream> //the input/output stream library of C++

class Propulsion
{
    private:
    double fuel_level;
    double fuel_tank_capacity;
    double speed_of_light;
    double light_to_fuel_conversion;
    double light_level;
public:
Propulsion();
Propulsion(const double _fuel_level, const double _light_level);
~Propulsion();
bool Consume_Fuel(const double _energy_required);
void AddFuel(const double _add_fuel);
double GenerateFuel(double _time_elapsed);
void Set_Light_Level(double _light_level);
void Report(void);
};
#endif
