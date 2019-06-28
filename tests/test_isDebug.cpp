#include <buildmode.hpp>

int main ()
{
	if (BuildMode::isDebug && !BuildMode::isRelease)
		return 0;
	return 1;
}
