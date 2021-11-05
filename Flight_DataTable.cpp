#include "Flight_DataTable.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

/**
 * Function:    Flight Data Table Constructor
 * Parameters:  a string file representing the file location of the file.
 * Return:      N/A
 * Description: Initializes the hashMap in the class with the data in the file.
 */
Flight_DataTable::Flight_DataTable(string file)
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
 * Parameters:  a string values which represents the key that will be hashed.
 * Return:      an integer value which represents the hashed key.
 * Description: This hash function uses modulo to hash the integer key by the table size.
 */
int Flight_DataTable::hash(string key)
{
    int stringHash = 0; 

    for(auto it : key)
        stringHash += it;

    return stringHash % table_size;
}

/**
 * Function:    Insert
 * Parameters:  A string value, Flight, which contains the contents of the new Flight structure dilemited by commas. 
 * Return:      N/A
 * Description: This function inserts Flight structures into the hashMap using a chaining collision method.
 */
bool Flight_DataTable::insert(string flight)
{
    Flight tempFlight; //temp Flight structure
    stringstream ss(flight); //string stream object with the string of the plane.

    //storing the contents of the parameter into the Flight structure.
    getline(ss, tempFlight.flno, ',');
    getline(ss, tempFlight.meal, ',');
    getline(ss, tempFlight.smoking, ',');

    int index = hash(tempFlight.flno); //hashing the flno of the Flight as the key to get the index.
    auto& chain = hashMap[index]; //list in the index in which the new Flight structure will be added.
    
    if(chain.size() >= table_size) //return false if the size of the list at the index has already reach the table size.
        return false;

    for(auto it : chain)
    {
        if(it.flno == tempFlight.flno)//If the flno of the current index is equal to the Flight being added, return false.
            return false;
    }

    chain.push_back(tempFlight); //adding the Flight to the hash map.

    return true;
}