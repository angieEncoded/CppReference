// Dynamic Linking
/*
Linking that happens at run time
Does not get dumped into your actual code, it stays on its own
When your executable is launched, that's when its linked

*/

#include <iostream>
#include "GLFW/glfw3.h"
// The build settings would be configured exactly as the Static one was, but 


// Now we need to make sure that we link against the library
//Project -> Properties -> Linker -> General -> Additional Library Dependencies - > Library path
// And then we tell VS about the specific file we're linking against
//Project -> Properties -> Linker -> Input -> Additional Dependencies - > Library file (glfwdll.lib)
// BUT - then the dll file itself MUST be in an accessible location on the target pc
// Either in the root folder or somewhere in the system path




int main() {

	int a = glfwInit();
	std::cout << a << std::endl;




}