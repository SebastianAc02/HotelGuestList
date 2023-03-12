//
//  GuestRecords.cpp
//  ListasEnlazadas
//
//  Created by Sebastian Acosta Molina on 2023-03-05.
//

#include "GuestRecords.hpp"
#include <vector>
#include <cstdio>
using namespace std;

using std::cout;
using std::endl;




const string GuestRecords::FILENAME = "/Users/sebastianacosta/HASH/ListasEnlazadas/ListasEnlazadas/HotelGuestList.txt";



void GuestRecords::ReadFile(){
    std::ifstream GuestFile(this-> FILENAME);

    try{
        if (!GuestFile) {
            throw std::runtime_error("Error al abrir el archivo") ;
        }
        
        
        string GuestName ;
        string GuestNumberRoom;
       
        while (std::getline(GuestFile, GuestName)  && std::getline(GuestFile,GuestNumberRoom )) {
           
            try {
                         Guest guestx(std::stoi(GuestNumberRoom), GuestName);
                         this-> AddGuestToList(guestx);
                     }
                     catch (const std::invalid_argument& e) {
                        // std::cerr << "Error al convertir el número de habitación en el archivo: " << e.what() << std::endl;
                     }
        }
        
        GuestFile.close();
    }catch(const std::runtime_error& error){
        cout <<"El path del archivo esta erroneo por favor revise la variable FILENAME y proporcione un path correcto, si necesita ayuda acuda a su terminal para tener una informacion precisa";
    }

}





void GuestRecords::AddGuestToList(Guest guest){
    
    AlphabeticalList.AddAlphabetical(guest);
    ChronologicalList.AddLast(guest);
    
   
    
}




void GuestRecords::WriteToFile(Guest guest){
    
    try{
        std::ofstream GuestFile(this-> FILENAME,  std::ios::app);
        
        if (!GuestFile) {
            throw std::runtime_error("Error al abrir el archivo") ;
        }
        
     
        GuestFile << guest.getGuestName()  <<endl;
        GuestFile  << guest.getNumberRoom() <<endl;
        
        GuestFile.close();
        
        
    }catch(const std::runtime_error& error){
        cout <<"El path del archivo esta erroneo por favor revise la variable FILENAME y proporcione un path correcto, si necesita ayuda acuda a su terminal para tener una informacion precisa";
    }
    
}



void GuestRecords::RemoveFromFile(Guest guest, string newFilePath){
    // reescribir el archivo a un archivo nuevo
    
    try{
        
        std::ifstream input(this-> FILENAME);
        std::ofstream output(newFilePath);
        
        if(!input || !output ){
            throw std::runtime_error("Error al abrir el archivo") ;
        }
        
        string line;
        
        int count = 0;
        while (std::getline(input, line) ) {
            count++;
            if (line == guest.getGuestName() || line == std::to_string(guest.getNumberRoom())) { // omite la tercera línea
                continue;
            }
            output << line << '\n';
        }
        input.close();
        output.close();
    }catch(const std::runtime_error& error){
        cout <<"El path del archivo esta erroneo por favor revise la variable FILENAME y proporcione un path correcto, si necesita ayuda acuda a su terminal para tener una informacion precisa";
    }
    
    
}

void GuestRecords::ReplaceFile(string FileNewName, string fileToDelete){
    
    auto eliminarFile = [](string fileToDelete) {
        
        int result = std::remove(fileToDelete.c_str());
        
           if (result == 0) {
               std::cout << "El archivo ha sido eliminado con éxito." << std::endl;
           } else {
               std::perror("Error al eliminar el archivo.");
           }
        
        return result;
    };
    
    
    auto replaceFileName = [](char* oldFile, char* newFile){
        int result = std::rename(oldFile, newFile );
        if (result == 0) {
            std::cout << "El archivo ha sido renombrado con éxito." << std::endl;
        } else {
            std::perror("Error al renombrar el archivo.");
        }
        
        return result;
        
    };
    
    eliminarFile(FileNewName);
    
    char* fileToDeleteChar = new char[fileToDelete.length() + 1];
    std::strcpy(fileToDeleteChar, fileToDelete.c_str());

    char* fileNewNameChar = new char[FileNewName.length() + 1];
    std::strcpy(fileNewNameChar, FileNewName.c_str());

    // Llamar a la función replaceFileName
    replaceFileName(fileToDeleteChar, fileNewNameChar);

    // Liberar memoria
    delete[] fileToDeleteChar;
    delete[] fileNewNameChar;
    
    //eliminarFile(fileToDelete);
    
    
    
    
}


