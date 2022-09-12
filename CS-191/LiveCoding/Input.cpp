#include <iostream>
#include <string>

namespace ints {
	int x;
}
namespace floats {
	float x;
}

int main() {
	std::cout << "Enter an int and then a float: " << std::endl;
	std::cin >> ints::x;
	std::cin >> floats::x;
	std::cout << ints::x << " " << floats::x << std::endl;
	
	return 0;
}
