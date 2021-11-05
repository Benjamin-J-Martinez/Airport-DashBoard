#include "Airport_DataTable.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

/**
 * Function:    Airport Data Table Constructor
 * Parameters:  a string file representing the file location of the file.
 * Return:      N/A
 * Description: Initializes the hashMap in the class with the data in the file.
 */
Airport_DataTable::Airport_DataTable(string file)
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
 * Parameters:  a string value which represents the key that will be hashed.
 * Return:      an integer value which represents the hashed key.
 * Description: This hash function uses modulo to hash the mulitplicative string key by the table size.
 */
int Airport_DataTable::hash(string key)
{
    int stringHash = 0; 

    for(auto it : key)
        stringHash += it;

    return stringHash % table_size;
}

/**
 * Function:    Insert
 * Parameters:  A string value, Airport, which contains the contents of the new Airport structure dilemited by commas. 
 * Return:      N/A
 * Description: This function inserts Airport structures into the hashMap using a chaining collision method.
 */
bool Airport_DataTable::insert(string airport)
{
    Airport tempAirport; //temp Airport structure
    stringstream ss(airport); //string stream object with the string of the plane.

    //storing the contents of the parameter into the Airport structure.
    getline(ss, tempAirport.code, ',');
    getline(ss, tempAirport.city, ',');
    getline(ss, tempAirport.state, ',');

    int index = hash(tempAirport.code); //hashing the code of the Airport as the key to get the index.
    auto& chain = hashMap[index]; //list in the index in which the new Airport structure will be added.
    
    if(chain.size() >= table_size) //return false if the size of the list at the index has already reach the table size.
        return false;

    for(auto it : chain)
    {
        if(it.code == tempAirport.code)//If the code of the current index is equal to the Airport being added, return false.
            return false;
    }

    chain.push_back(tempAirport); //adding the Airport to the hash map.

    return true;
}