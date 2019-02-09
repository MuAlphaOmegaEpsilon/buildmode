#ifndef BUILDMODE_HPP
#define BUILDMODE_HPP

namespace BuildMode
{
#ifdef NDEBUG
	/// Specifies at compile time if the build mode selected is considered "Release".
	constexpr bool isRelease = true;
	/// Specifies at compile time if the build mode selected is considered "Debug".
	constexpr bool isDebug = false;
#else  
	/// Specifies at compile time if the build mode selected is considered "Release".
	constexpr bool isRelease = false;
	/// Specifies at compile time if the build mode selected is considered "Debug".
	constexpr bool isDebug = true;
#endif
}

#endif