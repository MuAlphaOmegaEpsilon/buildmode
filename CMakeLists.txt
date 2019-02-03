###############################################################################
#                                CMAKE VERSION                                #
###############################################################################
CMAKE_MINIMUM_REQUIRED (VERSION 3.9.2)




###############################################################################
#                                   PROJECT                                   #
###############################################################################
PROJECT (buildmode VERSION 1.0.0 LANGUAGES CXX 
		DESCRIPTION "A C++17 library to easily handle code paths for \
					different build modes like Debug and Release."
		HOMEPAGE_URL "https://github.com/MuAlphaOmegaEpsilon/BuildMode")




###############################################################################
#                                  LIBRARY                                    #
###############################################################################
ADD_LIBRARY (buildmode INTERFACE)




###############################################################################
#                                  HEADERS                                    #
###############################################################################
TARGET_INCLUDE_DIRECTORIES	(buildmode INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})




###############################################################################
#                                  OPTIONS                                    #
###############################################################################
OPTION (TEST "Is library testing enabled?" OFF)




###############################################################################
#                                    TESTS                                    #
###############################################################################
IF (TEST)
	ENABLE_TESTING ()

	IF (CMAKE_BUILD_TYPE STREQUAL Debug)
		ADD_EXECUTABLE (debug_mode "${CMAKE_CURRENT_SOURCE_DIR}/tests/debug_mode.cpp")
		TARGET_LINK_LIBRARIES (debug_mode buildmode)
		ADD_TEST (Debug debug_mode)
		SET_TARGET_PROPERTIES 	(debug_mode PROPERTIES
								CXX_STANDARD 17
								CMAKE_CXX_STANDARD_REQUIRED ON
								CXX_EXTENSIONS OFF
								CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra")

	ELSEIF (CMAKE_BUILD_TYPE STREQUAL Release)
		ADD_EXECUTABLE (release_mode "${CMAKE_CURRENT_SOURCE_DIR}/tests/release_mode.cpp")
		TARGET_LINK_LIBRARIES (release_mode buildmode)
		ADD_TEST (Release release_mode)	
		SET_TARGET_PROPERTIES 	(release_mode PROPERTIES
								CXX_STANDARD 17
								CMAKE_CXX_STANDARD_REQUIRED ON
								CXX_EXTENSIONS OFF
								CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra")
		ENDIF ()
ENDIF ()
