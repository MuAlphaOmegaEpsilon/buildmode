# BuildMode
A C++17 library to easily handle code paths for different build modes like Debug and Release.

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
