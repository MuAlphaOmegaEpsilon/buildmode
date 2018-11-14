#ifndef BUILDMODE 
#define BUILDMODE
#pragma once

namespace BuildMode
{
	/// An enumeration based on boolean values that provides only two possible scenarios: Debug and Release.
	/// There is no need to have multiple build mode scenarios, since cases like MinSizeRel falls under one
	/// of the specified ones (Release in this particular case).
	enum class Mode : bool
	{
		Release = false,
		Debug = true
	};

	#ifdef NDEBUG 	
	/// Specifies at compile time which kind of build mode has been selected.
	/// The setting is taken from the definition of a particular macro, named NDEBUG.
	/// This constexpr value should be used in conjunction with constexpr-if statements.
	constexpr Mode current = Mode::Release;

	#else
	/// Specifies at compile time which kind of build mode has been selected.
	/// The setting is taken from the definition of a particular macro, named NDEBUG.
	/// This constexpr value should be used in conjunction with constexpr-if statements.
	constexpr Mode current = Mode::Debug;

	#endif
}



#endif