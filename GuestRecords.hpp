//
//  GuestRecords.h
//  ListasEnlazadas
//
//  Created by Sebastian Acosta Molina on 2023-03-05.
//

#ifndef GuestRecords_h
#define GuestRecords_h

#include "LinkedList.hpp"
#include <fstream>
#include <string>
#include<vector>


class GuestRecords : public LinkedList<Guest>{
    
private:
    
    const static string FILENAME;
    
    LinkedList<Guest> ChronologicalList;
    
    LinkedList<Guest> AlphabeticalList;
    
    void ReadFile();
    
    void AddGuestToList(Guest);
    
    void WriteToFile(Guest);
    
    void RemoveFromFile(Guest, string);
    
    void ReplaceFile(string FileNewName, string fileToDelete);
    
  
    
public:
    
    // Debido a que ya no voy a necesita manejar memoria opto por no usar el big 5
  
    GuestRecords(); // lee el archivo desde el inicio
    
    ~GuestRecords();
    
    int NewGuest(string guestName, int possibleRoomNumber);
    
    void ExitGuest(Guest);
    
    string GetGuest(int);
    
    int GetGuest(string);
    
    void ShowListChronologically();
    
    void ShowListAlphabetically();
    
    std::vector<string> getNeighbours(int);
    
    
    
};

#include "GuestRecords.cpp.h"

#endif /* GuestRecords_h */
