# BuildMode [![Travis CI](https://travis-ci.com/MuAlphaOmegaEpsilon/buildmode.svg?branch=master)](https://travis-ci.com/MuAlphaOmegaEpsilon/buildmode/) [![codecov](https://codecov.io/gh/MuAlphaOmegaEpsilon/buildmode/branch/master/graph/badge.svg)](https://codecov.io/gh/MuAlphaOmegaEpsilon/buildmode) ![MIT](https://img.shields.io/badge/license-MIT-blue.svg) [![GitHub](https://img.shields.io/badge/repo-github-green.svg)](https://github.com/MuAlphaOmegaEpsilon/buildmode)

A C++17 library to easily handle code paths for Debug and Release at compile time.

## How to use
By checking if the current build mode is **Release**:
```cpp
if constexpr (BuildMode::isRelease)
{
	...
}
```

By checking if the current build mode is **Debug**:
```cpp
if constexpr (BuildMode::isDebug)
{
	...
}
```

## License
This library is available to anybody free of charge, under the terms of MIT License (see LICENSE.md).
