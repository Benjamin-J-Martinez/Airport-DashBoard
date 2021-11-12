#include "Plane_DataTable.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
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
    numWrites = 0; //setting the number of writes of the object to 0.
    
    for(auto &it : hashMap) //initializing all ids of plane strucuters to -1 which is equivalent to empty;
    {
        it.id = -1;
    }

    ifstream in(file); //creating input file stream from the filepath.
    string line;

    getline(in, line); //ignoring the first line of the file.
    
    while(getline(in, line)) //while loop to get each row in the file to store the data.
        insert(line);

    in.close();
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
        if((hashMap[index].id == -1) || (hashMap[index].id == -2)) //If the index is emtpy add the plane to the hashMap.
        {
            hashMap[index] = tempPlane;
            return true;
        }
        
        if(hashMap[index].id == id) //If the id of the current index is equal to the id being added return false.
            return false;

        index = hash(index + 1); //incrementing the index and hashing it again.
        bucketsProbed++; //incrementing the buckets probed variable.
    }

    return false;
}


/**
 * Function:    Update
 * Parameters:  A string value, plane, which contains the contents of the new Plane structure dilemited by commas. 
 * Return:      True if the Plane strucuture was update false otherwise.
 * Description: This function updates a plane structures in the hashMap using a linear probing collision method.
 */
bool Plane_DataTable::update(string plane)
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

    while((hashMap[index].id !=  -1) && (bucketsProbed < table_size)) //while loop to iterate until all the buckets have been probed.
    {
        if((hashMap[index].id == tempPlane.id)) //If the index is emtpy add the plane to the hashMap.
        {
            hashMap[index] = tempPlane;
            return true;
        }

        index = hash(index + 1); //incrementing the index and hashing it again.
        bucketsProbed++; //incrementing the buckets probed variable.
    }

    return false;
}

/**
 * Function:    Remove
 * Parameters:  A string value, plane, which contains the contents of the Plane structure dilemited by commas. 
 * Return:      True if the plane was removed false otherwise.
 * Description: This function removes a plane structure in the hashMap using a linear probing collision method.
 */
bool Plane_DataTable::remove(string plane)
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

    while((hashMap[index].id !=  -1) && (bucketsProbed < table_size)) //while loop to iterate until all the buckets have been probed.
    {
        if((hashMap[index].id == tempPlane.id)) //If the planes are equal to eachother remove the plane from the hashMap.
        {
            Plane emptyPlane;
            emptyPlane.id = -2;
            hashMap[index] = emptyPlane;
            return true;
        }

        index = hash(index + 1); //incrementing the index and hashing it again.
        bucketsProbed++; //incrementing the buckets probed variable.
    }

    return false;
}

/**
 * Function:    Print
 * Parameters:  N/A
 * Return:      N/A
 * Description: This function prints the contents of the plane.
 */
void Plane_DataTable::print()
{
    cout << "File Name: " << fileLocation << endl;
    cout << "Insert Content: ['ID', 'Maker', 'Model', 'LastMaint', 'LastMaintA']" << endl;
    cout << setw(3) << "ID" << setw(8) << "Maker" << setw(9) << "Model" << setw(11)  << "LastMaint" << setw(11) << "LastMaintA" << endl;

    for(const auto it : hashMap)
    {
        if((it.id != -1) && (it.id != -2))
            cout << setw(3) << it.id << setw(8) << it.maker << setw(9) << it.model << setw(11)  << it.lastMaint << setw(11) << it.lastMaintA << endl;
    }
}

/**
 * Function:    Write
 * Parameters:  N/A
 * Return:      N/A
 * Description: This function writes the contents of the hashMap to a new file in the data folder.
 */
void Plane_DataTable::write()
{
    numWrites++; //incremement number of writes.
    string newFile = fileLocation; //creating a string which will be the location of the new file.
    string version = "_v" + to_string(numWrites); //creating a string of the version to be added to the newFile.
    newFile.insert(newFile.size()-4, version); //creating the new file location.

    ofstream out(newFile); //oppening the new file location.

    //writing the contents of the hashMap to the new file dilemited by commas.
    out << "ID" << ',' << "Maker" << ',' << "Model" << ',' << "LastMaint" << ',' << "LastMaintA" << endl;
    for(auto it : hashMap)
    {
        if((it.id != -1) && (it.id != -2))
            out << it.id << ',' << it.maker << ',' << it.model << ',' << it.lastMaint << ',' << it.lastMaintA << endl; 
    }

    out.close(); //closing the output stream.
}




