#ifndef FLIGHTLEG_DATATABLE_H
#define FLIGHTLEG_DATATABLE_H

#include <string>
#include <vector>
using namespace std;

struct FlightLeg
{
    string flno;
    string seq;
    string fromA;
    string toA;
    string deptTime;
    string arrTime;
    string plane;
};

//HashMap that implements using multiplicative string hash and quadratic probing collision method.
class FlightLeg_DataTable
{
    private:
        static const int table_size = 23;
        vector<FlightLeg> hashMap = vector<FlightLeg>(table_size);
        string fileLocation;
    
    public:
        FlightLeg_DataTable(string file);
        int hash(string key1, string key2);
        bool insert(string flightLeg);
};

#endif