
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
            
            //Just holds the first temp item we find, 
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
            itemCount--;
            
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
            
            //Moving to next node
            tempCurrentFirstNodeToCheck = tempCurrentFirstNodeToCheck->getNext();
        }
        
        //After loop ends, we are at last position and we can just add the node
        tempCurrentNewNode->setItem(tempNodeToBeAdded);
        tempCurrentFirstNodeToCheck->setNext(tempCurrentNewNode);
        itemCount++;
        tempNodeIsAdded = true;
    }
    else {

        //If empty just set it to the node to be added
        headPtr->setItem(tempNodeToBeAdded);
        itemCount++;
    }
    
    return tempNodeIsAdded;
}


        
//counts number of nodes in the linked bag iteratively
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
    
    int tempTotalNodeCount = 0;
    
    if(isEmpty()) {
        
        tempTotalNodeCount = 0;
    }
    
    else {
        
        //Loop through all the nodes, then add one as we loop
        for(Node<ItemType>* tempCurrentFirstNodeToCheck = headPtr; tempCurrentFirstNodeToCheck != nullptr; tempCurrentFirstNodeToCheck = tempCurrentFirstNodeToCheck->getNext()) {
            
            tempTotalNodeCount++;
        }
    }
    
    return tempTotalNodeCount;
} 

//counts the number of nodes in the linked bag recursively. use helper function
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
    
    Node<ItemType>* tempCurrentFirstNodeToCheck = headPtr;
    
    //If Empty return 0
    if(isEmpty()) {
        
        return 0;
    }
    //If not empty, contains something, run the recursive helper method
    else {
        
        return getCurrentSize340RecursiveHelper(tempCurrentFirstNodeToCheck);
    }
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* tempCurrentNodeToCheck) const {
    
    int tempTotalNodeCount = 0;
    
    //If the node we are checking is null, don't count it
    if(tempCurrentNodeToCheck == nullptr) {
        
        return tempTotalNodeCount;
    }
    else {
        
        //Double check to see if there is actually a node is null
        if(tempCurrentNodeToCheck != nullptr) {
            
            tempCurrentNodeToCheck = tempCurrentNodeToCheck->getNext();
            
            //Add one as we move next
            tempTotalNodeCount++;
            
            //As we add one, we have to also run the method again recursively as long as the next is null, until we reach end
            return tempTotalNodeCount + getCurrentSize340RecursiveHelper(tempCurrentNodeToCheck);
        }
    }
    
}   

//counts the number of nodes in the linked bag
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
    
    int tempTotalNodeCount = 0;
    
    static Node<ItemType>* tempCurrentFirstNodeToCheck = headPtr;
    
    if(isEmpty()) {
        
        return 0;
        
    }
    else {
        
        if(tempCurrentFirstNodeToCheck != nullptr) {
            
            tempCurrentFirstNodeToCheck = tempCurrentFirstNodeToCheck->getNext();
        
            tempTotalNodeCount++;
        
            return tempTotalNodeCount + getCurrentSize340RecursiveNoHelper();
        }
        
    }
     
}


        
//recursively counts the number of times an entry appears in the linked bag
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& tempValueToBeChecked) const {
    
    Node<ItemType>* tempCurrentFirstNodeToCheck = headPtr;
    
    if(isEmpty()) {
        
        return 0;
    }
    else {
        
        return getFrequencyOf340RecursiveHelper(tempCurrentFirstNodeToCheck, tempValueToBeChecked);
    }
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* tempNodeToBeChecked, const ItemType& tempValueToBeChecked) const {
    
    int tempNodeFrequencyCount = 0;   
    
    if(tempNodeToBeChecked == nullptr) {
        
        return tempNodeFrequencyCount;
    }
 
    else {
        
        if(tempNodeToBeChecked->getItem() == tempValueToBeChecked) {
            
            tempNodeFrequencyCount++;
            
            tempNodeToBeChecked = tempNodeToBeChecked->getNext();
        
            return tempNodeFrequencyCount + getFrequencyOf340RecursiveHelper(tempNodeToBeChecked, tempValueToBeChecked);
        }
        
        else {
            
            tempNodeToBeChecked = tempNodeToBeChecked->getNext();
        
            return tempNodeFrequencyCount + getFrequencyOf340RecursiveHelper(tempNodeToBeChecked, tempValueToBeChecked);
        }
    }
    
}
    


//recursively counts the number of times an entry appears in the linked bad. This recursive function does not use any helper functions
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& tempValueToBeChecked) const {
 
    static Node<ItemType>* tempCurrentFirstNodeToCheck = headPtr;
    
    int tempNodeFrequencyCount = 0; 
    
    if(isEmpty()) {
        
        return 0;
    }
    else {
        
        if(tempCurrentFirstNodeToCheck != nullptr) {
       
            if(tempCurrentFirstNodeToCheck->getItem() == tempValueToBeChecked) {
            
                tempNodeFrequencyCount++;
                
                tempCurrentFirstNodeToCheck = tempCurrentFirstNodeToCheck->getNext();
        
                return tempNodeFrequencyCount + getFrequencyOf340RecursiveNoHelper(tempValueToBeChecked);
            }        
            else {
                
                tempCurrentFirstNodeToCheck = tempCurrentFirstNodeToCheck->getNext();
        
                return tempNodeFrequencyCount + getFrequencyOf340RecursiveNoHelper(tempValueToBeChecked);
            }
        }
        else {
            
            tempCurrentFirstNodeToCheck = headPtr;
        }
    }

    return tempNodeFrequencyCount;
}


        
//removes a random entry from the linked bag
template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {
    
    
    
    return 0;
}
        
        
        
        
        

        
        
        
        
        
        

        
        

