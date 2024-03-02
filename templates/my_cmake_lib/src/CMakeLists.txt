cmake_minimum_required(VERSION 3.25)
project({{name}} CXX)

# Optionally glob
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${ModernCMakeExample_SOURCE_DIR}/include/{{name}}/*.hpp")
#set(HEADER_LIST "${ModernCMakeExample_SOURCE_DIR}/include/{{name}}/{{name}}.hpp")

add_library({{name}}
  {{name}}.cpp)

target_include_directories({{name}} PUBLIC ../include)

{% if requires is defined -%}
{% for require in requires -%}
target_link_libraries({{name}} PRIVATE {{as_name(require)}}::{{as_name(require)}})
{% endfor %}
{%- endif %}

# All users of this library will need at least C++20
#target_compile_features(modern_library PUBLIC cxx_std_20)

# IDEs should put the headers in a nice place
#source_group(
#  TREE "${PROJECT_SOURCE_DIR}/include"
#  PREFIX "Header Files"
#  FILES ${HEADER_LIST})

add_library({{name}}::{{name}} ALIAS {{name}})

set_target_properties({{name}} PROPERTIES PUBLIC_HEADER "include/{{name}}.h")
install(TARGETS {{name}})
