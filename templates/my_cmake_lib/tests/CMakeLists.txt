cmake_minimum_required(VERSION 3.30.3)

project({{name}}Tests LANGUAGES CXX)

add_executable(${PROJECT_NAME}
  {{name}}Tests.cpp
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
  {{name}}::{{name}}
  gtest::gtest
)

{% if requires is defined -%}
{% for require in requires -%}
target_link_libraries({{name}}Tests PRIVATE {{as_name(require)}}::{{as_name(require)}})
{% endfor %}
{%- endif %}

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

