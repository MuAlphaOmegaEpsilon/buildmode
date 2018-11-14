# BuildMode
A C++17 library to easily handle code paths for different build modes like Debug and Release.

## How to use
```cpp
#include <BuildMode.hpp>
#include <iostream>

int main ()
{
	if constexpr (BuildMode::current == BuildMode::Mode::Release)
		std::cout << "Release mode enabled.\n";
	else
		std::cout << "Debug mode enabled.\n";
		
	return 0;
}
```
