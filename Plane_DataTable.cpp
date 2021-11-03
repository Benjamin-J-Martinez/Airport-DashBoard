#include "Plane_DataTable.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

Plane_DataTable::Plane_DataTable(string file)
{
    fileLocation = file;
    //initializing all ids of plane strucuters to -1;
    for(auto &it : hashMap)
    {
        it.id = -1;
    }

    ifstream in(file);
    int id;
    string line, temp;

    getline(in, line);
    int index = 0;
    while(getline(in, line))
    {
        stringstream ss(line);
        getline(ss, temp, ',');
        hashMap[index].id = stoi(temp);
        getline(ss, hashMap[index].maker, ',');
        getline(ss, hashMap[index].model, ',');
        getline(ss, hashMap[index].lastMaint, ',');
        getline(ss, hashMap[index].lastMaintA, ',');  
        index++;
    } 
}

int Plane_DataTable::hash(int key)
{
    return key % table_size;
}

void Plane_DataTable::insert(string plane)
{
    Plane tempPlane;
    stringstream ss(plane);
    string strID;
    int id;

    getline(ss, strID, ',');
    getline(ss, tempPlane.maker, ',');
    getline(ss, tempPlane.model, ',');
    getline(ss, tempPlane.lastMaint, ',');
    getline(ss, tempPlane.lastMaintA, ',');
    int id = stoi(strID);
    tempPlane.id = id;

    int index = hash(id);
    int bucketsProbed = 0;

    while(bucketsProbed < table_size)
    {
        if(hashMap[index].id == -1)
        {
            hashMap[index] = tempPlane;
            return;
        }

        index = (index + 1) % table_size;
        bucketsProbed++;
    }
}

void Plane_DataTable::print()
{
    cout << "File Name: " << fileLocation << endl;
    cout << "Insert Content: ['ID', 'Maker', 'Model', 'LastMaint', 'LastMaintA']" << endl;

    for(const auto it : hashMap)
    {

    }
}



