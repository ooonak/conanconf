cmake_minimum_required(VERSION 3.30.3)

project(
  {{name}}
  VERSION {{version}}
  DESCRIPTION "Please write a short description"
  LANGUAGES CXX)

option(TESTS "Build tests" ON)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here
  set(CMAKE_POSITION_INDEPENDENT_CODE ON)
  #set(CMAKE_VERBOSE_MAKEFILE ON)
  #set(CMAKE_CXX_STANDARD 20)
  #set(CMAKE_CXX_STANDARD_REQUIRED ON)

  # Let's ensure -std=c++xx instead of -std=g++xx
  set(CMAKE_CXX_EXTENSIONS OFF)

  # Let's nicely support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  include(GNUInstallDirs)
  include(CTest)

  find_package(Doxygen)
  if(Doxygen_FOUND)
    add_subdirectory(docs)
  else()
    message(STATUS "Doxygen not found, not building docs")
  endif()
endif()

# We are using Conan
#include(FetchContent)

{% if requires is defined -%}
{% for require in requires -%}
find_package({{as_name(require)}} CONFIG REQUIRED)
{% endfor %}
{%- endif %}

add_subdirectory(src)
add_subdirectory(example)

message(STATUS "CXX flags: ${CMAKE_CXX_FLAGS}")

# Testing only available if this is the main app
# Emergency override MODERN_CMAKE_BUILD_TESTING provided as well
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING)
  AND TESTS)
  find_package(GTest REQUIRED)
  add_subdirectory(tests)
endif()

