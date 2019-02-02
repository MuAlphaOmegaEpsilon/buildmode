#ifndef BUILDMODE 
#define BUILDMODE
#pragma once

namespace BuildMode
{
	/// An enumeration based on boolean values that provides only two possible scenarios: Debug and Release.
	/// There is no need to have multiple build mode scenarios, since cases like MinSizeRel falls under one
	/// of the two specified below.
	enum
	{
		Release = false,
		Debug = true
	};

	/// Specifies at compile time which kind of build mode has been selected.
	/// The setting is taken from the definition of a particular macro, named NDEBUG.
	/// This constexpr value should be used in conjunction with constexpr-if statements.
	constexpr auto current = 
							#ifdef NDEBUG
							Release; 
							#else 
							Debug;
							#endif

	/// Specifies at compile time if the build mode selected is considered "Release".
	constexpr bool isRelease = (current == Release);
	/// Specifies at compile time if the build mode selected is considered "Debug".
	constexpr bool isDebug = (current == Debug);
}

#endif