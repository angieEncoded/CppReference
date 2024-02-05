//#include "../../Engine/src/Engine.h" // One solution - relative path to the existing files, but this will break if we move things around
// Better way, use compiler include paths
// Project -> Properties -> C\CPP -> Additional Include paths -> $(SolutionDir)Engine\src
#include "Engine.h" // Now this is all we need to do to tell VS what it has
// And to get VS to link it against the library right clicn on the project -> Add -> Reference -> Select our Engine project
// Now the project is fully linked in, and even if we change the name of the project, it will still compile
// VS is also smart enough to compile both if needed, so there's no weirdness with 'forgetting' to compile the deps

int main() {
	engine::PrintMessage();
}