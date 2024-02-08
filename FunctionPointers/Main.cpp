/*Raw function pointers
These come from C
A way to assign a function to a variable
The way we've been using them - just as a symbol that we can call when we want something to happen
but we can assign them to variables, pass functions into other functions as parameters
*/

#include <iostream>
#include <vector>

void HelloWorld() {
	std::cout << "Hello World" << std::endl;
}

void HelloWorldWithParams(int a) {
	std::cout << "Hello World Value:" << a << std::endl;
}

void PrintValue(int value) {
	std::cout << "Value is: " << value << std::endl;
}

void ShowMultipliedValue(int value) {
	std::cout << "Multiplied " << value << " is: " << value * value << std::endl;
}

void FilterValues(int value) {
	std::cout << "Filtered value " << value << " is: " << ((value % 2) == 0) << std::endl;
}


void ForEach(const std::vector<int>& values, void(*func)(int)) {
	for (int value : values) {
		func(value);
	}
}


int main() {

	// Now for an example on why we might want to use this
	std::vector<int> values = { 1, 2, 3, 4, 5 };
	ForEach(values, ShowMultipliedValue);
	ForEach(values, FilterValues);
	ForEach(values, PrintValue);

	// Just calling a function
	HelloWorld();

	// What if we assign it to a variable?
	auto function = HelloWorld; // With no parens, we get a function "pointer" so its just like doing &HelloWorld - we dont need the &, the compiler will do an implicit conversion

	// And now, we can call it 
	function();
	function();

	// This is the actual type
	void(*SomeName)() = HelloWorld;

	// Instead of that weird code - we can do this
	typedef void(*HelloWorldFunction)();
	HelloWorldFunction newFunction = HelloWorld; 

	// To use the one with parameters
	typedef void(*HelloWorldFunctionWithParams)(int);
	HelloWorldFunctionWithParams newFunctionWithParams = HelloWorldWithParams;
	newFunctionWithParams(5);

	// We can also just use anonymous functions
	ForEach(values, [](int value) { std::cout << "Added " << value << " is: " << value + value << std::endl; });
	// The [] are called a capture method - this is how we get variables in from the outside world

}