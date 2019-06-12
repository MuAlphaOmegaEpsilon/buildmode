# BuildMode 

A C++11 library to easily handle code paths for Debug and Release at compile time.

[![Travis CI](https://travis-ci.com/MuAlphaOmegaEpsilon/buildmode.svg?branch=master)](https://travis-ci.com/MuAlphaOmegaEpsilon/buildmode/) 
[![codecov](https://codecov.io/gh/MuAlphaOmegaEpsilon/buildmode/branch/master/graph/badge.svg)](https://codecov.io/gh/MuAlphaOmegaEpsilon/buildmode) 
[![MIT](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![GitHub](https://img.shields.io/badge/repo-github-green.svg)](https://github.com/MuAlphaOmegaEpsilon/buildmode)
![GitHub repo size in bytes](https://img.shields.io/github/repo-size/MuAlphaOmegaEpsilon/buildmode.svg?colorB=%23ff0000&label=size)

## How to use
```cpp
// C++11 version should be easily handled by basically every serious compiler 
if (BuildMode::isRelease)
{
	// COMPILER SHOULD STRIP WHEN NOT IN RELEASE
	...
}

if (BuildMode::isDebug)
{
	// COMPILER SHOULD STRIP WHEN NOT IN DEBUG
	...
}


// C++17 version guarantees compile-time evaluation
if constexpr (BuildMode::isRelease)
{
	// CODE STRIPPED WHEN NOT IN RELEASE
	...
}

if constexpr (BuildMode::isDebug)
{
	// CODE STRIPPED WHEN NOT IN DEBUG
	...
}
```

## CMake integration
Add these lines to your *CMakeLists.txt*:
```cmake
ADD_SUBDIRECTORY (relative_path_to/buildmode)
TARGET_LINK_LIBRARIES (your_target_name buildmode)
```

## Library testing
If you wish to test the library on your machine, just launch:
```bash
./tests/run.sh
```
Note that this library's *CMakeLists.txt* won't compile testing sources unless `BUILD_TESTING=ON`: use this feature to choose when to spend time building tests and when not.

## License
This library is available to anybody free of charge, under the terms of MIT License (see [LICENSE](./LICENSE)).

## Author
 [<img src="https://avatars0.githubusercontent.com/u/26225010?s=460&v=4" alt="MuAlphaOmegaEpsilon" width=300 style="border-radius:50%;">](https://github.com/MuAlphaOmegaEpsilon)