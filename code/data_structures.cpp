#include "data_structures.h"
#include <iostream>
#include <math.h>

// Constructor
airport::airport(){
    // Initializes the BH and sets the number of flights to zero
    heap_ = shared_ptr<bh>(new bh);
    heap_->n_flights = 0;
}

airport::~airport(){
    // Unneccessary due to the use of smart pointers
}

// Returns a pointer to the root of the BH
shared_ptr<bh> airport::InitBinaryHeap(){
    return heap_;
}

// Inserts a flight object into the BH. Requires the heap pointer, flight name, 
// arrival time, departure time, and energy in kWh that is needed for the flight
void airport::Insert(shared_ptr<bh> heap, string flight_name, float arrival_time, float departure_time, float energy_needed){
    // Inserts the new flight at the end of the BH array
    int i = heap->n_flights;
    heap->arr[i].name = flight_name;
    heap->arr[i].arrival_time = arrival_time;
    heap->arr[i].departure_time = departure_time; 
    heap->arr[i].energy_needed = energy_needed;

    // Percolate upwards
    // If necessary, percolates the added node up based on priority
    // For this implementation all nodes are checked after insertion
    flight temp_flight;
    for (int j = i; j>0; j--){
        // The planes are ranked by departure time
        // Another method would be to rank them by arrival time
        float child_priority = heap->arr[j].departure_time;
        float parent_priority = heap->arr[(j-1)/2].departure_time;

        // If the child priority is less than the parent priority the nodes are swapped
        if (child_priority < parent_priority){
            temp_flight = heap->arr[(j-1)/2];
            heap->arr[(j-1)/2] = heap->arr[j];
            heap->arr[j] = temp_flight;
        }
        else {
            continue;
        }
    }

    // Increments the number of flights up by one
    heap->n_flights = heap->n_flights + 1;
}

// Extract removes the highest priority (lowest departure time) node from the BH
// Then, Extract replaces the root node with the bottom leaf and percolates down 
// the leaf.
flight airport::Extract(shared_ptr<bh> heap){
    // Storing the extracted flight
    flight extracted_flight;
    extracted_flight = heap->arr[0];

    // Setting the root of the array to the bottom leaf value
    heap->arr[0] = heap->arr[heap->n_flights-1];

    // Percolating down while necessary
    // Number of flights is reduced by 1
    heap->n_flights = heap->n_flights-1;
    int i = heap->n_flights;
    for (int j = 0; j<i; j++){
        // A temp_flight, swap_index, parent_flight, and largest_flight are initialized
        // temp_flight: stores a flight temporarily if a swap is needed
        // swap_index: stores the index to swap the flights to and from
        // parent_flight: stores the node to be checked against children and 
        //      potentially percolated down
        // largests_flight: compares the parent and two children and stores the 
        //      largest priority (nearest departure time) for swapping
        //      To start, assume largest flight is parent
        flight temp_flight;
        int swap_index;
        flight parent_flight = heap->arr[j];
        flight largest_flight = parent_flight; 

        // Checking the left child
        if (2*j<i) {
            if (heap->arr[(2*j)].departure_time < largest_flight.departure_time){
                // If the left child has a higher priority, store data
                largest_flight = heap->arr[(2*j)];
                swap_index = 2*j;
            }
        }

        // Checking the right child
        if (2*j+1 <i) {
            if (heap->arr[(2*j+1)].departure_time < largest_flight.departure_time){
                // If the right child has a higher priority, store data
                largest_flight = heap->arr[(2*j+1)];
                swap_index = 2*j+1;
            }
        }

        // Perform the swap with the child if largest flight != parent flight
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

// Peek returns the root node without extracting it
flight airport::Peek(shared_ptr<bh> heap){
    return heap->arr[0];
}

// Print_BH prints the BH in levels to check if the BH is in the right order
void airport::Print_BH(shared_ptr<bh> heap){
    // Levels will be log2 of the number of nodes
    int levels = ceil(log2(heap->n_flights))-1;
    // nodes stores the number of nodes per level
    int nodes = 0;
    // starting_node provides the first node on a level to print
    int starting_node = 3;

    // For each level print all nodes
    for (int j = 0; j<=levels; j++){
        // Level 0 and 1 have abberations in their formula so are just printed
        if (j == 0){
            cout << heap->arr[0].departure_time << endl;
        }
        else if(j == 1){
            cout << heap->arr[1].departure_time << "  " << heap->arr[2].departure_time << endl;
        }
        // Levels > 1 follow a repeating pattern and are printed as such
        else {
            // The number of nodes per level is the level^2
            nodes = pow(levels,2);
            // The starting node starts with the left node and prints all nodes
            for(int i = starting_node; i < starting_node+nodes; i++){
                // In case the i exceeds the number of flights exit the loop
                // This would happen if the BH lowest level is not full
                if (i >= heap->n_flights){
                    break;
                }
                else {
                    cout << heap->arr[i].departure_time << " ";
                }
            }
            cout << endl;
            // Storing the starting node for the next level
            starting_node = starting_node+nodes;
        }
    }
}

// Calculate_Chargers checks how many airports are on the ground at the same time
// For each airplane a maximum number of chargers is estimated and stored
// The largest maximum number is returned as the result
int airport::Calculate_Chargers(shared_ptr<bh> heap){

    // max_chargers stores the largest recorded number and is returned
    int max_chargers = 1;

    // For all flights the algorithm is run
    for (int i = 0; i<heap->n_flights; i++){
        // The local number of chargers is estimated starting at 1
        int j = i;
        int n_chargers= 1;

        // Temporary flight variables are used to traverse the BH
        flight temp_flight;
        flight temp_flight_2;
        flight next_flight;

        // The first flight is extracted
        temp_flight = Extract(heap);
        next_flight = Peek(heap);
        
        // While flights overlap add additional chargers are added
        while (next_flight.arrival_time <= temp_flight.departure_time) {
            j = j+1;
            
            // Breaking in case at the end of the flights
            if (j > heap->n_flights){
                break;
            }

            // Throw away the next flight and look at the following flight
            temp_flight_2 = Extract(heap);
            next_flight = Peek(heap);
            n_chargers = n_chargers+1;   
        }

        // For each pass, if the n_chargers is larger than previously recorded
        // it is increased
        if (n_chargers > max_chargers) {max_chargers = n_chargers;}
        i = j;
    }

    return max_chargers;
}

