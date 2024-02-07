// Like a bit of a macro - lets you do almost anything
// Compiler will write code for you based on a set of rules
#include <iostream>
#include <string>
/*
// A good example is if we have a function that we want to take in different types
void Print(int value) {
	std::cout << value << std::endl;
}

// Now what if we want to print a string too? Then we'd have to do an overload
void Print(std::string value) {
	std::cout << value << std::endl;
}

//And a float? Another overload
void Print(float value) {
	std::cout << value << std::endl;
}
*/

// We can avoid all of that with template programming - use a decorator to make this function a "template"
// template will be evaluated at compile time - the compiler will look at how we are calling this function 
// and with what types, and then it will write the necessary functions with the correct types
template<typename T> // note that this can also be written as <class T> - but this might be confusing
void Print(T value) {
	std::cout << value << std::endl;
}


// Templates are not limited to functions - classes also can be templates and the STL is full of them
template<typename T, int N> // We can pass this in at compile time, which will size our array
class Array {
private: 
	//int m_Array[N];
	T m_Aray[N]; // now we have an array of type T instead of an array of ints
public:
	int GetSize() const { return N; }
};


int main() {
	// Now, the compiler will infer if it can, 
	Print(5);
	Print("Hello");
	Print(4.5f);

	// but we can also be explicit and let the compiler know what we want
	Print<int>(5); // the T will be replaced with the typename we are casting to
	Print<std::string>("World");
	Print<float>(5.6f);

	// Using the template with a class
	Array<int, 5> array;
	Array<std::string, 50> stringArray;
	std::cout << "Array size is: " << array.GetSize() << std::endl;
	std::cout << "Array size is: " << stringArray.GetSize() << std::endl;

}

// Where you might want to use them and not use them
// Lot of game studios just outright damn them - don't use them anywhere
// Useful in a logging system for example
// 