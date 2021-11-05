#ifndef FLIGHTLEGINSTANCE_DATATABLE_H
#define FLIGHTLEGINSTANCE_DATATABLE_H

#include <string>
#include <vector>
#include <list>
using namespace std;

struct FlightLegInstance
{
    string seq;
    string flno;
    string fDate;
    string actDept;
    string actArr;
    string pilot;
};

//HashMap that implements using multiplicative string hash and chaining collision method.
class FlightLegInstance_DataTable
{
    private:
        static const int table_size = 23;
        vector<list<FlightLegInstance>> hashMap = vector<list<FlightLegInstance>>(table_size);
        string fileLocation;
    
    public:
        FlightLegInstance_DataTable(string file);
        int hash(string key1, string key2, string key3);
        bool insert(string flightLegInstance);
};

#endif