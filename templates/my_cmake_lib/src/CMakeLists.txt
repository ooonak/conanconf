cmake_minimum_required(VERSION 3.25)
project({{name}} CXX)

add_library({{name}}
  {{name}}.cpp)

#target_include_directories({{name}} PUBLIC ../include)
target_include_directories(${PROJECT_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

{% if requires is defined -%}
{% for require in requires -%}
target_link_libraries({{name}} PRIVATE {{as_name(require)}}::{{as_name(require)}})
{% endfor %}
{%- endif %}

# All users of this library will need at least C++20
#target_compile_features(modern_library PUBLIC cxx_std_20)

add_library({{name}}::{{name}} ALIAS {{name}})

#set_target_properties({{name}} PROPERTIES PUBLIC_HEADER "../include")

#install(TARGETS {{name}})

install(TARGETS ${PROJECT_NAME}
        EXPORT ${CMAKE_PROJECT_NAME}Targets
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/{{name}}
        DESTINATION include
        COMPONENT Devel
)
