/* Chrono Library and how to use some timing functions */

#include <chrono>
#include <iostream>
#include <thread>

// Basic struct that will do all the timing
struct Timer {

	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	// intellisense complained about
	Timer() :duration(0.0){
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer() {
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		float ms = duration.count() * 1000.0f;
		std::cout << "Timer took: " << ms << " ms" << std::endl;
	}

};

void Function() {
	Timer timer; // now the whole function will be timed

	for (int i = 0; i < 100; i++) {
		std::cout << "Hello" << std::endl;
	}
}


// Optimize the preceding function
void Function2() {
	Timer timer; // now the whole function will be timed

	for (int i = 0; i < 100; i++) {
		std::cout << "Hello\n";
	}
}


int main() {

	using namespace std::literals::chrono_literals; // so we can use the "s" in 1s

	auto startingTime = std::chrono::high_resolution_clock::now(); // get the current time
	std::this_thread::sleep_for(1s); // need chrono_literals for the s in 1s
	auto endingTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = endingTime - startingTime;
	std::cout << duration.count() << std::endl; // now we will see that roughly 1 second has passed
	std::cout << "====================================================================" << std::endl;
	Function();
	std::cout << "====================================================================" << std::endl;
	Function2();

}