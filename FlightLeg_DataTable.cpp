#include "FlightLeg_DataTable.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

/**
 * Function:    flight leg Data Table Constructor
 * Parameters:  a string file representing the file location of the file.
 * Return:      N/A
 * Description: Initializes the hashMap in the class with the data in the file.
 */
FlightLeg_DataTable::FlightLeg_DataTable(string file)
{
    fileLocation = file; //storing the file path.
    
    for(auto &it : hashMap) //initializing all flno strings in the of flight leg structures to "empty".
    {
        it.flno = "-1";
    }

    ifstream in(file); //creating input file stream from the filepath. 
    string line;

    getline(in, line); //ignoring the first line of the file.
    
    while(getline(in, line)) //while loop to get each row in the file to store the data.
        insert(line); 
}

/**
 * Function:    Hash
 * Parameters:  an integer value key which represents the key that will be hashed.
 * Return:      an integer value which represents the hashed key.
 * Description: This hash function uses modulo to hash the key by the table size.
 */
int FlightLeg_DataTable::hash(string key)
{
    int k = stoi(key); 

    return k % table_size;
}

/**
 * Function:    Insert
 * Parameters:  A string value, flightLeg, which contains the contents of the new flightLeg structure dilemited by commas. 
 * Return:      N/A
 * Description: This function inserts flight leg structures into the hashMap using a double hashing collision method.
 */
bool FlightLeg_DataTable::insert(string flightLeg)
{
    FlightLeg tempFlightLeg; //temp flight leg structure
    stringstream ss(flightLeg); //string stream object with the string of the plane.

    //storing the contents of the parameter into the Plane structure.
    getline(ss, tempFlightLeg.flno, ',');
    getline(ss, tempFlightLeg.seq, ',');
    getline(ss, tempFlightLeg.fromA, ',');
    getline(ss, tempFlightLeg.toA, ',');
    getline(ss, tempFlightLeg.deptTime, ',');
    getline(ss, tempFlightLeg.arrTime, ',');
    getline(ss, tempFlightLeg.plane, ',');

    int bucketsProbed = 0; //variable to keep track how many of the buckets have been probed.
    int i = 0;
    while(bucketsProbed < table_size) //while loop to iterate until all the buckets have been probed.
    {
        int index = (hash(tempFlightLeg.flno) + (i * hash(tempFlightLeg.seq))) % table_size; //hashing the flno and sequence of the FlightLeg as the key to get the index.

        if(hashMap[index].flno == "-1") //If the index is emtpy add the plane to the hashMap.
        {
            hashMap[index] = tempFlightLeg;
            return true;
        }
        
        if((hashMap[index].flno == tempFlightLeg.flno) && (hashMap[index].seq == tempFlightLeg.seq)) //If the flno and seq of the current index is equal to the flno and seq being added, return false.
            return false;

        i++;
        bucketsProbed++; //incrementing the buckets probed variable.
    }

    return false;
}