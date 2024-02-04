#ifndef WEAPONS_H
#define WEAPONS_H
#include <iostream> //the input/output stream library of C++


class Weapons
{
    private:
    int number_of_torpedoes;
    int number_of_laser_cannons;
    int torpedo_capacity;
    int Max_Num_laser_canons;
    double energy_required_to_fire;
public:
Weapons();
Weapons(const int _number_of_torpedoes, const int _number_of_laser_cannons);
~Weapons();
bool FireTorpedoes(int _number_of_torpedoes);
double FireLaserCanons(double _time_duration);
void AddTorpedoes(int _number_of_torpedoes);
void AddLaserCanons(int _number_of_laser_cannons);
void Report(void);
};
#endif
