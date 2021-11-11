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
    Plane_DataTable test("data/DATA_Plane.csv");
    test.print();
    cout << endl;
    cout << "Inserted: " << test.insert("25,AIRBUS,A340,09/04/2021,SEA") << endl;
    cout << "Inserted: " << test.insert("31,AIRBUS,A340,09/04/2021,SEA") << endl;
    cout << "Removed: " << test.remove("2,AIRBUS,A340,09/04/2021,SEA") << endl;
    cout << "Removed: " << test.remove("25,AIRBUS,A340,09/04/2021,SEA") << endl;
    cout << "Removed: " << test.remove("56,AIRBUS,A340,09/04/2021,SEA") << endl;
    cout << "Updated: " << test.update("3,AIRBUS,A340,09/04/2021,SEA") << endl;
    test.print();
    return 0;
}