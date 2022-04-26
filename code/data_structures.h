#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

// The flight object keeps track of all flight-related data.
struct flight {
    string name;
    float arrival_time;
    // The priority in the BH will be assigned based on departure time
    float departure_time;
    // It was originally planned to estimate the charger rate but was 
    // unneccessary for completion of the algorithm.
    float energy_needed;
};

// The Binary Heap is implemented through an array where the parents of a node
// are given by the equation (i-1)/2
// The BH is initialized to handle up to 50 flights
// The n_flights keeps track of the number of flights stored in the BH 
struct bh {
    flight arr[50];
    int n_flights;
};

// All subroutines and data are part of the airport class which could 
// be run for any number of airports.
class airport {
public: 
    // Constructor to set all values to zero and initialize airport
    airport();

    // Deconstructor, won't be necessary as using shared_ptr but included
    // for good coding practices.
    ~airport();

    // This subroutine initializes the BH in preparation for data entry.
    // it returns a pointer to the root of the BH
    shared_ptr<bh> InitBinaryHeap();

    // This subroutine inserts a flight into the BH
    void Insert(shared_ptr<bh> heap, string flight_name, float arrival_time, float departure_time, float energy_needed);

    // This subroutine extracts the highest priority node and then replaces it 
    // with the lowest priority node, then percolates down all necessary nodes 
    // to maintain the BH structure
    flight Extract(shared_ptr<bh> heap);

    // This subroutine returns the highest priority node without removing it
    flight Peek(shared_ptr<bh> heap);

    // This subroutine prints the array to make sure it is ordered as expected
    void Print_BH(shared_ptr<bh> heap);

    // This subroutine is performed after all flights are added, 
    // and returns the number of chargers needed at the airport.
    int Calculate_Chargers(shared_ptr<bh> heap);


private: 
    // This private member stores the pointer to the top of the BH
    shared_ptr<bh> heap_;
};
