# conanconf
Custom Conan configuration

## Install templates
```
$ conan config install https://github.com/ooonak/conanconf.git -t git -sf=templates -tf=templates/command/new
```

## Usage
### Create a new library.
```
$ conan new my_cmake_lib -d name=mylib -d version=0.0.1
```

