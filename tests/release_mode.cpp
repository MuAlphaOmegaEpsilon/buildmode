#include <stdlib.h>
#include <buildmode.hpp>

int main ()
{
	if constexpr (BuildMode::isRelease && !BuildMode::isDebug)
		return EXIT_SUCCESS;
	return EXIT_FAILURE;
}