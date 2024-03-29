# conanconf
Custom Conan configuration

## Install templates
```
$ conan config install https://github.com/ooonak/conanconf.git -t git -sf=templates -tf=templates/command/new
```

## Usage
### Create a new 'hello' library from template.
```
$ conan new my_cmake_lib -d name=hello -d version=0.0.1 -d requires=spdlog/1.13.0
```

Comes with batteries included out of the box.

```
$ conan build .
$ cd build/Release
$ ctest
Test project /tmp/hello/build/Release
    Start 1: hello.Dummy
1/1 Test #1: hello.Dummy ......................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.00 sec

$ ./apps/helloApp 
hello/0.0.1: Hello World Release!
  hello/0.0.1: __x86_64__ defined
  hello/0.0.1: _GLIBCXX_USE_CXX11_ABI 1
  hello/0.0.1: __cplusplus201703
  hello/0.0.1: __GNUC__13
  hello/0.0.1: __GNUC_MINOR__2
hello/0.0.1 test_package

$ cd ../../
$ conan create .
======== Testing the package: Executing test ========
hello/0.0.1 (test package): Running test()
hello/0.0.1 (test package): RUN: ./example
hello/0.0.1: Hello World Release!
  hello/0.0.1: __x86_64__ defined
  hello/0.0.1: _GLIBCXX_USE_CXX11_ABI 1
  hello/0.0.1: __cplusplus201703
  hello/0.0.1: __GNUC__13
  hello/0.0.1: __GNUC_MINOR__2
hello/0.0.1 test_package

$ conan install .
```

Dev flow.
```
$ conan install . --output-folder=build --build=missing -pr=clang-debug
$ cmake -S . -B build -G Ninja --preset conan-debug
$ cmake --build build
$ cd build
$ ctest
```