GuestRecords::GuestRecords(){  // lee el archivo desde el inicio

    
    
    this-> ReadFile();
    
}

GuestRecords::~GuestRecords(){};

void GuestRecords::ExitGuest(Guest guest){
    
    RemoveFromFile(guest, "/Users/sebastianacosta/HASH/ListasEnlazadas/ListasEnlazadas/HotelGuestList2.txt");
    
    ReplaceFile(FILENAME, "/Users/sebastianacosta/HASH/ListasEnlazadas/ListasEnlazadas/HotelGuestList2.txt");
    
    //removefrom list
    
    
    
}

string GuestRecords::GetGuest(int hotelRoomNumber){
    
    if(ChronologicalList.getHead() == nullptr) return "";
    
   
    
    Node<Guest>* refHead = ChronologicalList.getHead();
    
  
  
    string guestToReturn = "";
    
    if(hotelRoomNumber==ChronologicalList .getTail()->data.getNumberRoom()){
        guestToReturn = ChronologicalList.getTail()-> data.getGuestName();
        refHead = ChronologicalList.getTail();
    }
    
    while(refHead != ChronologicalList.getTail()  ){
        
        if(hotelRoomNumber ==refHead-> data.getNumberRoom() ){
            guestToReturn = refHead-> data.getGuestName();
            break;
        }
        
       
        
        
        
        refHead = refHead-> next;
      
    }
    
    refHead  = nullptr;
    
    if(guestToReturn == ""){
        return "" ;
    }else{
        return guestToReturn;
    }
    
}

int GuestRecords::GetGuest(string guestName){
    
    if(this->ChronologicalList.getHead() == nullptr) return -1;
    
    Node<Guest>* refHead = this-> ChronologicalList.getHead();
    
    
    int guestToReturn = -1;
    
    if(guestName == this->ChronologicalList.getTail()->data.getGuestName()){
        guestToReturn = ChronologicalList.getTail()-> data.getNumberRoom();
        refHead = this->ChronologicalList.getTail();
    }
        
    
    while(refHead != this-> ChronologicalList.getTail()){
        
        if(guestName ==refHead-> data.getGuestName() ){
            guestToReturn = refHead-> data.getNumberRoom();
            break;
        }
        
        refHead = refHead-> next;
        
    }
    
    
  
    
    refHead  = nullptr;
    
    if(guestToReturn == -1){
        return -1;
    }else{
        return guestToReturn;
    }
    
}

void GuestRecords::ShowListChronologically(){
    
    this-> ChronologicalList.PrintList();
    
}

void GuestRecords::ShowListAlphabetically(){
    
    this-> AlphabeticalList.PrintList();
}

int GuestRecords::NewGuest(string guestName, int possibleRoomNumber){
    
    
    std::vector<int> myArray = { possibleRoomNumber, possibleRoomNumber-1,possibleRoomNumber+1};
    
    for (int i = myArray.size() - 1; i >= 0; i--) {
          if (GetGuest(myArray[i]) != "") {
              myArray.erase(myArray.begin() + i);
          }
      }
    
    
    if(myArray.size() == 0){
        cout <<"La habitacion esta ocupada, porfavor seleccione otro numero " << endl;
        return 0;
    }
    
    Guest newGuest(myArray[0] ,guestName );
    AddGuestToList(newGuest);
    
    WriteToFile(newGuest);
    return  myArray[0];
    
}


vector<string> GuestRecords::getNeighbours(int numberRoom){
    
    std::vector<int> myArray = { numberRoom-1, numberRoom+1};
    
    std::vector<string> myGuests ={};
    
    int guestCount = 0;
    
    for(auto element:myArray ){
        string result  =GetGuest(element);
        if(! (result  == ""))
            {
                myGuests.push_back(result);
                guestCount++;
            }
            
    }
    
    return myGuests;
    
    
    
    
}
