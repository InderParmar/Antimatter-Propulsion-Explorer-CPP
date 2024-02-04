#include "Payload.h"
#include <iomanip>
#include <iostream>
using namespace std;
Payload::Payload()
{
    mass_of_passengers = 0.00;
    mass_of_cargo = 0.00;
    mass_of_workstations = 0.00;
}
Payload::Payload(const double _mass_of_passengers, const double _mass_of_cargo, const double _mass_of_workstations)
{
    mass_of_passengers = _mass_of_passengers;
    mass_of_cargo = _mass_of_cargo;
    mass_of_workstations = _mass_of_workstations;
}
Payload::~Payload()
{
    mass_of_passengers = 0.00;
    mass_of_cargo = 0.00;
    mass_of_workstations = 0.00;
}
double Payload::GetMassPassengers(void)
{
    return mass_of_passengers;
}
double Payload::GetMassCargo(void)
{
    return mass_of_cargo;
}
double Payload::GetMassWorkstations(void)
{
    return mass_of_workstations;
}
void Payload::AddPassengers(double _Mass_of_Added_Pasengers)
{
    mass_of_passengers += _Mass_of_Added_Pasengers;
}
void Payload::AddCargo(double _Mass_of_Added_Cargo)
{
    mass_of_cargo += _Mass_of_Added_Cargo;
}
void Payload::AddWorkstations(double _Mass_of_Added_Workstations)
{
    mass_of_workstations += _Mass_of_Added_Workstations;
}
void Payload::Report(void)
{
    cout << std::fixed << std::setprecision(2) << "Payload: mass of passengers:" << mass_of_passengers << "kg, mass of cargo:" << mass_of_cargo << "kg, mass of workstations:" << mass_of_workstations << "kg." << endl;
}
