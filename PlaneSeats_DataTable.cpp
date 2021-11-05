#include "PlaneSeats_DataTable.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

/**
 * Function:    pleane seats Data Table Constructor
 * Parameters:  a string file representing the file location of the file.
 * Return:      N/A
 * Description: Initializes the hashMap in the class with the data in the file.
 */
PlaneSeats_DataTable::PlaneSeats_DataTable(string file)
{
    fileLocation = file; //storing the file path.
    
    for(auto &it : hashMap) //initializing all maker strings in the of pleane seats structures to "empty".
    {
        for(auto &chain : it)
            chain.maker = "empty";
    }

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
int PlaneSeats_DataTable::hash(string key1, string key2, string key3)
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
 * Parameters:  A string value, planeSeats, which contains the contents of the new Plane Seats structure dilemited by commas. 
 * Return:      N/A
 * Description: This function inserts pleane seats structures into the hashMap using a chaining collision method.
 */
bool PlaneSeats_DataTable::insert(string planeSeats)
{
    PlaneSeats tempPlaneSeats; //temp pleane seats structure
    stringstream ss(planeSeats); //string stream object with the string of the plane.

    string strNoOfSeats;
    //storing the contents of the parameter into the Plane Seats structure.
    getline(ss, tempPlaneSeats.maker, ',');
    getline(ss, tempPlaneSeats.model, ',');
    getline(ss, tempPlaneSeats.seatType, ',');
    getline(ss, strNoOfSeats, ',');
    tempPlaneSeats.noOfSeats = stoi(strNoOfSeats);

    int index = hash(tempPlaneSeats.maker, tempPlaneSeats.model, tempPlaneSeats.seatType); //hashing the maker,models, and seatType of the PlaneSeats as the key to get the index.
    auto& chain = hashMap[index]; //list in the index in which the new Plane Seats structure will be added.
    
    if(chain.size() >= table_size) //return false if the size of the list at the index has already reach the table size.
        return false;

    for(auto it : chain)
    {
        if((it.maker == tempPlaneSeats.maker) && (it.model == tempPlaneSeats.model) && (it.seatType == tempPlaneSeats.seatType))//If the maker, model, and seatType of the current index is equal to the PlaneSeats being added, return false.
        return false;
    }

    chain.push_back(tempPlaneSeats);

    return true;
}