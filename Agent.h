#ifndef AGENT_H
#define AGENT_H
#include <math.h>
#include "Map.h"
#include "weapon.h"
#include "Armor.h"
#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

enum Action {MOVE, STOP, SHOOT};

class Agent
{
protected:
    int weight;
    int visibility;
    int remainingSteps;
    int bulletTrack;
    int direction;
    Map my_map;

public:
    Armor *armor;
    Weapon *weapon;
    double lives;
    int lin;
    int pos;
    int col;
    int enemyLin;
    int enemyCol;
    Agent() {}
    Agent(double l, int ln, int cl, Map &mymap, Armor *ar, Weapon *wp) :
        lives(l), lin(ln), col(cl), my_map(mymap), armor(ar), weapon (wp)
    {
        my_map.my_map[ln][cl]='x';
//        cout << armor->weight;
//        SetValues();
    }
    virtual void SetValues()
    {
        remainingSteps = visibility / 2;
        weapon->speed *= armor->weight;
    }
    void Move();
    virtual bool Shoot()
    {
        int linC = lin;
        int colC = enemyCol;
        int AC = abs(col - colC);
        int BC = abs(lin - linC);
        double duration = sqrt(pow(AC, 2) + pow(BC, 2));
        bulletTrack = ceil(duration * weapon->speed);
        if(bulletTrack < duration/2) return false;
        return true;
    }

    virtual Action GetAction()
    {
        int i, j;
        for (
            lin - visibility < 0 ? i = 0 : i = lin - visibility;
            lin + visibility > 24 ? i <= 24 : i <= lin + visibility;
            ++i
        )
        {
            if (i == lin) continue;
            for (
                col - visibility < 0 ? j = 0 : j = col - visibility;
                col + visibility > 24 ? j <= 24 : j <= col + visibility;
                ++j
            )
            {
                if (j == col) continue;
                if (my_map.my_map[i][j] == 'x')
                {
                    enemyLin = i;
                    enemyCol = j;
                    return SHOOT;
                }
            }
        }
        return MOVE;
    }
    virtual ~Agent() {}
};

class Agent1: public Agent
{
public:
    Agent1(): Agent() {}
    Agent1(double l, int ln, int cl, Map &my_map, Armor *ar, Weapon *wp) :
        Agent(l, ln, cl, my_map, ar, wp)
    {
//        SetValues();
    }
    ~Agent1() {}
    void SetValues()
    {
        weight = 85;
        visibility = 6;
        Agent::SetValues();
    }

    Action GetAction()
    {
        Agent::GetAction();
    }
};
#endif // AGENT_H
