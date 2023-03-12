//
//  Guest.h
//  ListasEnlazadas
//
//  Created by Sebastian Acosta Molina on 2023-03-04.
//

#ifndef Guest_h
#define Guest_h

#include <string>
using std::string;

class Guest{
  
private:
    int numberRoom;
    string guestName;
    
public:
    // No hare los big five debido a 1 no se require para la tarea y 2 no manejo memoria ent no lo veo tan necesario
    Guest();
    
    ~Guest();
    
    Guest(int, string);
    
    int getNumberRoom();
    
    string getGuestName();
    
    void print() const ;
    
     bool operator > (const Guest) ;
    
     bool operator < (const Guest)  ;
    
    bool operator == (const Guest) const ;
    
    
};


#endif /* Guest_h */
