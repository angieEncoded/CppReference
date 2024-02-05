

// A few strategies we can take

// Linking against Binaries - if you're lucky, you can get precompiled ones
// Grab the binary for your target platform not the platform you are running on


// Static linking - the library gets embedded in your exe
// Dynamic - linked at runtime


// Create a file inside the project folder called Deps
// Create another folder inside that called whatever the library is
// Copy the include (which has all the .h files) and the lib folder for your toolchain in there


// Right click on the project, select properties, then C\C++ -> Include directories
// Set a relative path with $(SolutionDir) - check the macros for all the possibilities

// Now we need to make sure that we link against the library
//Project -> Properties -> Linker -> General -> Additional Library Dependencies - > Library path
// And then we tell VS about the specific file we're linking against
//Project -> Properties -> Linker -> Input -> Additional Dependencies - > Library file (glfw3.lib)




#include <iostream>
#include "GLFW/glfw3.h" // now we can include these files, just like we would in node
// If it's inside the solution, no matter what project its in, use quotes
// The quotes will look for relative paths first and then will look through the compiler include paths


//extern "C" int glfwInit(); // This is how to forward declare if we are linking against a library built in C

int main() {

	int a = glfwInit();
	std::cout << a << std::endl; // will return 1 if it initialized correctly


}





