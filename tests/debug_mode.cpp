#include <stdlib.h>
#include <buildmode.hpp>

int main ()
{
	if (BuildMode::isDebug && !BuildMode::isRelease)
		return EXIT_SUCCESS;
	return EXIT_FAILURE;
}