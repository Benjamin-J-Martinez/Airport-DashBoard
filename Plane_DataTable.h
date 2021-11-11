#ifndef PLANE_DATATABLE_H
#define PLANE_DATATABLE_H

#include <string>
#include <vector>
using namespace std;

struct Plane
{
    int id;
    string maker;
    string model;
    string lastMaint;
    string lastMaintA;
};

//HashMap that implements using modulo hash and linear probing collision method.
class Plane_DataTable
{
    private:
        static const int table_size = 23;
        vector<Plane> hashMap = vector<Plane>(table_size);
        string fileLocation;
    
    public:
        Plane_DataTable(string file);
        int hash(int key);
        bool insert(string plane);
        bool update(string plane);
        bool remove(string plane);
        void print();
        void write();
        void test();

};

#endif
