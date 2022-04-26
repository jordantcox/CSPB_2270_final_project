#include "data_structures.h"
#include <iostream>


airport::airport(){
    // Implement Initialization
    heap_ = shared_ptr<bh>(new bh);
    heap_->n_flights = 0;
}

airport::~airport(){
    // Nothing to be done here
}

shared_ptr<bh> airport::InitBinaryHeap(){
    return heap_;
}

void airport::Insert(shared_ptr<bh> heap, string flight_name, float arrival_time, float departure_time, float energy_needed){
    int i = heap->n_flights;

    heap->arr[i].name = flight_name;
    heap->arr[i].arrival_time = arrival_time;
    heap->arr[i].departure_time = departure_time; 
    heap->arr[i].energy_needed = energy_needed;

    // percolate upwards

    heap->n_flights = heap->n_flights + 1;
}

void airport::Swap(){
    // Implement Swap operation
}

string airport::Extract(){
    // Implement Extract Operation
    return "c";
}

string airport::Peek(){
    // Implement Peek Operation
    return "c";
}

void airport::Print_BH(shared_ptr<bh> heap){

}

int airport::Calculate_Chargers(){
    // Implement the airport chargers calculation
    return 1;
}

