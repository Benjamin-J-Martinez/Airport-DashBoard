#ifndef AIRPORT_DATATABLE_H
#define AIRPORT_DATATABLE_H

#include <string>
#include <vector>
#include <list>
using namespace std;

struct Airport
{
    string code;
    string city;
    string state;
};

//HashMap that implements using multiplicative string hash and chaining collision method.
class Airport_DataTable
{
    private:
        static const int table_size = 23;
        vector<list<Airport>> hashMap = vector<list<Airport>>(table_size);
        string fileLocation;
    
    public:
        Airport_DataTable(string file);
        int hash(string key);
        bool insert(string airport);
};

#endif