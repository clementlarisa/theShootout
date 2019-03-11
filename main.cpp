#include <iostream>
#include "Agent.h"
#include "Map.h"
#include "Armor.h"
#include "Weapon.h"
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;


Agent* GetAgentFromPosition(vector<Agent*> &agents, int lin, int col)
{
    for (int i = 0; i < agents.size(); ++i)
    {
        if (agents[i]->lin == lin && agents[i]->col == col)
            return agents[i];
    }
}

void ApplyActions(vector<Action> &actions, vector<Agent*> &agents)
{
    for (int i = 0 ; i < actions.size(); ++i)
    {
        Agent *agent = agents[i];
        if (actions[i] == SHOOT)
        {
            bool hitsTarget = agent->Shoot(); //verific daca poate trage
            if (hitsTarget == true)
            {
                Agent *enemy = GetAgentFromPosition(agents, agent->enemyLin, agent->enemyCol);
                double damage = agent->weapon->attack - enemy->armor->defence;
                if (damage > 0)
                {
                    enemy->lives -= damage / 3 * enemy->lives;
                    cout << enemy->lives << endl;
                }
            }
        }
        else if (actions[i] == MOVE)
        {
            agent->Move();
        }
    }
}

int main()
{
    int rounds = 10;
    Map my_map = Map();
    //folosesc doi vectori pentru agenti si actiuni
    vector<Agent*> agents;
    vector<Action> actions;

    //Agent1 Rogers;
    int linie, coloana;

    srand(time(NULL));
    linie = rand()%25;
    coloana = rand()%25;

    while(my_map.my_map[linie][coloana] == 'x')
        linie = rand()%25, coloana = rand()%25;

    Armor *rogersArmor = new Armor1();
    cout << (double) rogersArmor->weight;
    Weapon *rogersWeapon = new AssaultRifle();
    Agent *Rogers = new Agent1(3, linie, coloana, my_map, rogersArmor, rogersWeapon);
    Rogers->SetValues();
    agents.push_back(Rogers);

    linie = rand()%25;
    coloana = rand()%25;

    while(my_map.my_map[linie][coloana] == 'x')
        linie = rand()%25, coloana = rand()%25;

    Armor *carterArmor = new Armor1();
    Weapon *carterWeapon = new DualPistols();
    Agent *Carter = new Agent1(3, linie, coloana, my_map, carterArmor, carterWeapon);
    Carter->SetValues();
    agents.push_back(Carter);

    while (rounds)
    {
        actions.clear();
        for (int i = 0; i < agents.size(); ++i)
        {
            Agent *agent1 = agents[i];
            Action action = agent1->GetAction(); //generez actiuni posibile pentru agenti
            actions.push_back(action);
        }

        ApplyActions(actions, agents); //aplic actiunile

        my_map.ShowMap();
        cout << "Agent1 lives: " << Rogers->lives << endl;
        cout << "Agent2 lives: " << Carter->lives << endl;

        rounds--;
    }


    return 0;
}
