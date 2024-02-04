#include "Starship.h"

#include <iostream> //the input/output stream library of C++
#include <iomanip>
using namespace std;
Starship::Starship()
{
    speed_of_travel = 0.00;
    distance_travelled = 0.00;
}
Starship::Starship(const double _fuel_level, const double _light_level, const double _mass_of_passengers,
                 const double _mass_of_cargo, const double _mass_of_workstations, const int _number_of_torpedoes,
                 const int _number_of_laser_cannons)
    : propulsion(_fuel_level, _light_level),
      payload(_mass_of_passengers, _mass_of_cargo, _mass_of_workstations), weapon(_number_of_torpedoes,
                                                                                   _number_of_laser_cannons)
{
    speed_of_travel = 0.00;
    distance_travelled = 0.00;
}
Starship::~Starship()
{
    speed_of_travel = 0.00;
    distance_travelled = 0.00;
}
bool Starship::ChangeSpeed(const double _change_of_speed)
{
    bool retval = true;
    double mass = payload.GetMassPassengers() + payload.GetMassCargo() + payload.GetMassWorkstations();
    double new_Speed = speed_of_travel + _change_of_speed;
    double energy = 0.5 * mass * (_change_of_speed * _change_of_speed);
    retval = propulsion.Consume_Fuel(energy);
    if (retval)
    {
        speed_of_travel = new_Speed;
        return retval;
    }
    else
    {
        return retval;
    }
}
void Starship::Travel(const double _time_travelled, const double _light_level)
{
    distance_travelled = distance_travelled +  (speed_of_travel * _time_travelled);
    propulsion.Set_Light_Level(_light_level);
    propulsion.GenerateFuel(_time_travelled);
}
bool Starship::FireTorpedoes(int _number_of_torpedoes)
{
    bool retval = weapon.FireTorpedoes(_number_of_torpedoes);
    return retval;
}
bool Starship::FireLaser(double _time_duration)
{
    double energy_consumed = weapon.FireLaserCanons(_time_duration);
    bool retval = propulsion.Consume_Fuel(energy_consumed);
    return retval;
}
void Starship::Report(void)
{
    cout << std::fixed << std::setprecision(2) << "The star ship is travelling at " 
    << speed_of_travel << "m/s and has travelled " << distance_travelled << "m." << endl;
    propulsion.Report();
    payload.Report();
    weapon.Report();
    cout<<endl;

    }
