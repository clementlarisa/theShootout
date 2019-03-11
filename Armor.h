#ifndef ARMOR_H
#define ARMOR_H
#include "Weapon.h"

class Armor
{
    public:
        Armor();
        virtual ~Armor();

        double defence;
        double weight;
};

class Armor1 : public Armor
{
    public:
        double defence = 0.5;
        double weight;
        Armor1() : Armor() {
            weight = 0.3;
        }
        ~Armor1() {}
};
class Armor2 : public Armor
{
    public:
        double defence = 0.7;
        double weight;
        Armor2() : Armor() {
            weight = 0.5;
        }
        ~Armor2() {}
};
class Armor3 : public Armor
{
    public:
        double defence = 0.9;
        double weight;
        Armor3() : Armor() {
            weight = 0.7;
        }
        ~Armor3() {}
};
#endif // ARMOR_H
