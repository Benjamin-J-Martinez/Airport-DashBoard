#ifndef FLIGHT_DATATABLE_H
#define FLIGHT_DATATABLE_H

#include <string>
#include <vector>
#include <list>
using namespace std;

struct Flight
{
    string flno;
    string meal;
    string smoking;
};

//HashMap that implements using multiplicative string hash and chaining collision method.
class Flight_DataTable
{
    private:
        static const int table_size = 23;
        vector<list<Flight>> hashMap = vector<list<Flight>>(table_size);
        string fileLocation;
    
    public:
        Flight_DataTable(string file);
        int hash(string key);
        bool insert(string flight);
};

#endif