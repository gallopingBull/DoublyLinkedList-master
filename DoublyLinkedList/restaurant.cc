/**
 * @file restaurant.cc
 *
 * @brief
 *    Runs the restaurant simulation. 
 *
 * @author Joshua Salcido!
 * @date 2/5/16
 */
#include "restaurant.h"
#include <string>
#include <fstream> 
#include <iostream>
using namespace std; 

////// Reads in commands that initialize table and party objects and adds them to a doublylinked list.///////

void Restaurant::getInput(){

    string command;
    string object;
    
    // Table variables 
    Table *table;
    string serverName;
    string tableID;
    int numSeats = 0;
    
    //Party Variables
    Party *party;
    string reservationName; 
    int numDiners = 0; 
    int timeRequired = 0; 
 
    
    while(cin>>command){
        if(command == "table"){
          
            cin>>tableID;
            cin>>numSeats; 
            cin>>serverName;
            servers[serverName] = 0; 
            table  = new Table(tableID, numSeats, serverName); 

            available.append(table);
        }   
        else if (command == "party"){
       
            cin>>numDiners;
            cin>>reservationName; 
            cin>>timeRequired;
            party = new Party(reservationName, numDiners, timeRequired); 
            
            waiting.append(party); 
        }
        else if(command == "end") {
            break; 
        }
    }
}


///function runs the restaurant simulation//// 
void Restaurant::serveParties(){
   
    bool isOpen = true;
    Table *table;
    Table *tableA;
    Party *party;

    table = occupied.first();
    tableA = available.first(); 
    party = waiting.first();
    
    while(isOpen){
        while (!occupied.empty()){
            table->decrementTimer(); 
            if(table->getTimer() == 0){
                cout<<*party->getReservationName()<< " finished at " << *table->getTableID() << endl; 
                occupied.remove();
                table->clearTable();
                available.append(table);
            }
           table = occupied.next(); 
        }    
    
        while (!waiting.empty()){
            while(!available.empty()){
                cout << tableA->getNumSeats() << endl; 
                if(tableA->getNumSeats() >= party->getNumDiners()){
                    cout<<*party->getReservationName() << " seated at " << *tableA->getTableID() << endl; 
                    tableA->seatParty(party);
                    tableA->setTimer(party->getTimeRequired());
                    servers[*tableA->getServerName()] += party->getNumDiners(); 
                    available.remove();
                    waiting.remove(); 
                    occupied.append(tableA);
                }
                tableA = available.next(); 
            }
        }
    
        if(waiting.empty() && occupied.empty()){
            cout/* << serverName*/<< " served "/* << total */<< endl;  
            isOpen = false; 
        }
    }
}

int main() {
    
    Restaurant myDiner;
   
    
    myDiner.getInput();
    myDiner.serveParties();
    

    return 0; 

}
