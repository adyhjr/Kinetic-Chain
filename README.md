# Kinetic-Chain


The primary objective of this program was to simulate the effects of a kinetic chain using object-oriented programming and dynamic memory allocation. The user is prompted to input the number of links in the chain, the length of each link, and the angles of the interconnecting links. These inputs are used in an iterating for loop to append values to the links defined in the SubChain Class. The outputs for this are the starting and ending coordinates of each link contained in a paired vector and as well as the relative and absolute angle for each interconnected link. Since a very important part of this project was to correctly manage memory, I implemented a function within the SubChain class to delete memory and restore to its empty nullptr address. For user input, I implemented a data validation function that did not seem to work correctly, I came to realize that I was not passing by reference so none of the validation was changing direct variables.
