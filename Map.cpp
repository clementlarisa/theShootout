#include "Map.h"
#include <cstring>
#include <iostream>
using namespace std;

//constructor
Map::Map()
{
    my_map=new char*[25];
    for(int i=0; i<25; i++)
        my_map[i]=new char[25];

    for(int i=0; i<25; i++)
        for(int j=0; j<25; j++)
            my_map[i][j]='.';
}
//destructor
Map::~Map()
{
    for(int i=0; i<25; i++)
        delete[]my_map[i];
    delete[]my_map;
}
void Map::ShowMap()
{
    cout<<endl<<endl;
    for(int i=0; i<25; i++)
    {
        for(int j=0; j<25; j++)
            cout<<my_map[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl<<endl;
}
