/*
auto allows CPP to automatically deduce the data type 
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

// if we change this to char *, variables set with auto will work automatically
std::string GetName() {
	return "Cherno";
}

class Device {};

// What if we have this massive huge type?
class DeviceManager {
private: 
	std::unordered_map<std::string, std::vector<Device*>> m_Devices;

public:
	const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const {
		return m_Devices;
	}
};


int main() {
	auto mything = 0;
	auto myotherthing = "hello"; // casts to a const char *

	std::string name = GetName();
	auto autnoname = GetName(); // or we could use auto

	std::vector<std::string> strings;
	strings.push_back("Apple");
	strings.push_back("Orange");

	// Iterator, alternative to range based for loops
	for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++) {
		std::cout << *it << std::endl;
	}

	// We can just use auto here, which makes it easier to read and it works just the same
	for (auto it = strings.begin(); it != strings.end(); it++) {
		std::cout << *it << std::endl;
	}

	// one way to deal with this massive type
	using DeviceMap = std::unordered_map<std::string, std::vector<Device*>>;

	// support older codebases with typedef
	typedef std::unordered_map<std::string, std::vector<Device*>> DeviceMap;

	// but if we don't have this, we can just use auto

	DeviceManager DM;
	const std::unordered_map<std::string, std::vector<Device*>>& devices = DM.GetDevices();
	const auto& devices2 = DM.GetDevices(); // we do still need the reference

}