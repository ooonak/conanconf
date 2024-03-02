cmake_minimum_required(VERSION 3.25)

project({{name}}App LANGUAGES CXX)

add_executable(${PROJECT_NAME}
    main.cpp
)

{% if requires is defined -%}
{% for require in requires -%}
target_link_libraries(${PROJECT_NAME} PRIVATE {{as_name(require)}}::{{as_name(require)}})
{% endfor %}
{%- endif %}

target_link_libraries(${PROJECT_NAME} PRIVATE {{name}}::{{name}})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
