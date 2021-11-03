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
        vector<Plane> hashMap[16];
    
    public:
        Plane_DataTable(string file);
        int hash(int key);
        void insert(int key, string plane);
        void update(int key, string plane);
        void remove(int key);

};

