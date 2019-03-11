#ifndef WEAPON_H
#define WEAPON_H


class Weapon
{
    public:
        //Weapon();
        virtual void SetValues() = 0;
        double attack;
        double range;
        double speed;
        //~Weapon();
};

class DualPistols: public Weapon
{
    public:
    DualPistols() : Weapon() {}

    void SetValues()
    {
        attack=0.1;
        range=0.3;
        speed=0.8;
    }

    ~DualPistols() {}
};

class AssaultRifle: public Weapon
{
    public:
    AssaultRifle() : Weapon() {}

    void SetValues()
    {
        attack=0.25;
        range=0.3;
        speed=0.8;
    }

    ~AssaultRifle() {}
};

class MachineGun: public Weapon
{
    public:
    MachineGun() : Weapon() {}

    void SetValues()
    {
        attack=0.3;
        range=0.3;
        speed=0.8;
    }

    ~MachineGun() {}
};
#endif // WEAPON_H
