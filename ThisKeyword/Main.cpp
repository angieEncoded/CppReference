#include <iostream>
#include <string>
#include <memory>

class Entity {
public:
	Entity() { std::cout << "Created entity" << std::endl; }
	~Entity() { std::cout << "Destroyed entity" << std::endl; }

	void Print() { std::cout << "Something" << std::endl; };
};

int main() {


	{
		std::unique_ptr<Entity> entity(new Entity()); // One way to create a unique pointer
		std::unique_ptr<Entity> uniqueEntity = std::make_unique<Entity>(); // how we *should* do it
		// Primary reason is for "Exception Safety" - if something does happen with the constructor
		// you won't end up with a dangling pointer with no reference and a memory leak

		entity->Print();
	}

	// You can't make a copy of these pointers though. The copy constructor and the copy assignment operator
	// are deleted - the authors are trying to save us from doing bad things

}