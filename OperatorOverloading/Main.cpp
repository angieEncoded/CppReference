#include <iostream>
#include <string>

struct Vector2 {
	float x, y;

	Vector2(float x, float y) : x(x), y(y) {} // constructor

	Vector2 Add(const Vector2& other) const {
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 Multiply(const Vector2& other) const {
		return Vector2(x * other.x, y * other.y);
	}

	// We can define and overloaded operator like any other function
	Vector2 operator+(const Vector2& other) const {
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator*(const Vector2& other) const {
		return Vector2(x * other.x, y * other.y);
	}

	bool operator==(const Vector2& other) const {
		return x == other.x && y == other.y;
	}

	bool operator!=(const Vector2& other) const {
		return !(*this == other);
	}
};

// since this overload has nothing to do with the vector struct, we define it outside
std::ostream& operator <<(std::ostream& stream, const Vector2& other) {
	stream << other.x << ", " << other.y;
	return stream;
}

int main() {
	Vector2 position(4.0f, 4.0f);
	Vector2 speed(0.5f, 1.5f);
	Vector2 powerup(1.1f, 1.1f);

	Vector2 result = position.Add(speed.Multiply(powerup)); // Can get hard to read
	Vector2 result2 = position + speed * powerup;			// This is more concise

	std::cout << result2 << std::endl; 	// What about if we want to print that out?

	if (result == result2) std::cout << "true" << std::endl; // Or check equality?
}