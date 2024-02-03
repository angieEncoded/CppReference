#include <iostream>
#include <string>

// Bonus use of the arrow operator
struct Vector3 {
	// 0byteloc, 4byte loc, 8byte loc	
	float x, y, z;
};

class Entity {
public: 
	int x;

public:
	void Print() const { std::cout << "Hello" << std::endl; }
};

class ScopedPtr {
private:
	Entity* m_Obj;
public:
	// Constructor
	ScopedPtr(Entity* entity) : m_Obj(entity){}

	// Destructor
	~ScopedPtr() { delete m_Obj; }

	// Overload the arrow operator
	Entity* operator->() { return m_Obj; }

	// We can provide a const version
	const Entity *operator->() const { return m_Obj; }

};

int main() {

	// How do we access the variables locations - useful for parsing raw data
	&((Vector3*)0)->x; // this gets the offset as x
	(int)&((Vector3*)nullptr)->x; // nullptr will do the same thing
	int offsetx = (int)&((Vector3*)nullptr)->x; // now we can check the offset
	int offsety = (int)&((Vector3*)nullptr)->y; // now we can check the offset
	int offsetz = (int)&((Vector3*)nullptr)->z; // now we can check the offset
	std::cout << "Offset of x is " << offsetx << std::endl;
	std::cout << "Offset of y is " << offsety << std::endl;
	std::cout << "Offset of z is " << offsetz << std::endl;

	// Now we can create objects that will automatically be cleaned up when they go out of scope
	ScopedPtr entity = new Entity();
	entity->Print(); // now that we have overloaded the operator, this code will work

	// Using the const version - note that the function we use also has to be marked as const
	const ScopedPtr constEntity = new Entity();
	constEntity->Print();

	Entity e;
	e.Print(); // Dot operator works fine for stack allocated variables

	Entity* ptrEntity = &e;// create a pointer on the heap...
	// ptr.Print(); // But when we are on the heap, we need to dereference first
	(*ptrEntity).Print(); // This works, dereference first inside parens because of precedence
	ptrEntity->Print(); // Or use the -> which does it for us
	ptrEntity->x = 2; // works with variables as well

}