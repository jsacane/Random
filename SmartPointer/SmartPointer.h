/**
    SmartPointer.h
    Purpose: Implementation of class that wraps pointers and automatically garbage collects

    @author Jack Sacane
    @version 1.0 5/17/17
*/

#ifndef SMART_PTR_H
#define SMART_PTR_H

#include <iostream>
#include <map>

template <typename T>
class SmartPointer {
private:
    static std::map<T*, unsigned> referenceMap;   // maps address keys to reference counts
    T* ptr;                                       // points to the data object
public:

    /**
    *   Constructs a SmartPointer object that points to data of type 'T'.
    *
    *   @param Pointer to a data object of type 'T'.
    */
    SmartPointer(T* data_addr) {
        // point to the data object
        ptr = data_addr;
        // if the address of the data object being pointed to is not found in the reference map,
        // insert it and set its reference count to 1
        // else if it is found in the map, increment its reference count
        if (referenceMap.find(data_addr) == referenceMap.end()) {
            referenceMap[data_addr] = 1;
            std::cout << "Set to 1" << std::endl;
        } else {
            referenceMap[data_addr]++;
            std::cout << "Incremented reference count" << std::endl;
        }
    }

    /**
    *   Constructs a null SmartPointer.
    */
    SmartPointer() {
        ptr = NULL;
    }

    /**
    *   Destructs a SmartPointer object and garbage collects all the data that the SmartPointer
    *   is pointing to.
    */
    ~SmartPointer() {
        referenceMap[ptr]--;
        std::cout << "Decremented reference count" << std::endl;
        if (referenceMap[ptr] == 0) {
            delete ptr;
            std::cout << "Deleted dynamic data object" << std::endl;
        }
    }

    /**
    *   Overloads '=' operator to support pointer reassignment.
    *
    *   @param Reference to a SmartPointer object.
    *   @return Reference to the current SmartPointer object.
    */
    SmartPointer & operator=(SmartPointer & rhs) {
        if (ptr != NULL && ptr != rhs.ptr) {
            referenceMap[ptr]--; // if rhs is a new address, decrement the current reference count
        }
        ptr = rhs.ptr;           // reassign ptr
        referenceMap[ptr]++;     // increment new reference count
        return *this;
    }

    /**
    *   Overloads '=' operator to support pointer reassignment.
    *
    *   @param Address of an object of type 'T'.
    */
    SmartPointer & operator=(T* rhs) {
        if (ptr != NULL && ptr != rhs) {
            referenceMap[ptr]--; // if rhs is a new address, decrement the current reference count
        }
        ptr = rhs;              // reassign ptr
        referenceMap[ptr]++;    // increment new reference count
        return *this;
    }

    /**
    *   Overloads '*' operator to allow dereferencing of the SmartPointer.
    *
    *   @return Reference to the dereferenced data of type 'T'.
    */
    T & operator*() const {
        return *ptr;
    }

    /**
    *   Overloads '->' operator to allow dereferencing of data members and methods of an object
    *   being pointed to by a SmartPointer.
    *
    *   @return Reference to pointer to the data of type 'T'.
    */
    T* & operator->() {
        return ptr;
    }
}; // end of class SmartPointer

// instantiate static class member outside of class
template <typename T>
std::map<T*, unsigned> SmartPointer<T>::referenceMap;

#endif // SMART_PTR_H
