#include <iostream>
#include "../BuildMode.hpp"

int main ()
{
	if constexpr (BuildMode::current == BuildMode::Mode::Release)
		std::cout << "Release mode enabled.\n";
	else
		std::cout << "Debug mode enabled.\n";
		
	return 0;
}