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
    
    for(auto &it : hashMap) //initializing all maker strings the of plane strucuters to "empty".
    {
        it.maker = "empty";
    }

    ifstream in(file); //creating input file stream from the filepath. 
    string line, maker, model, strFly, strGround;

    getline(in, line); //ignoring the first line of the file.
    
    while(getline(in, line)) //while loop to get each row in the file to store the data.
    {
        stringstream ss(line); //creating string stream each line in the row.

        //getting the contents of the string delimited by a comma.
        getline(ss, maker, ','); 
        getline(ss, model, ',');
        getline(ss, strFly, ',');
        getline(ss, strGround, ','); 

        int index = hash(maker, model); //hashing the maker and model key to determine the index in which the Plane Type structure will be added too in the hashMap.

        //setting all the plane type structure data members from the contents in each row using getline delimited by a comma.
        hashMap[index].maker = maker;
        hashMap[index].model = model;
        hashMap[index].flyingSpeed = stoi(strFly);
        hashMap[index].groundSpeed = stoi(strGround);
         
    } 
}

/**
 * Function:    Hash
 * Parameters:  an integer value key which represents the key that will be hashed.
 * Return:      an integer value which represents the hashed key.
 * Description: This hash function uses modulo to hash the key by the table size.
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
 * Description: This function inserts plane type structures into the hashMap using a linear probing collision method.
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

    int index = hash(tempPlaneType.maker, tempPlaneType.model); //hashing the id of the plane as the key to get the index.
    int bucketsProbed = 0; //variable to keep track how many of the buckets have been probed.
    int i = 0;
    index %= table_size;
    while(bucketsProbed < table_size) //while loop to iterate until all the buckets have been probed.
    {
        if(hashMap[index].id == -1) //If the index is emtpy add the plane to the hashMap.
        {
            hashMap[index] = tempPlane;
            return true;
        }
        
        if(hashMap[index].id = id) //If the id of the current index is equal to the id being added return false.
            return false;

        index = hash(index + 1); //incrementing the index and hashing it again.
        bucketsProbed++; //incrementing the buckets probed variable.
    }

    return false;
}