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
		std::shared_ptr<Entity> e0; // Initial reference
		{

			std::shared_ptr<Entity> entity = std::make_shared<Entity>(); // always call it this way
			// The shared pointer also calls a second block of memory called a control block to keep
			// track of its references

			std::shared_ptr<Entity> entityCopy = entity; // Now we can have additional references
			e0 = entity; // We can even grab from other scopes


			entity->Print();
		}
	}
	// e0 will not die until we reach this point, when both have gone out of scope

}