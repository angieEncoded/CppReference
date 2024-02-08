/*Lambdas!
These are a way to define an 'anonymous' function
Quick disposable function, treated more like a variable rather than a symbol.
Used for:
whenever you have a function pointer, you can use a lambda
Way for us to define a function without defining a function
whereever we would normally use a function pointer, we can set it to a lambda instead
*/

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>


void ForEach(const std::vector<int>& values, const std::function<void(int)>& func) {
	for (int value : values) {
		func(value);
	}
}

int main() {
	std::vector<int> values = { 1,2,3,4,5 };
	ForEach(values, [](int value) { std::cout << "Value: " << value << std::endl;});
	auto iterator = std::find_if(values.begin(), values.end(), [](int value) {return value > 3; }); // loops through the list and returns whatever we are filtering on
	// These are used exactly like the filter\map\etc functions are in javascript
	std::cout << *iterator << std::endl;

	// [] captures - a comma separated list of one or more captures
	// = is everything
	// & is everything by reference
	// and you can specify as well
	auto Lambda = [=](int value) { std::cout << "Value: " << value << std::endl; };	
}






