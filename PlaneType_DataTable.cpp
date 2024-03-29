#include "PlaneType_DataTable.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

/**
 * Function:    Plane Type Data Table Constructor
 * Parameters:  a string file representing the file location of the file.
 * Return:      N/A
 * Description: Initializes the hashMap in the class with the data in the file.
 */
PlaneType_DataTable::PlaneType_DataTable(string file)
{
    fileLocation = file; //storing the file path.
    
    for(auto &it : hashMap) //initializing all maker strings in the of plane type structures to "empty".
    {
        it.maker = "empty";
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
 * Description: This hash function uses modulo to hash the mulitplicative string key by the table size.
 */
int PlaneType_DataTable::hash(string key1, string key2)
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
 * Parameters:  A string value, plame, which contains the contents of the new Plane structure dilemited by commas. 
 * Return:      N/A
 * Description: This function inserts plane type structures into the hashMap using a quadratic probing collision method.
 */
bool PlaneType_DataTable::insert(string planeType)
{
    PlaneType tempPlaneType; //temp plane type structure
    stringstream ss(planeType); //string stream object with the string of the plane.

    string strFly, strGround;
    //storing the contents of the parameter into the Plane structure.
    getline(ss, tempPlaneType.maker, ',');
    getline(ss, tempPlaneType.model, ',');
    getline(ss, strFly, ',');
    getline(ss, strGround, ',');
    tempPlaneType.flyingSpeed = stoi(strFly);
    tempPlaneType.groundSpeed = stoi(strGround);

    int index = hash(tempPlaneType.maker, tempPlaneType.model); //hashing the maker and models of the planetype as the key to get the index.
    int bucketsProbed = 0; //variable to keep track how many of the buckets have been probed.
    int i = 0;
    while(bucketsProbed < table_size) //while loop to iterate until all the buckets have been probed.
    {
        if(hashMap[index].maker == "empty") //If the index is emtpy add the plane to the hashMap.
        {
            hashMap[index] = tempPlaneType;
            return true;
        }
        
        if((hashMap[index].maker == tempPlaneType.maker) && (hashMap[index].model == tempPlaneType.model)) //If the id of the current index is equal to the id being added, return false.
            return false;

        i++;
        index = (hash(tempPlaneType.maker, tempPlaneType.model) + i + i*i) % table_size; //incrementing the index and hashing it again.
        bucketsProbed++; //incrementing the buckets probed variable.
    }

    return false;
}