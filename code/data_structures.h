#include <string>
#include <vector>
#include <iostream>

using namespace std;


struct flight {
    string name;
    float arrival_time;
    float departure_time;
    float energy_needed;
};

struct bh {
    flight arr[50];
    int n_flights;
};

class airport {
public: 
    // Constructor to set all values to zero and initialize airport
    airport();

    // Deconstructor, won't be necessary as using shared_ptr but included
    // for good coding practices.
    ~airport();

    // This subroutine initializes the binary heap in preparation for data entry.
    shared_ptr<bh> InitBinaryHeap();

    // This subroutine inserts a flight into the binary tree
    void Insert(shared_ptr<bh> heap, string flight_name, float arrival_time, float departure_time, float energy_needed);

    // This subroutine swaps two nodes wihtin the binary heap to maintain heap order
    void Swap();

    // This subroutine extracts the highest priority node and then replaces it 
    // with the lowest priority node, then swaps all necessary nodes to maintain
    // the binary tree structure
    string Extract();

    // This subroutine returns the highest priority node without removing it
    string Peek();

    // This subroutine prints the array to make sure it is ordered as expected
    void Print_BH(shared_ptr<bh> heap);

    // This subroutine is performed after all flights are added, 
    // and returns the number of chargers needed at the airport.
    int Calculate_Chargers();


private: 
    // This private member stores the pointer to the top of the BH
    shared_ptr<bh> heap_;
};
