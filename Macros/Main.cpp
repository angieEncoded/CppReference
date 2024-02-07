/*
* What is a macro?
* Using the preprocessor 
* Macros will replce text in our code with something else
*/
#include <iostream>
#include <string>

#define WAIT std::cin.get(); // you CAN do this, but you shouldn't - what if this is defined in another file, you wont see this
// so it won't be immediately obvious what it does

#define OPEN_CURLY {
// more useful way of using this
#define LOG(x) std::cout << x << std::endl;

// we can use these to strip stuff from release builds
// Right click -> Properties -> C\C++ -> Preprocessor Directives and add our identifier to the FRONT of the list
// Note that adding it to the END of the list didn't work
#ifdef AS_DEBUG
#define DETAILLOG(x) std::cout << x << std::endl;
#else
#define DETAILLOG(x)
#endif

// This can be used to quickly cancel out an entire block of code
#if 0
// Nothing in here will work
#endif

// Note there are things wrong with the preceding code
// A better way to define this would be 
#if AS_DEBUG == 1
// Then do something in here
#endif
// and we can change to == 0 if we want to turn it off instead of commenting out the whole line
// NOTE that we would have to #define it above, or set it inside the preprocessor directive
// And if we put it in the preprocessor directive, we can't have spaces it must be AS_DEBUG=1
#define DEVELOPMENT 1
#if DEVELOPMENT == 1
// Do something
#elif defined (BABLET)
// do something else 
#endif

// Multiline macros - interstingly, OPEN_CURLY didn't work in place of the {
#define MAIN int main()\
{\
LOG("Hello world");\
WAIT\
}


MAIN


#if 0

int main() OPEN_CURLY // looks ridiculous, but this will indeed work

// Now instead of typing the whole std::cout << "Hello World" << std::endl; we can do
LOG("Hello world");


	//std::cin.get(); // waits for some kind of enter keypress, not really needed in vs2022
	WAIT // this symbol will be replaced
}

#endif