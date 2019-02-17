# BuildMode [![Travis CI](https://travis-ci.com/MuAlphaOmegaEpsilon/buildmode.svg?branch=master)](https://travis-ci.com/MuAlphaOmegaEpsilon/buildmode/) [![codecov](https://codecov.io/gh/MuAlphaOmegaEpsilon/buildmode/branch/master/graph/badge.svg)](https://codecov.io/gh/MuAlphaOmegaEpsilon/buildmode) ![MIT](https://img.shields.io/badge/license-MIT-blue.svg) [![GitHub](https://img.shields.io/badge/repo-github-green.svg)](https://github.com/MuAlphaOmegaEpsilon/buildmode)

A C++17 library to easily handle code paths for Debug and Release at compile time.

## How to use
```cpp
if constexpr (BuildMode::isRelease)
{
	// CODE PRESENT IN BINARY ONLY IN RELEASE MODE
	...
}

if constexpr (BuildMode::isDebug)
{
	// CODE PRESENT IN BINARY ONLY IN RELEASE MODE
	...
}
```

## Library testing
If you wish to test the library on your machine, just launch:
```bash
./tests/run.sh
```
Note that this library's *CMakeLists.txt* won't compile testing sources unless `BUILD_TESTING=ON`.

## License
This library is available to anybody free of charge, under the terms of MIT License (see LICENSE.md).
