#include "Plane_DataTable.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

Plane_DataTable::Plane_DataTable(string file)
{
    ifstream in(file);
    int id;
    string maker, model, lastMaint, lastMaintA, line, temp;
    getline(in, line);
    while(getline(in, line))
    {
        stringstream ss(line);
        getline(ss, temp, ',');
        id = stoi(temp);
        getline(ss, maker, ',');
        getline(ss, model, ',');
        getline(ss, lastMaint, ',');
        getline(ss, lastMaintA, ',');  
    } 
}

int Plane_DataTable::hash(int key)
{
    return key % table_size;
}

void Plane_DataTable::insert(int key, string plane)
{
    int index = hash(key);
    int bucketsProbed = 0;

    while(bucketsProbed < table_size)
    {
        //Plane plane = hashMap[index];
        //if(hashMap[index].id != 0)
    }

}



