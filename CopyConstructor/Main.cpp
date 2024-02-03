#include <iostream>
#include <string>

// Basic raw class
class String {

private:
	char* m_Buffer;
	size_t m_Size;

public:

	// Default copy constructors and what they might look like							//
	// =================================================================================//
	// String(const String& other) : m_Buffer(other.m_Buffer), m_Size(other.m_Size) {}; //
	// =================================================================================//
	// An alternate way this could be written											//
	// String(const String& other) { memcpy(this, &other, sizeof(String)); };			// 
	// =================================================================================//
	// What if we want to disable the ability to do a deep copy?						//
	// String(const String& other) = delete;											//
	//==================================================================================//


	String(const char * string) {
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1]; // requires 1 more for null termination
		// NOTE: We could also use strcpy() c function which automatically does that
				// dest   src	 size
		memcpy(m_Buffer, string, m_Size); 
		m_Buffer[m_Size] = 0; // Manually add our /0 if for whatever reason the original string didn't have
	}

	// Deep copy constructor - comment this out to observe the default shallow copy behavior
	String(const String& other) : m_Size(other.m_Size) {
		std::cout << "copied string" << std::endl;
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, other.m_Size + 1); // At this point we know that the other string will have the /0
	}

	// If we call new, we need to call delete, constructor is a pretty good place
	~String() {
		delete[] m_Buffer; // Since we used [] when we called new, we have to use it with delete as well
	}

	// Overload the [] operator
	char& operator[](unsigned int index) {
		return m_Buffer[index];
	}

	// Making this function a friend means we can access the members of this class directly
	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

// overload the << operator
std::ostream& operator<<(std::ostream& stream, const String& string) {
	stream << string.m_Buffer; // push the string into the stream
	return stream; // and send back the stream
}

// This will end up using the deep copy constructor
// void PrintString(String string) {
//  	std::cout << string << std::endl;
// }


// what we want to do is pass that by reference, and since we will not be
// modifiying the data, we should mark it as const
void PrintString(const String &string) {
	std::cout << string << std::endl;
}

// Basic example struct
struct Vector2{
	float x, y;
};

int main() {

	// This will either crash or work depending on whether the copy constructor code is commented out
	String string = "Cherno";
	String second = string; // This automatically does a SHALLOW copy
	second[2] = 'a'; // See above for an overload on the [] operator
	
	// Printing out like this doesn't take any additional copies
	std::cout << string << std::endl;
	std::cout << second << std::endl; // GOTO END for notes

	// Passing the item into a function will do yet another deep copy
	PrintString(string);
	PrintString(second);

	// Variables on the stack get a deep copy
	//===========================================
	int a = 2; 
	int b = a; // makes a copy, so these are independant
	b = 3; // this will not change the value of a

	// Works the same with classes\structs
	Vector2 v = { 2,3 };
	Vector2 v2 = v;
	v.x = 4;

	// Heap allocation doesn't work the same
	Vector2 * heap = new Vector2(); // uses the default constructor
	Vector2 * heap2 = heap; // This doesn't copy the vector, it copies the pointer
	heap2->x = 2; // This will affect both heap and heap2, they point to the same address

}
// END
// Once we get to the end of this scope, the first string's destructor has already been called
// So we get the crash because the second string's destructor is trying to free memory that 
// doesn't belong to it.