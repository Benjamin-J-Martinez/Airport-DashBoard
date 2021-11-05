#include "Passenger_DataTable.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

/**
 * Function:    Passenger Data Table Constructor
 * Parameters:  a string file representing the file location of the file.
 * Return:      N/A
 * Description: Initializes the hashMap in the class with the data in the file.
 */
Passenger_DataTable::Passenger_DataTable(string file)
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
 * Parameters:  an integer values which represents the key that will be hashed.
 * Return:      an integer value which represents the hashed key.
 * Description: This hash function uses modulo to hash the integer key by the table size.
 */
int Passenger_DataTable::hash(int key)
{
    return key % table_size;
}

/**
 * Function:    Insert
 * Parameters:  A string value, Passenger, which contains the contents of the new Passenger structure dilemited by commas. 
 * Return:      N/A
 * Description: This function inserts Passenger structures into the hashMap using a chaining collision method.
 */
bool Passenger_DataTable::insert(string passenger)
{
    Passenger tempPassenger; //temp Passenger structure
    stringstream ss(passenger); //string stream object with the string of the plane.

    //storing the contents of the parameter into the Passenger structure.
    string strID;
    getline(ss, strID, ',');
    getline(ss, tempPassenger.name, ',');
    getline(ss, tempPassenger.phone, ',');
    tempPassenger.id = stoi(strID);

    int index = hash(tempPassenger.id); //hashing the id of the Passenger as the key to get the index.
    auto& chain = hashMap[index]; //list in the index in which the new Passenger structure will be added.
    
    if(chain.size() >= table_size) //return false if the size of the list at the index has already reach the table size.
        return false;

    for(auto it : chain)
    {
        if(it.id == tempPassenger.id)//If the id of the current index is equal to the Passenger being added, return false.
            return false;
    }

    chain.push_back(tempPassenger); //adding the Passenger to the hash map.

    return true;
}