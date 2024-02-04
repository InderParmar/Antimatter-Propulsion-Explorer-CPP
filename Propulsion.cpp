#include "Propulsion.h"
#include <iostream> //the input/output stream library of C++
#include <iomanip>
using namespace std;

Propulsion::Propulsion()
{
    fuel_level = 0.00;
    light_level = 0.00;
    speed_of_light = 299792458;
    fuel_tank_capacity = 1000.0;
    light_to_fuel_conversion = 0.00;
}
Propulsion::Propulsion(const double _fuel_level, const double _light_level)
{
    fuel_level = _fuel_level;
    light_level = _light_level;
    speed_of_light = 299792458;
    fuel_tank_capacity = 1000.0;
    light_to_fuel_conversion = 0.00;
}
Propulsion::~Propulsion()
{
    fuel_level = 0.00;
    light_level = 0.00;
    speed_of_light = 0.00;
    fuel_tank_capacity = 0.00;
    light_to_fuel_conversion = 0.00;
}
bool Propulsion::Consume_Fuel(const double _energy_required)
{
    bool retval = true;
    double mass_of_fuel_required = 0.00;
    mass_of_fuel_required = _energy_required / (speed_of_light * speed_of_light);
    
    if (fuel_level < mass_of_fuel_required)
    {
        retval = false;
    }
    else
    {
        fuel_level = fuel_level - mass_of_fuel_required;
    }
    return retval;
}
void Propulsion::AddFuel(const double _add_fuel)
{
    // Add fuel (in kg of matter/anti-matter),
    fuel_level += _add_fuel;
    if (fuel_level > fuel_tank_capacity)
    {
        fuel_level = 1000.0;
    }
}
double Propulsion::GenerateFuel(double _time_elapsed)
{
    light_to_fuel_conversion = light_level * _time_elapsed;
    fuel_level = fuel_level  + light_to_fuel_conversion;
      if (fuel_level > fuel_tank_capacity)
    {
        fuel_level = 1000.0;
    }
    return light_to_fuel_conversion;
}
void Propulsion::Set_Light_Level(double _light_level)
{
    light_level = _light_level;
}
void Propulsion::Report(void)
{
    cout << std::fixed << std::setprecision(2) << "Propulsion: fuel level: " << fuel_level << "kg of matter/anti-matter, light level:" << light_level << "." << endl;
}