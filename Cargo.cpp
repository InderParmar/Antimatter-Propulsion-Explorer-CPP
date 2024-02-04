
#include "Cargo.h"
#include <iostream> //the input/output stream library of C++
#include <iomanip>
using namespace std;
Cargo::Cargo()
{
    speed_of_travel = 0.00;
    distance_travelled = 0.00;
}
Cargo::Cargo(const double _fuel_level, const double _light_level, const double _mass_of_passengers1,
             const double _mass_of_cargo1, const double _mass_of_workstations1)
    : propulsion(_fuel_level, _light_level), // Call Propulsion constructor
      payload1(_mass_of_passengers1, _mass_of_cargo1, _mass_of_workstations1),
       payload2(_mass_of_passengers1, _mass_of_cargo1, _mass_of_workstations1)
{
    speed_of_travel = 0.00;
    distance_travelled = 0.00;
}
Cargo::~Cargo()
{
    speed_of_travel = 0.00;
    distance_travelled = 0.00;
}
bool Cargo::ChangeSpeed(const double _change_of_speed)
{
    // Change speed (passing through the change of speed in m/s, returning true whether the
    // change is possible and false otherwise). The energy required is calculated according to the
    //  equation for kinetic energy: E=0.5mv2. This energy is passed to the propulsion system to
    // see how much fuel is consumed.
    bool retval = true;
    double mass = payload1.GetMassPassengers() + payload1.GetMassCargo() + payload1.GetMassWorkstations() + 
    payload2.GetMassPassengers() + payload2.GetMassCargo() + payload2.GetMassWorkstations();
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
        speed_of_travel = new_Speed;

        return retval;
    }
}
void Cargo::Travel(const double _time_travelled, const double _light_level)
{
    distance_travelled =  distance_travelled +  (speed_of_travel * _time_travelled);
    propulsion.Set_Light_Level(_light_level);
    propulsion.GenerateFuel(_time_travelled);
}
void Cargo::Report(void)
{
    cout << std::fixed << std::setprecision(2) << "The cargo ship is travelling at " << speed_of_travel << "m/s and has travelled " << distance_travelled/1000  << "km." << endl;
    propulsion.Report();
    payload1.Report();
    payload2.Report();
    cout<<endl;
}