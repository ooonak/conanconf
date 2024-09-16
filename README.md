# conanconf
Custom Conan configuration

## Install templates
```
$ conan config install https://github.com/ooonak/conanconf.git -t git --args="-b main" -sf=profiles -tf=profiles
$ conan config install https://github.com/ooonak/conanconf.git -t git --args="-b main" -sf=templates -tf=templates/command/new
```

## Usage
### Create a new 'hello' library from template.
```
$ conan new my_cmake_lib -d name=hello -d version=0.0.1 -d requires=spdlog/1.14.1

# Add/Update git submodule
$ git submodule add https://github.com/ooonak/cmake-files.git
$ git submodule update --init --recursive
```

Comes with batteries included out of the box.

```
$ conan build . -pr clang-release --build=missing
$ cd build/Release
$ ctest
...

$ ./build/Release/example/helloExample
...

$ conan create . -pr clang-release --build=missing
======== Testing the package: Executing test ========
...

$ conan install . -pr clang-release --build=missing
```

Dev flow.
```
$ conan install . --build=missing -pr=clang-debug
$ cmake --preset conan-debug
$ cmake --build build/Debug
$ ctest --preset conan-debug
$ ./build/Debug/example/helloExample
```

CI flow with static analysis, strict compiler warnings, clang-tidy and CppCheck.
```
$ conan create . -pr clang-release --build=missing -o STATIC_ANALYSIS=True -o STRICT_WARNINGS=True
```

## TODO
 - It seems there is a compiler flag not compatible with GCC.
