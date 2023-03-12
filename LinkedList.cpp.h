//
//  LinkedList.cpp
//  ListasEnlazadas
//
//  Created by Sebastian Acosta Molina on 2023-03-04.
//

#include "LinkedList.hpp"
#include "Guest.hpp"




// default constructor
template <typename T>
LinkedList<T>::LinkedList(){
    head = tail = nullptr;
    count = 0;
    
}
//copy constuctor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copy){
    
    // deep copy
    Node<T>* current = copy.head;
    while(current != copy.tail){
        // add (current-> data)
        current = current->next;
        
        
    }
    if(copy.tail != nullptr)
    //add cop.tail
    
    current = nullptr;
    this-> count = copy.count;
    
    
    
    
}

//move constructor
template <typename T>
LinkedList<T>::LinkedList( LinkedList<T>&&copy ){
    
    //shallow copy
 
        
        head = copy.head ;
        tail = copy.tail;
        
        copy.head = copy.tail = nullptr;
        
        this-> count = copy.count;
        
        copy.count = 0 ;
        
        
        

    
    
    
}



//copy assingmnet operator
template <typename T>
void LinkedList<T>::operator = (const LinkedList<T> &copy){
    
    
    if(this != copy){
        // deep copy
        Node<T>* current = copy.head;
        while(current != copy.tail){
            // add (current-> data)
            current = current->next;
            
            
        }
        
        if(copy.tail != nullptr)
        //add cop.tail
        
        current = nullptr;
        
        
        this-> count = copy.count;
        
        
        
        
    }
    
    
}

//move copy constructor
template <typename T>
void LinkedList<T>::operator = (LinkedList<T>&&copy){
    
    if(this!= copy){
        
        head = copy.head ;
        tail = copy.tail;
        
        copy.head = copy.tail = nullptr;
        
        this-> count = copy.count;
        
        copy.count = 0 ;
        
        
        
        
    }
    
    
}

//destructor
template <typename T>
LinkedList<T>::~LinkedList(){
    
   
    Node<T>* current = this->head;
    Node<T>*temp = nullptr;
   while (current != nullptr) {
       temp = current;
       current = current->next;
       delete temp;
   }
    this-> head = this-> tail = nullptr;
    current = nullptr;
    temp = nullptr;
        
    
    
}

template <typename T>
bool LinkedList<T>::  AddAt(int index, T  DATA){
  
    Node<T>* NEWNODE = new Node<T>(DATA);
    
    // check some cases
    
    // is index within the range?

    if(index > count) return false;
    
    if(index == count ) return AddLast(DATA);
    
    if(index == 0 ) return AddBegin(DATA);
    
    // find the correct spot
    
    Node<T>* current = this-> head;
    int currentNode = 0;
    while(currentNode < index-1){
        
        currentNode++;
        current = current-> next;
        
    }
    
    current-> next -> prev  = NEWNODE;
    
    NEWNODE -> next = current-> next;
    
    NEWNODE-> prev = current;
    
    current-> next = NEWNODE;
    
    NEWNODE = current = nullptr;

    count ++;
    
    return  true;
  
    
}

template <typename T>
bool LinkedList<T>::AddBegin(T DATA){
    
    Node<T>* NEWNODE = new Node<T>(DATA);
    
    if(this-> head == nullptr){
        this-> head = this-> tail = NEWNODE;
        NEWNODE = nullptr;
        count++;
        return true;
    }
    
    if(this-> head == this-> tail){
        this-> head = NEWNODE;
        NEWNODE -> next = this-> tail;
        this-> tail-> prev = NEWNODE;
        NEWNODE = nullptr;
        count++;
        return true;
    }
    
    if(this-> count >=2){
        this-> head -> prev = NEWNODE;
        NEWNODE-> next = this-> head;
        this-> head = NEWNODE;
        NEWNODE = nullptr;
        count++;
        return true;
    }
    
    return false;
    
}

template <typename T>
bool LinkedList<T>:: AddLast(T DATA){
    
    Node<T>* NEWNODE = new Node<T>(DATA);
    
    if(this-> head == nullptr){
        this-> head = this-> tail = NEWNODE;
        NEWNODE = nullptr;
        count++;
        return true;
    }
    
    if(this-> head == this-> tail){
       
        this-> head -> next = NEWNODE;
        NEWNODE-> prev = this-> head;
        this-> tail = NEWNODE;
        NEWNODE = nullptr;
        count++;
        return true;
    }
    
    if(this-> count >=2){
        this-> tail -> next = NEWNODE;
        NEWNODE-> prev = this-> tail;
        this-> tail = NEWNODE;
        NEWNODE = nullptr;
        count++;
        return true;
    }
    
    return false;
}



