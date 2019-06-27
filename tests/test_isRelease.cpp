#include <buildmode.hpp>

int main ()
{
	if (BuildMode::isRelease && !BuildMode::isDebug)
		return 0;
	return 1;
}