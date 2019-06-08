#include <stdlib.h>
#include <buildmode.hpp>

int main ()
{
	if (BuildMode::isRelease && !BuildMode::isDebug)
		return EXIT_SUCCESS;
	return EXIT_FAILURE;
}