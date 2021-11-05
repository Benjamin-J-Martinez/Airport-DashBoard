#include "Pilot_DataTable.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

/**
 * Function:    Pilot Data Table Constructor
 * Parameters:  a string file representing the file location of the file.
 * Return:      N/A
 * Description: Initializes the hashMap in the class with the data in the file.
 */
Pilot_DataTable::Pilot_DataTable(string file)
{
    fileLocation = file; //storing the file path.

    ifstream in(file); //creating input file stream from the filepath. 
    string line;

    getline(in, line); //ignoring the first line of the file.
    
    while(getline(in, line)) //while loop to get each row in the file to store the data.
        insert(line); 

    int index = 0;
    for(auto i : hashMap)
    {
        cout << "Index " << index << ":" << endl;
        for( auto j : i)
            cout << j.id << " " << j.name << " " << j.dateHired << endl;
        index++;
    }
}

/**
 * Function:    Hash
 * Parameters:  a integer value which represents the key that will be hashed.
 * Return:      an integer value which represents the hashed key.
 * Description: This hash function uses modulo to hash the integer key by the table size.
 */
int Pilot_DataTable::hash(int key)
{
    return key % table_size;
}

/**
 * Function:    Insert
 * Parameters:  A string value, Pilot, which contains the contents of the new Pilot structure dilemited by commas. 
 * Return:      N/A
 * Description: This function inserts Pilot structures into the hashMap using a chaining collision method.
 */
bool Pilot_DataTable::insert(string pilot)
{
    Pilot tempPilot; //temp Pilot structure
    stringstream ss(pilot); //string stream object with the string of the plane.

    //storing the contents of the parameter into the Pilot structure.
    string strID;
    getline(ss, strID, ',');
    getline(ss, tempPilot.name, ',');
    getline(ss, tempPilot.dateHired, ',');
    tempPilot.id = stoi(strID);

    int index = hash(tempPilot.id); //hashing the id of the Pilot as the key to get the index.
    auto& chain = hashMap[index]; //list in the index in which the new Pilot structure will be added.
    
    if(chain.size() >= table_size) //return false if the size of the list at the index has already reach the table size.
        return false;

    for(auto it : chain)
    {
        if(it.id == tempPilot.id)//If the id of the current index is equal to the Pilot being added, return false.
            return false;
    }

    chain.push_back(tempPilot); //adding the Pilot to the hash map.

    return true;
}