#include "Plane_DataTable.h"
#include "PlaneType_DataTable.h"
#include "FlightLeg_DataTable.h"
#include "PlaneSeats_DataTable.h"
#include "FlightLegInstance_DataTable.h"
#include "Airport_DataTable.h"
#include "Pilot_DataTable.h"
#include "FlightInstance_DataTable.h"
#include "Reservation_DataTable.h"
#include "Passenger_DataTable.h"
#include "Flight_DataTable.h"
#include <iostream>
using namespace std;

int main()
{
    Plane_DataTable test("./data/DATA_Plane.csv");
    test.insert("25,AIRBUS,A340,09/04/2021,SEA");
    test.print();
    cout << test.hash(24) << endl;
    //cout << test.remove("24,AIRBUS,A340,09/04/2021,SEA") << endl;
    test.print();
    return 0;
}