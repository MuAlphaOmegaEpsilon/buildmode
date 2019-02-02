###############################################################################
#                                CMAKE VERSION                                #
###############################################################################
CMAKE_MINIMUM_REQUIRED (VERSION 3.9.5)




###############################################################################
#                                   PROJECT                                   #
###############################################################################
PROJECT (BuildMode VERSION 1.0.0 LANGUAGES CXX 
		DESCRIPTION "A C++17 library to easily handle code paths for 
					different build modes like Debug and Release."
		HOMEPAGE_URL "https://github.com/MuAlphaOmegaEpsilon/BuildMode")




###############################################################################
#                                  LIBRARY                                    #
###############################################################################
ADD_LIBRARY (BuildMode INTERFACE)




###############################################################################
#                                  HEADERS                                    #
###############################################################################
TARGET_INCLUDE_DIRECTORIES	(BuildMode INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})




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
		ADD_EXECUTABLE (DebugMode "${CMAKE_CURRENT_SOURCE_DIR}/tests/debug_mode.cpp")
		TARGET_LINK_LIBRARIES (DebugMode BuildMode)
		ADD_TEST (DebugMode DebugMode)
		SET_TARGET_PROPERTIES 	(DebugMode PROPERTIES
								CXX_STANDARD 17
								CMAKE_CXX_STANDARD_REQUIRED ON
								CXX_EXTENSIONS OFF)

	ELSEIF (CMAKE_BUILD_TYPE STREQUAL Release)
		ADD_EXECUTABLE (ReleaseMode "${CMAKE_CURRENT_SOURCE_DIR}/tests/release_mode.cpp")
		TARGET_LINK_LIBRARIES (ReleaseMode BuildMode)
		ADD_TEST (ReleaseMode ReleaseMode)	
		SET_TARGET_PROPERTIES 	(ReleaseMode PROPERTIES
								CXX_STANDARD 17
								CMAKE_CXX_STANDARD_REQUIRED ON
								CXX_EXTENSIONS OFF)
		ENDIF ()
ENDIF ()
