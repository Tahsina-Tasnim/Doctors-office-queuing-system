#ifndef SENG1120_LQUEUE_HPP
#define SENG1120_LQUEUE_HPP

#include "lqueue.h"

template <typename T>
LQueue<T>::LQueue() {
    list = new std::list<T>(); // Initialize the list
    count = 0; // Initialize the count
}

template <typename T>
LQueue<T>::~LQueue() {
   delete list; // Free the memory allocated for the list
   count = 0;
   
}

template <typename T>
void LQueue<T>::enqueue(const T& data) {
    list->push_back(data); // Add data to the end of the list
    count++; // Increment the count
}

template <typename T>
T LQueue<T>::dequeue() {
    if (list->empty()) { //checks if empty
        throw empty_collection_exception(); // Throw exception if the list is empty
    }
    T frontElement = list->front(); // Get the front element
    list->pop_front(); // Remove the front element
    count--; // reduces the count
    return frontElement; // Return the front element
}

template <typename T>
T& LQueue<T>::front() {
    if (list->empty()) { //checks if empty
        throw empty_collection_exception(); // Throw exception if the list is empty
    }
    return list->front(); // Return reference to the front element
}

template <typename T>
int LQueue<T>::size() const {
    return count; // Return the count of elements
}

template <typename T>
bool LQueue<T>::empty() const {
    return list->empty(); // Return true if the list is empty
}

#endif 
