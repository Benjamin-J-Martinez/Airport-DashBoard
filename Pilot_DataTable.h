#ifndef PILOT_DATATABLE_H
#define PILOT_DATATABLE_H

#include <string>
#include <vector>
#include <list>
using namespace std;

struct Pilot
{
    int id;
    string name;
    string dateHired;
};

//HashMap that implements using multiplicative string hash and chaining collision method.
class Pilot_DataTable
{
    private:
        static const int table_size = 23;
        vector<list<Pilot>> hashMap = vector<list<Pilot>>(table_size);
        string fileLocation;
    
    public:
        Pilot_DataTable(string file);
        int hash(int key);
        bool insert(string pilot);
};

#endif