#include "FlightInstance_DataTable.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

/**
 * Function:    FlightInstance Data Table Constructor
 * Parameters:  a string file representing the file location of the file.
 * Return:      N/A
 * Description: Initializes the hashMap in the class with the data in the file.
 */
FlightInstance_DataTable::FlightInstance_DataTable(string file)
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
 * Parameters:  2 string values which represents the keys that will be hashed.
 * Return:      an integer value which represents the hashed key.
 * Description: This hash function uses modulo to hash the multiplicative string key by the table size.
 */
int FlightInstance_DataTable::hash(string key1, string key2)
{
    int stringHash = 0; 

    for(auto it : key1)
        stringHash += it;

    for(auto it : key2)
        stringHash += it;

    return stringHash % table_size;
}

/**
 * Function:    Insert
 * Parameters:  A string value, FlightInstance, which contains the contents of the new FlightInstance structure dilemited by commas. 
 * Return:      N/A
 * Description: This function inserts FlightInstance structures into the hashMap using a chaining collision method.
 */
bool FlightInstance_DataTable::insert(string flightInstance)
{
    FlightInstance tempFlightInstance; //temp FlightInstance structure
    stringstream ss(flightInstance); //string stream object with the string of the plane.

    //storing the contents of the parameter into the FlightInstance structure.
    getline(ss, tempFlightInstance.flno, ',');
    getline(ss, tempFlightInstance.fDate, ',');

    int index = hash(tempFlightInstance.flno, tempFlightInstance.fDate); //hashing the flno and fDate of the FlightInstance as the key to get the index.
    auto& chain = hashMap[index]; //list in the index in which the new FlightInstance structure will be added.
    
    if(chain.size() >= table_size) //return false if the size of the list at the index has already reach the table size.
        return false;

    for(auto it : chain)
    {
        if((it.flno == tempFlightInstance.flno) && (it.fDate == tempFlightInstance.fDate))//If the flno and fDate of the current index is equal to the FlightInstance being added, return false.
            return false;
    }

    chain.push_back(tempFlightInstance); //adding the FlightInstance to the hash map.

    return true;
}