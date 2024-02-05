#include <iostream>
// tuple - a class that can contain x amount og variables and it doesnt care about the types
#include <functional>// uhhh, just go watch chernos vdeo if you evern actually need this...

// else just use a struct
struct stuffToReturn {
	std::string stringStuff;
	int intStuff;
};


static stuffToReturn FunctionToGetSomething() {
	return {"whatever", 1};
}


int main() {
	//static std::tuple<std::string, std::string>;// uhhh, just go watch chernos vdeo if you evern actually need this...
	stuffToReturn mystuff =  FunctionToGetSomething();
	std::cout << mystuff.intStuff << mystuff.stringStuff << std::endl;
}