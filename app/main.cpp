#include <iostream>
#include "../code/data_structures.h"

using namespace std;

int main(){
    cout << endl << "Starting the airport charger estimation."<< endl;
    int max_charge_rate = 1000; // charge rate in kW per hour
    cout << "The maximum allowable charge rate is: " << max_charge_rate << " kW"<< endl;


    cout << endl;
    cout << "Airport 1"<< endl;
    // Airport 1 has 7 flights that arrive and depart such that 
    // only 1 charger is needed
    airport test_airport_1;
    shared_ptr<bh> heap_1 = test_airport_1.InitBinaryHeap();

    test_airport_1.Insert(heap_1, "AAA_BBB", 10.00, 11.00, 500);  
    test_airport_1.Insert(heap_1, "AAA_CCC", 11.00, 12.00, 500); 
    test_airport_1.Insert(heap_1, "AAA_DDD", 12.00, 13.00, 500); 
    test_airport_1.Insert(heap_1, "AAA_EEE", 9.00, 10.00, 500);
    test_airport_1.Insert(heap_1, "AAA_FFF", 8.00, 9.00, 500);  
    test_airport_1.Insert(heap_1, "AAA_GGG", 17.00, 18.00, 500); 
    test_airport_1.Insert(heap_1, "AAA_HHH", 15.00, 16.00, 500); 

    test_airport_1.Print_BH(heap_1);

    cout << "Extracting a flight" << endl;
    flight temp_flight = test_airport_1.Extract(heap_1);

    test_airport_1.Print_BH(heap_1);

    cout << "Number of flights: " << heap_1->n_flights << endl;
    cout << "Number of chargers: " << test_airport_1.Calculate_Chargers() << endl;

    // Airport 2 has 7 flights  that arrive and depart such that 
    // at least 3 chargers are needed
    cout << endl;
    cout << "Airport 2"<< endl;

    airport test_airport_2;
    shared_ptr<bh> heap_2 = test_airport_2.InitBinaryHeap();

    test_airport_2.Insert(heap_2, "AAA_BBB", 10.00, 11.00, 500);  
    test_airport_2.Insert(heap_2, "AAA_CCC", 10.00, 11.00, 500); 
    test_airport_2.Insert(heap_2, "AAA_DDD", 10.00, 11.00, 500); 
    test_airport_2.Insert(heap_2, "AAA_EEE", 9.00, 10.00, 500);
    test_airport_2.Insert(heap_2, "AAA_FFF", 9.00, 10.00, 500);  
    test_airport_2.Insert(heap_2, "AAA_GGG", 10.00, 11.00, 500); 
    test_airport_2.Insert(heap_2, "AAA_HHH", 10.00, 11.00, 500); 

    test_airport_2.Print_BH(heap_2);

    cout << "Number of flights: " << heap_2->n_flights << endl;
    cout << "Number of chargers: " << test_airport_2.Calculate_Chargers() << endl;


    cout << "Done" << endl;
}