#ifndef PAYLOAD_H
#define PAYLOAD_H
#include <iostream> //the input/output stream library of C++


class Payload
{
    private:
    double mass_of_passengers;
    double mass_of_cargo;
    double mass_of_workstations;
public:
Payload();
Payload(const double _mass_of_passengers, const double _mass_of_cargo, const double _mass_of_workstations);
~Payload();
double GetMassPassengers(void);
double GetMassCargo(void);
double GetMassWorkstations(void);
void AddPassengers(double _Mass_of_Added_Pasengers);
void AddCargo(double _Mass_of_Added_Cargo);
void AddWorkstations(double _Mass_of_Added_Workstations);
void Report(void);
};
#endif
