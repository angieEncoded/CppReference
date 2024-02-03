#include <iostream>
#include <string>
#include <vector>

struct Vertex {
	float x, y, z;

	Vertex(float x, float y, float z) : x(x), y(y), z(z) {};	// basic constructor

	Vertex(const Vertex& vertex) : x(vertex.x), y(vertex.y), z(vertex.z) {
		std::cout << "Copy constructor called" << std::endl;
	}

};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex) {
	stream << vertex.x << "," << vertex.y << "," << vertex.z;
	return stream;
}

int main() {

	std::cout << "No Optimization: six total copies." << std::endl;
	std::cout << "============================================================" << std::endl;

	// These three lines of code results in the vertex being copied six (6!) times!
	std::vector<Vertex> vertices;
	vertices.push_back({ 1,2,3 }); // uses the default constructor if there isnt one
	vertices.push_back({ 4,5,6 });
	vertices.push_back(Vertex(7,8,9)); // use the constructor that we built

	std::cout << "Optimization Strategy 1: Preallocated space " << std::endl;
	std::cout << "============================================================" << std::endl;

	// Optimization strategy 1 - if we know the size ahead of time, we can tell it
	std::vector<Vertex> optimizeSizeVector;
	optimizeSizeVector.reserve(3); // this will tell it how big to initially be
	optimizeSizeVector.push_back(Vertex(1, 2, 3));
	optimizeSizeVector.push_back(Vertex(4, 5, 6));
	optimizeSizeVector.push_back(Vertex(7, 8, 9));


	std::cout << "Optimization Strategy 2: Construct directly into the vector " << std::endl;
	std::cout << "============================================================" << std::endl;
	std::vector<Vertex> optimizePlacementVector;
	optimizePlacementVector.reserve(3); // this will tell it how big to initially be
	optimizePlacementVector.emplace_back((float)1, (float)2, (float)3); // I cast them to a float to get rid of 
	optimizePlacementVector.emplace_back((float)4, (float)5, (float)6); // warning C4244
	optimizePlacementVector.emplace_back((float)7, (float)8, (float)9);
	 
}