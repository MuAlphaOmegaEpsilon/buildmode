###############################################################################
#                                CMAKE VERSION                                #
###############################################################################
CMAKE_MINIMUM_REQUIRED (VERSION 3.9.5)




###############################################################################
#                                   PROJECT                                   #
###############################################################################
PROJECT (BuildMode VERSION 1.0.0 LANGUAGES CXX 
		DESCRIPTION "A C++17 library to easily handle code paths for different build modes like Debug and Release."
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
######################HintingEnabled#########################################################
IF (TEST)
	ENABLE_TESTING ()
	ADD_EXECUTABLE (BaseCase "tests/baseCase.cpp")
	TARGET_LINK_LIBRARIES (BaseCase BuildMode)
	ADD_TEST (BaseCase BaseCase)		
	SET_TARGET_PROPERTIES 	(BaseCase PROPERTIES
            				CXX_STANDARD 17
            				CMAKE_CXX_STANDARD_REQUIRED ON
							CXX_EXTENSIONS OFF)
ENDIF ()
