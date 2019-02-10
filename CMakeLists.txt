###############################################################################
#                                CMAKE VERSION                                #
###############################################################################
CMAKE_MINIMUM_REQUIRED (VERSION 3.9.2)




###############################################################################
#                                   PROJECT                                   #
###############################################################################
PROJECT (buildmode 
		VERSION 1.0.0 
		LANGUAGES CXX 
		DESCRIPTION "A C++17 library to easily handle code paths for different build modes like Debug and Release.")




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

	SET (CMAKE_BUILD_TYPE "")

	ADD_EXECUTABLE (isDebug "${CMAKE_CURRENT_SOURCE_DIR}/tests/debug_mode.cpp")
	ADD_EXECUTABLE (isRelease "${CMAKE_CURRENT_SOURCE_DIR}/tests/release_mode.cpp")

	TARGET_LINK_LIBRARIES (isDebug buildmode)
	TARGET_LINK_LIBRARIES (isRelease buildmode)

	TARGET_COMPILE_OPTIONS (isDebug PRIVATE -g -std=c++17 -Wall -Wextra -Werror -pedantic)
	TARGET_COMPILE_OPTIONS (isRelease PRIVATE -DNDEBUG -O3 -std=c++17 -Wall -Wextra -Werror -pedantic)

	ADD_TEST (constexpr_bool_isDebug isDebug)
	ADD_TEST (constexpr_bool_isRelease isRelease)
ENDIF ()
