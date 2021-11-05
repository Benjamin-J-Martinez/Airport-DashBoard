#ifndef PASSENGER_DATATABLE_H
#define PASSENGER_DATATABLE_H

#include <string>
#include <vector>
#include <list>
using namespace std;

struct Passenger
{
    int id;
    string name;
    string phone;
};

//HashMap that implements using multiplicative string hash and chaining collision method.
class Passenger_DataTable
{
    private:
        static const int table_size = 23;
        vector<list<Passenger>> hashMap = vector<list<Passenger>>(table_size);
        string fileLocation;
    
    public:
        Passenger_DataTable(string file);
        int hash(int key);
        bool insert(string passenger);
};

#endif