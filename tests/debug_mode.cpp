#include <stdlib.h>
#include <buildmode.hpp>

int main ()
{
	if constexpr (BuildMode::isDebug && !BuildMode::isRelease)
		return EXIT_SUCCESS;
	return EXIT_FAILURE;
}