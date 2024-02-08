#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

// C didn't have namespaces, so folks would prepend something to the name of the symbol
// So, like GLFWInit() for example - the glfw library is a c library
// Namespaces were added to allow us to identify with namespace::function
// NEVER add a namespace to a header file
// 

// Namespaces can be nested
namespace apple {
	namespace functions {
		void print(const char* text) {
			std::cout << text << std::endl;
		}
	}

}

namespace orange {
	void print(const char* text) {
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << std::endl;
	}
}

// Classes are considered namespaces


int main() {

	// We can create aliases for namespaces
	namespace shortcut = apple::functions;

	orange::print("Print this in reverse");
	apple::functions::print("Print this forwards.");
	
	shortcut::print("Runs the apple thing");

}