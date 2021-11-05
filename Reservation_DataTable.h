#ifndef RESERVATION_DATATABLE_H
#define RESERVATION_DATATABLE_H

#include <string>
#include <vector>
#include <list>
using namespace std;

struct Reservation
{
    string passID;
    string flno;
    string fdate;
    string fromA;
    string toA;
    string seatClass;
    string dateBooked;
    string dateCancelled;
};

//HashMap that implements using multiplicative string hash and chaining collision method.
class Reservation_DataTable
{
    private:
        static const int table_size = 23;
        vector<list<Reservation>> hashMap = vector<list<Reservation>>(table_size);
        string fileLocation;
    
    public:
        Reservation_DataTable(string file);
        int hash(string key1, string key2, string key3);
        bool insert(string reservation);
};

#endif