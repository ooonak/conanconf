cmake_minimum_required(VERSION 3.30.3)
project(PackageTest CXX)

find_package({{name}} CONFIG REQUIRED)

{% if requires is defined -%}
{% for require in requires -%}
find_package({{as_name(require)}} CONFIG REQUIRED)
{% endfor %}
{%- endif %}

add_executable(example example.cpp)
target_link_libraries(example {{name}}::{{name}})
