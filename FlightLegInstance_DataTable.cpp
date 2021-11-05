#include "FlightLegInstance_DataTable.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

/**
 * Function:    flight leg instance Data Table Constructor
 * Parameters:  a string file representing the file location of the file.
 * Return:      N/A
 * Description: Initializes the hashMap in the class with the data in the file.
 */
FlightLegInstance_DataTable::FlightLegInstance_DataTable(string file)
{
    fileLocation = file; //storing the file path.

    ifstream in(file); //creating input file stream from the filepath. 
    string line;

    getline(in, line); //ignoring the first line of the file.
    
    while(getline(in, line)) //while loop to get each row in the file to store the data.
        insert(line); 
}

/**
 * Function:    Hash
 * Parameters:  3 string values which represents the keys that will be hashed.
 * Return:      an integer value which represents the hashed key.
 * Description: This hash function uses modulo to hash the mulitplicative string key by the table size.
 */
int FlightLegInstance_DataTable::hash(string key1, string key2, string key3)
{
    int stringHash = 0; 

    for(auto it : key1)
        stringHash += it;

    for(auto it : key2)
        stringHash += it;

    for(auto it : key3)
        stringHash += it;

    return stringHash % table_size;
}

/**
 * Function:    Insert
 * Parameters:  A string value, FlightLegInstance, which contains the contents of the new flight leg instance structure dilemited by commas. 
 * Return:      N/A
 * Description: This function inserts flight leg instance structures into the hashMap using a chaining collision method.
 */
bool FlightLegInstance_DataTable::insert(string flightLegInstance)
{
    FlightLegInstance tempFlightLegInstance; //temp flight leg instance structure
    stringstream ss(flightLegInstance); //string stream object with the string of the plane.

    //storing the contents of the parameter into the flight leg instance structure.
    getline(ss, tempFlightLegInstance.seq, ',');
    getline(ss, tempFlightLegInstance.flno, ',');
    getline(ss, tempFlightLegInstance.fDate, ',');
    getline(ss, tempFlightLegInstance.actDept, ',');
    getline(ss, tempFlightLegInstance.actArr, ',');
    getline(ss, tempFlightLegInstance.pilot, ',');

    int index = hash(tempFlightLegInstance.seq, tempFlightLegInstance.flno, tempFlightLegInstance.fDate); //hashing the seq, flno, and fDate of the FlightLegInstance as the key to get the index.
    auto& chain = hashMap[index]; //list in the index in which the new flight leg instance structure will be added.
    
    if(chain.size() >= table_size) //return false if the size of the list at the index has already reach the table size.
        return false;

    for(auto it : chain)
    {
        if((it.seq == tempFlightLegInstance.seq) && (it.flno == tempFlightLegInstance.flno) && (it.fDate == tempFlightLegInstance.fDate))//If the seq, flno, and fDate of the current index is equal to the FlightLegInstance being added, return false.
            return false;
    }

    chain.push_back(tempFlightLegInstance); //adding the flight leg instance to the hash map.

    return true;
}