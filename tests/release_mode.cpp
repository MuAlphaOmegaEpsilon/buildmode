#include <stdlib.h>
#include <buildmode.hpp>

int main ()
{
	using namespace BuildMode;

	if constexpr (isRelease && !isDebug && current == Release && current != Debug)
		return EXIT_SUCCESS;

	return EXIT_FAILURE;
}