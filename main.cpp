//
//  main.cpp
//  ListasEnlazadas
//
//  Created by Sebastian Acosta Molina on 2023-03-04.
//


#include"LinkedList.hpp"
#include "Guest.hpp"
#include "GuestRecords.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <cstdlib>

using std::endl;
using std::cout;
using std::cin;

class Menu{
private:
    GuestRecords Hotel;
    
    
    
    void readGuest(){
       
        string guestName;
        int numberRoom;
        bool roomavailable ;
        do{
            std::cout << "Porfavor indique el nombre con apellido" << endl;
            std::getline(std::cin, guestName);
          //  std::cin.ignore();
            std::cout<< "Porfavor indique el numero habitacion que le gustaria" << endl;
            std::cin>> numberRoom;
            std::cin.ignore();
           
            int selectedRoom =  this-> Hotel.NewGuest(guestName, numberRoom);
            if(  selectedRoom == numberRoom){
                cout << "La habitacion que escogio esatba disponible, felicidades!" <<endl;
                roomavailable = true;
            }else if(selectedRoom != 0){
                cout << "La habitacion no estaba disponible, se le proveera una de al lado "<<endl;
                roomavailable = true ;
            }else{
                roomavailable = false;
            }
        }while( !roomavailable );
        
        cout << "EL nuevo huesped ha sido alojado, disfrute su estancia!! " << endl;
        sleep(5);
    }
    
    void deleteGuest(){
        cout << "Porfavor escriba el nombre del usuario que desea eliminar de la lista de huespedes"<<endl;
        
        string guestodelete;
        int numberRoom;
        std::getline(std::cin, guestodelete);
        std:: cin.ignore();
        cout << "Porfavor escriba el numero de habitacion del usuario que desea eliminar de la lista de huespedes"<<endl;
        cin >> numberRoom;
        
        Guest todelete(numberRoom, guestodelete);
        
        this->Hotel.ExitGuest(todelete);
        
        cout << "Se ha eliminado de la lista con exito " <<endl;
        sleep(2);
        
        
    }
    
   
                
    void getGuest(){
        char choice = 'O';
        char again = 'J';
        do{
            std::cout << "Quisieras encontrar el huesped por su nombre o numero de habitacion?"<< endl;
            cout<< "Presiona N si sabes su habitacion, presiona G si conoces su nombre "<<endl;
            cin>>choice;
            cin.ignore();

            if(choice == 'N'){
                int numberRoom = -1;
                cout << "Porfavor ingrese el numero de habitacion"<< endl;
                cin>> numberRoom;
                cin.ignore();
                string result1 =  Hotel.GetGuest(numberRoom);
                if(! (result1 == "")){
                    cout << "El nombre del huesped es " <<result1 <<endl;
                }else{
                    cout <<"No se encontro el huesped, la habitacion esta vacia "<< endl;
                }
            }
            else if(choice == 'G'){
                string guestName = "";
                cout << "Porfavor ingrese el nombre del huesped "<< endl;
                
                std::getline(cin, guestName);
               
                int resultint = this->Hotel.GetGuest(guestName);
                if( resultint  == -1){
                    cout <<"No se encontro el huesped, la habitacion esta vacia "<< endl;
                }else{
                    cout << "El numero de habitacion es " << resultint   <<endl;
                }
            }else{
                cout << "No elegio una opcion valida "<<endl;
            }
            cout << "Desea buscar otro huesped? Y/N" <<endl;
            cin >> again;
        } while(again == 'Y');
    }

    
    void printList(){
        
        cout << "Desea ver la lista en orden de llegada presione 1 si prefiere verla en orden alafabetico presione 2"<<endl;
        
        int choice = -1;
        
        cin>>choice;
        string ans = choice == 1? "de llegada" :"alfabetico";
        
        cout << "Se le mostrara la lista en orden " <<ans  <<endl;
        
        if(choice == 1){
            this-> Hotel.ShowListChronologically();
            sleep(2);
        }else {
            this-> Hotel.ShowListAlphabetically();
            sleep(2);
        }
        
    }
    
    void printNeighBours(){
        
        cout<<"Porfavor seleccione una habitacion para buscar sus vecinos"<<endl;
        
        int number;
        
        cin >> number;
        
        std::vector<string> v( this->Hotel.getNeighbours(number));
        
        if(v.size() == 0 ){
            cout << "No tiene vecinos " << endl;
            return;
        }else{
            for(auto element : v ){
                std::cout << "Este es el nombre de su vecino "   << element  << endl ;
            }
        }
        sleep(2);
        
        
        
    }
    
    
    
    

    
    void printMenu(){
     
        cout << "Menu" << endl;
        cout << "Porfavor escoja una de las siguientes opciones : " << endl;
        cout << "Oprima 1: Agregar un nuevo huesped" << endl;
        cout << "Oprima 2: BUscar un usuario existente" << endl;
        cout << "Oprima 3: Mostrar la lista existente" << endl;
        cout << "Oprima 4 : Consultar vecinos" << endl;
        cout << "Oprima 5: Elmiminar un huesped de la lista"<<endl;
        cout << "Oprima 6: Salir " << endl;
        
        
        
        
    }
    
public:
    
    void activateMenu(){
        printMenu();
       int option   ;
        
        cin >>option;
        std::cin.ignore();
        
        bool repeat = true ;
      
        do{
          
            
            switch (option ) {
                case -1:
                    repeat = false;
                    
                case 1:
                    readGuest();
                    break;
                case 2:
                    getGuest();
                    break;
                case 3:
                    printList();
                    break;
                case 4:
                    printNeighBours();
                    break;
                case 5:
                    deleteGuest();
                    break;
                    
                case 6:
                    cout << "Muchas gracias por su interaccion, hasta pronto!"<<endl;
                    repeat = false;
                    break;
                default:
                    repeat = false;
                    break;
            }
            
            if(repeat){
                printMenu();
                cin >>option;
                cin.ignore();
            }
           
        }while(repeat   );
        
        
        
    }
    
    
    
    
    
};




int main(){
    


   
    Menu menu;
    
    menu.activateMenu();
    
 
}
