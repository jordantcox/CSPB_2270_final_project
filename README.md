# CSCI 2270 – Data Structures - Final Project - Jordan Cox
## Data Sructure Implemented
Binary Heap

## Overview and Data Structure Explanation
A Binary Heap (BH) can be through of as a combination between a priority queue and a binary tree.
In this implementatio of a BH, we are using artificial flight data. 

This flight data includes an airport, flight, arrival time, departure time, and energy used. 
In this hypothetical scenario, the airplanes are electrified such that during their residence 
time on ground they must charge similar to an electric car.

The BH will be used to predict the number of aiport chargers needed at a site by prioritizing 
the airplanes by arrival time, departure time, and if there are an insufficient number 
of chargers the code will add chargers and re-run the model to make sure all planes can depart 
on time.

Initially the plan for this project was bigger but to focus on the data structure
it was downscaled to emphasize the BH data structure.

## Objectives
* Create an airport class.
* Fill airport class with flight information, four algorithms are needed for this
  * Insert
  * Swap
  * Extract
  * Peek
* Estimate the number of chargers needed at the airport

## Algorithm Routine
* Step 1. Import a number of flights to the airport and into the binary heap
* Step 2. Estimate a number of EV chargers needed
* Step 3. Extract the highest priority airplane from the heap and reorder heap
* Step 4. Estimate the charge completion time of the aircraft
* Step 5. While airplane is charging number of chargers is reduced by 1
* Step 6. If any airplane is forced to delay departure due to charging, increase
  * airport chargers by 1 and return to step 1.


## Compilation Instructions



