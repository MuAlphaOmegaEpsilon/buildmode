/**
 * @brief A C++17 library to easily handle code paths for Debug and Release at compile time. 
 * @file buildmode.hpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com> https://github.com/MuAlphaOmegaEpsilon/buildmode
 * @date 17-02-2019
 */

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