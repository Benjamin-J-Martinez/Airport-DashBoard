#ifndef PLANETYPE_DATATABLE_H
#define PLANETYPE_DATATABLE_H

#include <string>
#include <vector>
using namespace std;

struct PlaneType
{
    string maker;
    string model;
    int flyingSpeed;
    int groundSpeed;
};

//HashMap that implements using multiplicative string hash and quadratic probing collision method.
class PlaneType_DataTable
{
    private:
        static const int table_size = 23;
        vector<PlaneType> hashMap = vector<PlaneType>(table_size);
        string fileLocation;
    
    public:
        PlaneType_DataTable(string file);
        int hash(string key1, string key2);
        bool insert(string planeType);
};

#endif
