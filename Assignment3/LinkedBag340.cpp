
#include <iostream>
#include <string>
#include <vector>


#include <cstddef>
//#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "LinkedBag.h"

using namespace std;


//Deletes second node in linked bag
template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340() {
    
    bool tempNodeIsRemoved = false;
    
    //Assuming there is something inside here
    if(!isEmpty()) {
        
        //Initializing to equal the first node we find
        Node<ItemType>* tempCurrentFirstNodeToRemove = headPtr;
        
        //As long as the current node we are looking at is not null continue, and not yet removed a node yet
        if(tempCurrentFirstNodeToRemove != nullptr) {
            
            //Just holds the first item we find 
            Node<ItemType>* tempCurrentItemToGet = new Node<ItemType>();
            tempCurrentItemToGet = headPtr;
            
            //Next will be set to the next item from tempCurrentItem
            headPtr->getNext()->setItem(tempCurrentItemToGet->getItem());
            
            //Move to next
            headPtr = headPtr->getNext();
            
            //Remove the node we are finding. Set to nullptr then delete in order to remove a node
            tempCurrentFirstNodeToRemove->setNext(nullptr);
            delete tempCurrentFirstNodeToRemove;
            tempCurrentFirstNodeToRemove = nullptr;
            //itemCount--;
            
            //If removed assigned to true
            tempNodeIsRemoved = true;

        }
    }
    
    return tempNodeIsRemoved;
}

// Adds/inserts a node to the end of the linked bag
template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& tempNodeToBeAdded) {
    
    bool tempNodeIsAdded = false;
    
    //The head of the node
    Node<ItemType>* tempCurrentFirstNodeToCheck = headPtr;
    Node<ItemType>* tempCurrentNewNode = new Node<ItemType>();
    
    //Making
    if(!isEmpty()) {
        
        //Looping through to get the last position, if position->next is null, then that is last position
        while(tempCurrentFirstNodeToCheck->getNext() != nullptr) {
            
            tempCurrentFirstNodeToCheck = tempCurrentFirstNodeToCheck->getNext();
        }
        
        tempCurrentNewNode->setItem(tempNodeToBeAdded);
        tempCurrentFirstNodeToCheck->setNext(tempCurrentNewNode);
        itemCount++;
    }
    else {
        //*headPtr = tempNodeIsAdded;
        //headPtr->setItem(tempNodeToBeAdded);
    }
    
    return tempNodeIsAdded;
}


        
//counts number of nodes in the linked bag iteratively
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
    
    return 0;
}

        
//counts the number of nodes in the linked bag recursively. use helper function
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
    
    return 0;
}

        
//counts the number of nodes in the linked bag
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
    
    return 0;
}

        
//recursively counts the number of times an entry appears in the linked bag
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType&) const {
 
    return 0;
}

        
//recursively counts the number of times an entry appears in the linked bad. This recursive function does not use any helper functions
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType&) const {
 
    return 0;
}

        
//removes a random entry from the linked bag
template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {
    
    return 0;
}
        
        
        
        
        
        
        
        
        
        
        

        
        

