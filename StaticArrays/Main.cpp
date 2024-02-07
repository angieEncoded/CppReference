/*
Arrays that do not grow
*/

#include <array> // right click -> open document to see this source file
#include <iostream>

// Using a template allows us to pass in the size
// https://stackoverflow.com/questions/66467081/can-the-c-array-class-be-passed-as-a-parameter-with-variable-size
template<typename T, size_t N>
void PrintArray(std::array<T, N> &arr) {
	for (auto element : arr) {
		//std::cout << 1 << std::endl;
		std::cout << element << std::endl;
	}

}

// This isn't actually storing the array size
// there is a function that returns the template argument


int main() {
	
	// CPP array class. Had optional bounds checking.
	std::array<int, 10> data;
	int counter = 15;
	// In order to do assignments inside the range loop, we have to make the iterator a reference
	for (auto &item : data) {
		item = counter; // and then we can assign, no idea what it was doing before lol
		counter++;
	}
	//data[0] = 12;

	// standard c style array - we have to maintain the size ourselves
	int oldData[10];
	oldData[0] = 5;

	// So why would we use this instead?
	int arraysize = data.size(); // we can ask it what its size is

	PrintArray(data);

}










