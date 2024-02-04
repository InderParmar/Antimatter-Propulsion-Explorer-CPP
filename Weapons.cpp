#include "Weapons.h"
#include <iostream> //the input/output stream library of C++
#include <iomanip>
using namespace std;
Weapons::Weapons()
{
    number_of_torpedoes = 0.0;
    number_of_laser_cannons = 0.00;
    torpedo_capacity = 100;
    Max_Num_laser_canons = 8;
    energy_required_to_fire = 1000000000000.0;
}
Weapons::Weapons(const int _number_of_torpedoes, const int _number_of_laser_cannons)
{
    number_of_torpedoes = _number_of_torpedoes;
    number_of_laser_cannons = _number_of_laser_cannons;
    torpedo_capacity = 100;
    Max_Num_laser_canons = 8;
    energy_required_to_fire = 1000000000000.0;
}
Weapons::~Weapons()
{
    number_of_torpedoes = 0;
    number_of_laser_cannons = 0;
    torpedo_capacity = 0;
    Max_Num_laser_canons = 0;
}
bool Weapons::FireTorpedoes(int _number_of_torpedoes)
{
    bool retval = true;
    if (this->number_of_torpedoes < _number_of_torpedoes)
    {
        retval = false;
    }
    else
    {
        number_of_torpedoes -=_number_of_torpedoes;
    }
    return retval;
}
double Weapons::FireLaserCanons(double _time_duration)
{
    double energy_consumed = energy_required_to_fire * _time_duration;
    return energy_consumed;
}
void Weapons::AddTorpedoes(int _number_of_torpedoes)
{
    this->number_of_torpedoes += _number_of_torpedoes;
    if (number_of_torpedoes > torpedo_capacity)
    {
        this->number_of_torpedoes  = 100;
    }
}
void Weapons::AddLaserCanons(int _number_of_laser_cannons)
{
    this->number_of_laser_cannons += _number_of_laser_cannons;
    if (number_of_laser_cannons > Max_Num_laser_canons)
    {
        this->number_of_torpedoes  = 8;
    }
}
void Weapons::Report(void)
{
    cout << "Weapon: number of laser cannons:" << number_of_laser_cannons << ", number of torpedoes:" << number_of_torpedoes << "." << endl;
}
