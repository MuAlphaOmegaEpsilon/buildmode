#include <stdlib.h>
#include <buildmode.hpp>

int main ()
{
	using namespace BuildMode;

	if constexpr (isDebug && !isRelease && current == Debug && current != Release)
		return EXIT_SUCCESS;

	return EXIT_FAILURE;
}