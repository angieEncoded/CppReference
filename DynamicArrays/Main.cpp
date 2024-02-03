#include <iostream>
#include <string>
#include <vector>

struct Vertex {
	float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex) {
	stream << vertex.x << "," << vertex.y << "," << vertex.z;
	return stream;
}

// And make sure that when you pass this stuff into functions that you do it by REFERENCE
// const reference if you don't plan to do anything with it
void PrintFunction(const std::vector<Vertex>& vertices) {
	// do something
}

int main() {

	// Should we use pointers or stack allocated objects?
	// It's more optimal in many cases to store them as objects since they will be allocated contiguously
	// Pointers, they will allocate wherever they find enough blocks of memory
	// The biggest concern comes when it's time to resize - all that data needs to be copied somewhere else
	// In this case, the pointers are more efficient
	std::vector<Vertex> vertices; // This is it - we pass in the type to the vector

	// Adding to the vector
	vertices.push_back({2,3,4});
	vertices.push_back({4,5,6});

	// We do know the size
	for (int i = 0; i < vertices.size(); i++) {
		std::cout << vertices[i] << std::endl;
	}

	// Can also use range bsed for loops - use the reference so it doesnt deep copy in
	for (Vertex &v : vertices) {
		std::cout << v << std::endl;
	}

	// Clear out the vector
	vertices.clear();

	// Remove a portion of it - must use an iterator to get to the location
	vertices.erase(vertices.begin() + 1); // this will erase the second position
}