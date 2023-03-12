//
//  Guest.cpp
//  ListasEnlazadas
//
//  Created by Sebastian Acosta Molina on 2023-03-04.
//

#include "Guest.hpp"
#include <iostream>

int numberRoom;
string guestName;

Guest::Guest(){};

Guest::~Guest(){};

Guest::Guest(int RoomNumber, string name){
    
    this-> numberRoom = RoomNumber;
    this-> guestName = name;
}

int Guest::getNumberRoom(){
    
    return this->numberRoom;
}

string Guest::getGuestName(){
    return this-> guestName;
}

void Guest::print() const{
    std::cout << this->guestName << std::endl;
    std::cout << this->numberRoom << std::endl;
    
}

/// string guestName;
bool Guest::operator > (const Guest compare) {
    

    
    return  this-> guestName > compare.guestName;
    
   
}

bool Guest::operator < (const Guest compare){
    return  this-> guestName < compare.guestName;
}

bool Guest::operator == (const Guest compare) const{
    return  this-> guestName ==  compare.guestName;
}
