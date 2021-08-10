/*
 * @file party.cpp 
 *
 * @brief
 *    Implementation of a party of diners in a restaurant. 
 * 
 * @author Joshua Salcido 
 * @date 2/4/16
 */

#include "party.h" 

Party::Party(){
    reservationName = nullptr;
    numDiners = 0;
    timeRequired = 0; 
}

Party::Party(const string& reservationName, int numDiners, int timeRequired){
    this->reservationName = new string (reservationName);
    this->numDiners = numDiners;
    this->timeRequired = timeRequired; 
}

Party::~Party(){
    
    delete reservationName; 
}

