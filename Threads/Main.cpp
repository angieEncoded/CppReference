#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork() {

	using namespace std::literals::chrono_literals;

	std::cout << "Started thread id = " << std::this_thread::get_id() << std::endl;

	while (!s_Finished) {
		std::cout << "Working..." << std::endl;
		std::this_thread::sleep_for(1s);
	}
}


int main() {

	// This will take in a function pointer - this thread is doing something
	std::thread worker(DoWork); // offloads the DoWork onto its own thread
	// Will run until it exits


	// this 'thread' is waiting for us to do something
	std::cin.get(); //blocks the thread until we hit enter
	s_Finished = true;


	// wait for it to finish its work with this:	
	worker.join();
	std::cout << "Started thread id = " << std::this_thread::get_id() << std::endl;
	std::cout << "Finished with the thing." << std::endl;

	std::cin.get();

}