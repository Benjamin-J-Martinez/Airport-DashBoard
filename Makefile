
output: main.o Plane_DataTable.o PlaneType_DataTable.o FlightLeg_DataTable.o PlaneSeats_DataTable.o FlightLegInstance_DataTable.o Airport_DataTable.o Pilot_DataTable.o FlightInstance_DataTable.o Reservation_DataTable.o Passenger_DataTable.o Flight_DataTable.o
	g++ main.o Plane_DataTable.o PlaneType_DataTable.o FlightLeg_DataTable.o PlaneSeats_DataTable.o FlightLegInstance_DataTable.o Airport_DataTable.o Pilot_DataTable.o FlightInstance_DataTable.o Reservation_DataTable.o Passenger_DataTable.o Flight_DataTable.o -o output

main.o: main.cpp
	g++ -c main.cpp

Plane_DataTable.o: Plane_DataTable.cpp Plane_DataTable.h
	g++ -c Plane_DataTable.cpp

PlaneType_DataTable.o: PlaneType_DataTable.cpp PlaneType_DataTable.h
	g++ -c PlaneType_DataTable.cpp

FlightLeg_DataTable.o: FlightLeg_DataTable.cpp FlightLeg_DataTable.h
	g++ -c FlightLeg_DataTable.cpp

PlaneSeats_DataTable.o: PlaneSeats_DataTable.cpp PlaneSeats_DataTable.h
	g++ -c PlaneSeats_DataTable.cpp

FlightLegInstance_DataTable.o: FlightLegInstance_DataTable.cpp FlightLegInstance_DataTable.h
	g++ -c FlightLegInstance_DataTable.cpp

Airport_DataTable.o: Airport_DataTable.cpp Airport_DataTable.h
	g++ -c Airport_DataTable.cpp

Pilot_DataTable.o: Pilot_DataTable.cpp Pilot_DataTable.h
	g++ -c Pilot_DataTable.cpp

FlightInstance_DataTable.o: FlightInstance_DataTable.cpp FlightInstance_DataTable.h
	g++ -c FlightInstance_DataTable.cpp

Reservation_DataTable.o: Reservation_DataTable.cpp Reservation_DataTable.h
	g++ -c Reservation_DataTable.cpp

Passenger_DataTable.o: Passenger_DataTable.cpp Passenger_DataTable.h
	g++ -c Passenger_DataTable.cpp

Flight_DataTable.o: Flight_DataTable.cpp Flight_DataTable.h
	g++ -c Flight_DataTable.cpp

clean:
	rm *.o output
