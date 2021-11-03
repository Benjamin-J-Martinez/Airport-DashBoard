#include "Plane_DataTable.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

/**
 * Function:    Plane Data Table Constructor
 * Parameters:  a string file representing the file location of the file.
 * Return:      N/A
 * Description: Initializes the hashMap in the class with the data in the file.
 */
Plane_DataTable::Plane_DataTable(string file)
{
    fileLocation = file; //storing the file path.
    
    for(auto &it : hashMap) //initializing all ids of plane strucuters to -1 which is equivalent to empty;
    {
        it.id = -1;
    }

    ifstream in(file); //creating input file stream from the filepath.
    int id; 
    string line, strID;

    getline(in, line); //ignoring the first line of the file.
    
    while(getline(in, line)) //while loop to get each row in the file to store the data.
    {
        stringstream ss(line); //creating string stream each line in the row.
        getline(ss, strID, ','); //getting the contents of the string delimited by a comma.
        id = stoi(strID); //parsing the string into an integer
        int index = hash(id); //hashing the ID key to determine the index in which the Plane structure will be added too in the hashMap.

        //setting all the plane structure data members from the contents in each row using getline delimited by a comma.
        hashMap[index].id = id;
        getline(ss, hashMap[index].maker, ',');
        getline(ss, hashMap[index].model, ',');
        getline(ss, hashMap[index].lastMaint, ',');
        getline(ss, hashMap[index].lastMaintA, ',');  
    } 
}

/**
 * Function:    Hash
 * Parameters:  an integer value key which represents the key that will be hashed.
 * Return:      an integer value which represents the hashed key.
 * Description: This hash function uses modulo to hash the key by the table size.
 */
int Plane_DataTable::hash(int key)
{
    return key % table_size;
}

/**
 * Function:    Insert
 * Parameters:  A string value, plame, which contains the contents of the new Plane structure dilemited by commas. 
 * Return:      N/A
 * Description: This function inserts plane structures into the hashMap using a linear probing collision method.
 */
bool Plane_DataTable::insert(string plane)
{
    Plane tempPlane; //temp plane structure
    stringstream ss(plane); //string stream object with the string of the plane.
    string strID;
    int id;

    //storing the contents of the parameter into the Plane structure.
    getline(ss, strID, ',');
    getline(ss, tempPlane.maker, ',');
    getline(ss, tempPlane.model, ',');
    getline(ss, tempPlane.lastMaint, ',');
    getline(ss, tempPlane.lastMaintA, ',');
    id = stoi(strID);
    tempPlane.id = id;

    int index = hash(id); //hashing the id of the plane as the key to get the index.
    int bucketsProbed = 0; //variable to keep track how many of the buckets have been probed.

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

void Plane_DataTable::print()
{
    cout << "File Name: " << fileLocation << endl;
    cout << "Insert Content: ['ID', 'Maker', 'Model', 'LastMaint', 'LastMaintA']" << endl;

    for(const auto it : hashMap)
    {
        cout << it.id << " " << it.maker << " " << it.model << " " << it.lastMaint << " " << it.lastMaintA << endl;
    }
}



