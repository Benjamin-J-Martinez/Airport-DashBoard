#ifndef PLANESEATS_DATATABLE_H
#define PLANESEATS_DATATABLE_H

#include <string>
#include <vector>
#include <list>
using namespace std;

struct PlaneSeats
{
    string maker;
    string model;
    string seatType;
    int noOfSeats;
};

//HashMap that implements using multiplicative string hash and chaining collision method.
class PlaneSeats_DataTable
{
    private:
        static const int table_size = 23;
        vector<list<PlaneSeats>> hashMap = vector<list<PlaneSeats>>(table_size);
        string fileLocation;
    
    public:
        PlaneSeats_DataTable(string file);
        int hash(string key1, string key2, string key3);
        bool insert(string planeSeats);
};

#endif