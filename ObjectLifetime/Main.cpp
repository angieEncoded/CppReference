#include <iostream>
#include <string>

// Scopes are generally noted by {}
// classes, for loops, while loops, empty {}, those are all scopes

class Entity {
public:
	Entity() { std::cout << "Created entity" << std::endl; }
	~Entity() { std::cout << "Destroyed Entity" << std::endl; }
};

// Class that is a wrapper for a pointer
// On construction, allocates heap
// on destruction, deletes the pointer
class ScopedPtr {
private:
	Entity* m_Ptr;

public:
	ScopedPtr(Entity* ptr) :m_Ptr(ptr) {} // construct it
	~ScopedPtr() { delete m_Ptr; } // delete upon destruction
};

// This is completely wrong
int* CreateArray() {
	int array[50]; // This gets created on the stack
	return array; // We return a pointer to the stack memory...
}// That stack memory is cleared the second we leave this scope

int main() {
	{
		ScopedPtr e = new Entity(); // this will actually get destroyed once we are out of scope
		// e gets created on the stack
		// when e goes out of scope, the destructor is called, and deletes the pointer

		Entity e1;// create an entity on the stack w/ default constructor
	} // our Entity e will not survive past this bracket

	{
		Entity* ePtr = new Entity(); // created on the heap
	} // will 'survive' the brackets
	// but then we lose the pointer, we cannot access the variable out here
}