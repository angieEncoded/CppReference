/*Array of Arrays - a collection of arrays*/

#include <iostream>

int main() {

	int* array = new int[50];
	int** a2darray = new int* [50];// pointer to a collection of int pointers
	// essentially allocated 200 bytes of memory - this is just a collection of ints. 
	// these two allocations are basically identical

	// Now we can set those pointers to point to actual arrays
	// thus an array of arrays

	
	// each array 
	for (int i = 0; i < 50; i++) {
		a2darray[i] = new int[50];
	}


}



