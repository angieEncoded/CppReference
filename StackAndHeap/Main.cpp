/*
* Stack vs Heap 
* Stack is about 2mb 
* View memory by going to Debug -> Windows -> Memory -> Memory1
* View assemby by going to Debug -> Windows -> Disassembly




*/


struct Vector3 {
	float x, y, z;
	
	Vector3():x(3.4f), y(4.3f), z(5.6f) {}

};


#include <iostream>
#include <string>


int main() {
	
	// Stuff on the stack
	int value = 5;
	int array[5];
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	array[3] = 4;
	array[4] = 5;
	Vector3 vector;

	// int on the heap
	int* hvalue = new int;
	*hvalue = 5;
	delete hvalue;

	// array on the heap
	int* hArray = new int[5];
	hArray[0] = 1;
	hArray[1] = 2;
	hArray[2] = 3;
	hArray[3] = 4;
	hArray[4] = 5;
	
	delete[] hArray;

	// class on the stack
	Vector3* hVector = new Vector3();


}



