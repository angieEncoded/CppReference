#include <iostream>
#include <string>
#include <vector>



// The long way to do this
// a "singleton" class should only have one instance created
class Singleton {
private:
	static Singleton* s_Instance;
public:
	static Singleton& Get() { return *s_Instance; }
	void Hello() {};
};

Singleton* Singleton::s_Instance = nullptr; // declare the single instance of the singleton class
//==============================

// How to do it with the static keyword - we get the same exact behavior
class Singleton2 {
public:
	static Singleton& Get() {
		static Singleton instance; // must have static here else this would be created on the stack and would be destroyed as soon as its out of scope
		return instance;
	}

	void Hello() {};
};


void Function() {

	static int i = 0; // This variable will stick around once its called
	// But this will not allow free reign access to the variable like
	// if you created a global variable
	
	// int i = 0; Without static, the variable doesn't stick around 
	i++;
	std::cout << i << std::endl;
}


int main() {

	Singleton::Get().Hello();
	Singleton2::Get().Hello();


	Function();
	Function();
	Function();
	Function();
	Function();
	Function();
	Function();
}