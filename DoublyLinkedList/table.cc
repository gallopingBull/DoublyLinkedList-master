/*
 * @file table.cpp
 * 
 * @brief
 *    Implementation of a class to represent a restaurant table.
 *
 * @author Joshua Salcido
 * @Date 2/4/16
 */

#include "table.h"

Table::Table(){
    tableID = nullptr;
    numSeats = 0; 
    serverName = nullptr;
    timer = 0; 
    party = nullptr; 
}

//Table constructor 
Table::Table(const string& tableID, int numSeats, const string& serverName){ 
   
   this->tableID = new string(tableID);
   this->numSeats = numSeats;
   this->serverName = new string (serverName); 
}

//Table destructor 
Table::~Table(){
    delete tableID;
    delete serverName; 
}

// Assign a party object to this table object
void Table::seatParty(const Party* newParty){
    party = newParty;
}

 
