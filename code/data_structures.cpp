#include "data_structures.h"
#include <iostream>
#include <math.h>

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

    // Percolate Upwards
    flight temp_flight;
    for (int j = i; j>0; j--){
        // The planes are ranked by departure time
        // Another method would be to rank them by arrival time
        float child_priority = heap->arr[j].departure_time;
        float parent_priority = heap->arr[(j-1)/2].departure_time;

        if (child_priority < parent_priority){
            temp_flight = heap->arr[(j-1)/2];

            heap->arr[(j-1)/2] = heap->arr[j];

            heap->arr[j] = temp_flight;
        }
        else {
            continue;
        }
    }

    heap->n_flights = heap->n_flights + 1;
}

flight airport::Extract(shared_ptr<bh> heap){
    // Getting the extracted flight
    flight extracted_flight;
    extracted_flight = heap->arr[0];

    // Setting the head of the array to the tail value.
    heap->arr[0] = heap->arr[heap->n_flights-1];

    // Percolating down while necessary
    // Number of flights is reduced by 1
    heap->n_flights = heap->n_flights-1;

    int i = heap->n_flights;
    for (int j = 0; j<i; j++){
        flight temp_flight;
        int swap_index;
        flight parent_flight = heap->arr[j];
        // Assume the largest priority is the parent priority
        flight largest_flight = parent_flight; 

        if (2*j<i) {
            if (heap->arr[(2*j)].departure_time < largest_flight.departure_time){
                largest_flight = heap->arr[(2*j)];
                swap_index = 2*j;
            }
        }

        if (2*j+1 <i) {
            if (heap->arr[(2*j+1)].departure_time < largest_flight.departure_time){
                largest_flight = heap->arr[(2*j+1)];
                swap_index = 2*j+1;
            }
        }

        if (largest_flight.name != parent_flight.name){
            temp_flight = parent_flight;
            heap->arr[j] = largest_flight;
            heap->arr[swap_index] = temp_flight;
        }
        else{
            break;
        }
    }
    
    // Returning the extracted flight data
    return extracted_flight;
}

string airport::Peek(shared_ptr<bh> heap){
    return heap->arr[0].name;
}

void airport::Print_BH(shared_ptr<bh> heap){
    int levels = ceil(log2(heap->n_flights))-1;
    int nodes = 0;
    int starting_node = 3;

    for (int j = 0; j<=levels; j++){
        if (j == 0){
            cout << heap->arr[0].departure_time << endl;
        }
        else if(j == 1){
            cout << heap->arr[1].departure_time << "  " << heap->arr[2].departure_time << endl;
        }
        else {
            nodes = pow(levels,2);
            for(int i = starting_node; i < starting_node+nodes; i++){
                // In case the i exceeds the number of flights exit the loop
                if (i >= heap->n_flights){
                    break;
                }
                else {
                    cout << heap->arr[i].departure_time << " ";
                }
            }

            cout << endl;
            starting_node = starting_node+nodes;
        }
    }
}

int airport::Calculate_Chargers(){
    // Implement the airport chargers calculation
    return 1;
}

