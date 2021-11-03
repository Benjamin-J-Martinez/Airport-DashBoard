#include "Plane_DataTable.h"
#include <iostream>
using namespace std;

int main()
{
    Plane_DataTable test("./data/DATA_Plane.csv");
    test.insert("10,AIRBUS,A340,09/04/2021,SEA");
    
    return 0;
}