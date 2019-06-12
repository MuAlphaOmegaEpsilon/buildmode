###############################################################################
#                                CMAKE VERSION                                #
###############################################################################
CMAKE_MINIMUM_REQUIRED (VERSION 3.11.4)




###############################################################################
#                                   PROJECT                                   #
###############################################################################
PROJECT (buildmode 
		VERSION 1.0.0 
		LANGUAGES CXX 
		DESCRIPTION "A C++11 library to easily handle code paths for different build modes like Debug and Release.")




###############################################################################
#                                  LIBRARY                                    #
###############################################################################
ADD_LIBRARY (buildmode INTERFACE)




###############################################################################
#                                  HEADERS                                    #
###############################################################################
TARGET_INCLUDE_DIRECTORIES	(buildmode INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})




###############################################################################
#                                    TESTS                                    #
###############################################################################
IF (BUILD_TESTING)
	ENABLE_TESTING()
	
	ADD_EXECUTABLE (isDebug "${CMAKE_CURRENT_SOURCE_DIR}/tests/debug_mode.cpp")
	ADD_EXECUTABLE (isRelease "${CMAKE_CURRENT_SOURCE_DIR}/tests/release_mode.cpp")

	TARGET_LINK_LIBRARIES (isDebug buildmode ${COVERAGE_FLAG})
	TARGET_LINK_LIBRARIES (isRelease buildmode ${COVERAGE_FLAG})
	
	IF (MSVC)
		TARGET_COMPILE_OPTIONS (isDebug PRIVATE /std:c++11)
		TARGET_COMPILE_OPTIONS (isRelease PRIVATE /std:c++11 /DNDEBUG)
	ELSE ()
		TARGET_COMPILE_OPTIONS (isDebug PRIVATE -std=c++11 -g -Wall -Wextra -Werror -pedantic ${COVERAGE_FLAG})
		TARGET_COMPILE_OPTIONS (isRelease PRIVATE -std=c++11 -DNDEBUG -O3 -Wall -Wextra -Werror -pedantic ${COVERAGE_FLAG})
	ENDIF ()


	ADD_TEST ([BUILDMODE]isDebug isDebug)
	ADD_TEST ([BUILDMODE]isRelease isRelease)
ENDIF ()
