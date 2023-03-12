//
//  LinkedList.h
//  ListasEnlazadas
//
//  Created by Sebastian Acosta Molina on 2023-03-04.
//

#ifndef LinkedList_h
#define LinkedList_h

#include<iostream>
template <typename T>
class Node{
public:
    static int x ;
    T data;
    Node* next;
    Node* prev;
    
    // default constructor
    Node(T data){
        this-> data = data;
        next = prev = nullptr;
    }
    
    // destructor
    
    ~Node(){
        
        if(next == nullptr && prev == nullptr ) return;
        if(next != nullptr){
          
            next = nullptr;
            
        }
        if(prev != nullptr){
            prev = nullptr;
            
        }
    
        
        
    }
   
    
};

template<typename T>
int Node<T>::x = 0;

template <typename T>
class LinkedList{
  
private:
    Node<T>* head;
    Node<T>* tail;
    int count ;
    
   
    
public:
    
    // default constructor
    LinkedList<T>();
    //copy constuctor
    LinkedList<T>(const LinkedList<T>& )  ;
    
    //move constructor
    LinkedList<T>( LinkedList<T>&& );
    
    
    
    //copy assingmnet operator
    
    void operator = (const LinkedList<T> &);
    
    //move copy constructor
    
    void operator = (LinkedList<T>&&);
    
    //destructor
    
    virtual ~LinkedList();
    
   // add
    
    bool  AddAt(int, T );
    
    
    bool  AddBegin(T);
    
    bool AddLast(T);
    
    bool DeleteBgn();
    
    bool DeleteLast();
    
    int GetCount();
    
    //delete node
    
    bool DeleteAt(int);
    
    Node<T>* getHead();
    
    Node<T>* getTail();
    
    // search
    
    Node<T>* SearchAt(int);
 
    void PrintList() const;
    
    bool AddAlphabetical(T);
    
    bool  IfGuest(const T &data)const;
    
    void PrintIfGuest(const T& data) const;
    
    
};


#include "LinkedList.cpp.h"

#endif /* LinkedList_h */
