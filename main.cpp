#include "Plane_DataTable.h"
#include "PlaneType_DataTable.h"
#include "FlightLeg_DataTable.h"
#include <iostream>
using namespace std;

int main()
{
    FlightLeg_DataTable test("./data/DATA_FlightLeg.csv");
    //test.insert("10,AIRBUS,A340,09/04/2021,SEA");
    return 0;
}