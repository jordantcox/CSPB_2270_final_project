# CSCI 2270 – Data Structures - Final Project - Jordan Cox
## Data Sructure Implemented
Binary Heap

## Short Explanation of Data Structure
A Binary Heap (BH) can be through of as a combination between a priority queue and a binary tree. The BH has the dual advantages of a priority queue (O(1) to extract data) and a binary tree (O(log2) depth reducing search time when necessary)

A proper BH should have the following capabilities
* Insert: Insert a new node as a leaf of the BH and 'percolate up' the leaf until it is in the proper location.
* Peek: Show the top priority node wihtout modifying the tree
* Printing: Output the BH contents to the screen
* Extracting: Pulling the top node from the tree and fixing the tree so it's queue and tree properties are maintaned. 

In this program, the BH is implemented as an array. The major difference between the BH and the priority queue previously implemented is in the extraction method. For an extract a BH replaces the top node with the bottom-most leaf and then percolates the leaf down until the tree properties are restored.

## Compliation Instructions 
To build this project clone the project into a repository, then navigate to the build folder. Type the following commands:
* 'cmake ..'
* 'make'
* './run_app'

This was similar to how our homeworks were compiled. 

## Project Overview and Motivation
The motivation for this project was to model airport charging infrastructure in the case of electrified flight. The airplanes are placed into the priority queue based on their departure time. 

Any time more than one plane is on the ground, it is assumed that there should be enough chargers to charge all planes. Thus the algorithm extracts flights and increments chargers for each overlapping flight

