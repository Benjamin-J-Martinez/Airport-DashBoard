#ifndef FLIGHTINSTANCE_DATATABLE_H
#define FLIGHTINSTANCE_DATATABLE_H

#include <string>
#include <vector>
#include <list>
using namespace std;

struct FlightInstance
{
    string flno;
    string fDate;
};

//HashMap that implements using multiplicative string hash and chaining collision method.
class FlightInstance_DataTable
{
    private:
        static const int table_size = 23;
        vector<list<FlightInstance>> hashMap = vector<list<FlightInstance>>(table_size);
        string fileLocation;
    
    public:
        FlightInstance_DataTable(string file);
        int hash(string key1, string key2);
        bool insert(string flightInstance);
};

#endif