//delete node
template <typename T>
bool  LinkedList<T>::DeleteAt(int index){
    
      // check some cases
      
      // is index within the range?

      if(index >= count) return false;
      
      if(index == count -1) return DeleteLast();
      
      if(index == 0 ) return DeleteBgn();
      
      // find the correct spot
      
      Node<T>* current = this-> head;
      int currentNode = 0;
      while(currentNode <= index-1){
          
          currentNode++;
          current = current-> next;
          
      }
    
    current -> prev -> next = current -> next;
    
    current -> next -> prev = current -> prev;
    
    current-> next = current-> prev = nullptr;
    
    delete current;
    

      count --;
      
      return  true;
    
    
}

template <typename T>
bool  LinkedList<T>::DeleteBgn(){
    
    if(this-> head == this-> tail){
        delete this -> head;
        this-> head = this-> tail = nullptr;
        this->count--;
        return true;
    }
    
    if(this-> count >=2){
        //save ref of the next node after the head
        Node<T>* ref = this-> head-> next;
        this-> head -> next = nullptr;
        delete this->head;
        ref-> prev = nullptr;
        this-> head = ref;
        ref = nullptr;
        count--;
        return true;
        
    }
    
    return false;
    
}

template <typename T>
bool  LinkedList<T>::DeleteLast(){
    
    if(this-> head == this-> tail){
        delete this -> head;
        this-> head = this-> tail = nullptr;
        this->count--;
        return true;
    }
    
    if(this-> count >=2){
        Node<T>* ref = this-> tail -> prev;
        ref-> next = this-> tail -> prev = nullptr;
        delete this-> tail;
        this-> tail = ref;
        ref= nullptr;
        count--;
        return true;
        
    }
    
    return false;
    
}

// search
template <typename T>
Node<T>* LinkedList<T>:: SearchAt(int index){
    
    if(index >= count) return nullptr;
    
    if(index == 0 ) return this-> head;
    
    if(index == count-1) return this-> tail;
    
    Node<T>* current = this-> head;
    
    int currentNode = 0;
    
    while(currentNode <= index-1){
        
        currentNode++;
        current = current-> next;
    }
    
    return current;
    
    
}

template <typename T>
int LinkedList<T>::GetCount(){
    return this-> count;
}

template <typename T>
Node<T>* LinkedList<T>::getHead(){
    return this-> head;
}

template <typename T>
Node<T>* LinkedList<T>::getTail(){
    return this-> tail;
}

template<typename T>
void LinkedList<T>::PrintList()const{
   
    Node<T>* current = head;
    
    while (current != tail) {
        PrintIfGuest(current->data);
        current = current->next;
    }
    
    PrintIfGuest(tail->data);
    current = nullptr;
    
}


template <typename T>
void LinkedList<T>::PrintIfGuest(const T& data) const {
    const Guest* guest = dynamic_cast<const Guest*>(&data);
    if (guest != nullptr) {
      guest->print();
      
        guest = nullptr;
    }
 
}

template <typename T>
bool LinkedList<T>::IfGuest(const T &data)const{
    const Guest* guest = dynamic_cast<const Guest*>(&data);
    if (guest != nullptr)
        {
          
            guest = nullptr;
            return true;
        }
    
    return false;
}

template <typename T>
bool LinkedList<T>::AddAlphabetical(T DATA){
    
    
   if(! (IfGuest(DATA)) )
       return false;
    
 //   Node<T>* NEWNODE = new Node<T>(DATA);
    
    if(this-> head == nullptr){
        
      return   this->AddBegin(DATA);
        
    }
    
    if(this-> head == this-> tail){
        
        if(DATA < this-> head -> data ){
            
          return  this-> AddBegin(DATA);
        }else{
            return   this-> AddLast(DATA);
        }
      
    }
    
    if(this-> count >=2){
       
        Node<T>* count = this-> head;
        int index = 0;
        
        while(count != this-> tail ){
            
            if(DATA < count-> data){
                count = nullptr;
              return   this-> AddAt(index, DATA);
              
            }
            
            count = count -> next;
            index++;
            
            
        }
        
        // es menor que la cola
        
        if(DATA < this-> tail-> data){
            count = nullptr;
          return   this-> AddAt(index, DATA);
        }
        
        // no entro en ninguno
        
      return   this-> AddLast(DATA);
        
        
    }
    
    return false;
    
}
