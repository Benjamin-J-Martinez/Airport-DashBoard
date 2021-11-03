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
        int size;
        int table_size = 16;
        vector<Plane> hashMap = vector<Plane>(16);
        string fileLocation;
    
    public:
        Plane_DataTable(string file);
        int hash(int key);
        void insert(string plane);
        void update(int key, string plane);
        void remove(int key);
        void print();

};

#endif
