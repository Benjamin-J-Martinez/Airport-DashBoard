#include "Reservation_DataTable.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

/**
 * Function:    Reservation Data Table Constructor
 * Parameters:  a string file representing the file location of the file.
 * Return:      N/A
 * Description: Initializes the hashMap in the class with the data in the file.
 */
Reservation_DataTable::Reservation_DataTable(string file)
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
 * Parameters:  3 string values which represents the keys that will be hashed.
 * Return:      an integer value which represents the hashed key.
 * Description: This hash function uses modulo to hash the multiplicative string key by the table size.
 */
int Reservation_DataTable::hash(string key1, string key2, string key3)
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
 * Parameters:  A string value, Reservation, which contains the contents of the new Reservation structure dilemited by commas. 
 * Return:      N/A
 * Description: This function inserts Reservation structures into the hashMap using a chaining collision method.
 */
bool Reservation_DataTable::insert(string reservation)
{
    Reservation tempReservation; //temp Reservation structure
    stringstream ss(reservation); //string stream object with the string of the plane.

    //storing the contents of the parameter into the Reservation structure.
    getline(ss, tempReservation.passID, ',');
    getline(ss, tempReservation.flno, ',');
    getline(ss, tempReservation.fdate, ',');
    getline(ss, tempReservation.fromA, ',');
    getline(ss, tempReservation.toA, ',');
    getline(ss, tempReservation.seatClass, ',');
    getline(ss, tempReservation.dateBooked, ',');
    getline(ss, tempReservation.dateCancelled, ',');

    int index = hash(tempReservation.passID, tempReservation.flno, tempReservation.fdate); //hashing the passId, flno, and fDate of the Reservation as the key to get the index.
    auto& chain = hashMap[index]; //list in the index in which the new Reservation structure will be added.
    
    if(chain.size() >= table_size) //return false if the size of the list at the index has already reach the table size.
        return false;

    for(auto it : chain)
    {
        if((it.passID == tempReservation.passID) && (it.flno == tempReservation.flno) && (it.fdate == tempReservation.fdate))//If the passId, flno, and fDate of the current index is equal to the Reservation being added, return false.
            return false;
    }

    chain.push_back(tempReservation); //adding the Reservation to the hash map.

    return true;
}