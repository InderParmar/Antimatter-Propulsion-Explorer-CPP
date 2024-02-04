#include "Warbird.h"

#include <iostream> //the input/output stream library of C++
#include <iomanip>
using namespace std;
Warbird::Warbird()
{
    speed_of_travel = 0.00;
    distance_travelled = 0.00;
}
Warbird::Warbird(const double _fuel_level, const double _light_level, const double _mass_of_passengers,
                 const double _mass_of_cargo, const double _mass_of_workstations, const int _number_of_torpedoes,
                 const int _number_of_laser_cannons)
    : propulsion1(_fuel_level, _light_level), propulsion2(_fuel_level, _light_level),
      payload(_mass_of_passengers, _mass_of_cargo, _mass_of_workstations),
      weapon1(_number_of_torpedoes, _number_of_laser_cannons),
      weapon2(_number_of_torpedoes, _number_of_laser_cannons)
{
    speed_of_travel = 0.00;
    distance_travelled = 0.00;
}
Warbird::~Warbird()
{
    speed_of_travel = 0.00;
    distance_travelled = 0.00;
}
bool Warbird::ChangeSpeed(const double _change_of_speed)
{
    bool retval = true;
    double energy = 0.00;
    double mass = payload.GetMassPassengers() + payload.GetMassCargo() + payload.GetMassWorkstations();
    double new_Speed = speed_of_travel + _change_of_speed;
    energy = 0.5 * mass * (_change_of_speed * _change_of_speed);
    energy = energy / 2;
    retval = propulsion1.Consume_Fuel(energy);
    bool retval1 = propulsion2.Consume_Fuel(energy);
    if (retval == true || retval1 == true)
    {
        speed_of_travel = new_Speed;

        return true;
    }
    else
    {
        return false;
    }
}

void Warbird::Travel(const double _time_travelled, const double _light_level)
{
    distance_travelled = distance_travelled + (speed_of_travel * _time_travelled) ;
    propulsion1.Set_Light_Level(_light_level);
    propulsion1.GenerateFuel(_time_travelled);
    propulsion2.Set_Light_Level(_light_level);
    propulsion2.GenerateFuel(_time_travelled);
}
bool Warbird::FireTorpedoes(int _number_of_torpedoes)
{
    _number_of_torpedoes = _number_of_torpedoes/2;
    bool retval = weapon1.FireTorpedoes(_number_of_torpedoes);
    bool retval1 = weapon2.FireTorpedoes(_number_of_torpedoes);
    if (retval == true || retval1 == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Warbird::FireLaser(double _time_duration)
{
    double energy_consumed1 = weapon1.FireLaserCanons(_time_duration);
    double energy_consumed2 = weapon2.FireLaserCanons(_time_duration);
    bool retval1 = propulsion1.Consume_Fuel(energy_consumed1);
    bool retval2 = propulsion2.Consume_Fuel(energy_consumed2);

    if (retval1 == true || retval2 == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Warbird::Report(void)
{

    cout << std::fixed << std::setprecision(2) << "The war bird is travelling at " << speed_of_travel << "m/s and has travelled "
         << distance_travelled << "m." << endl;
    propulsion1.Report();
    propulsion2.Report();
    payload.Report();
    weapon1.Report();
    weapon2.Report();
    cout << endl;
}
