#include <iostream>
#include "{{name}}/{{name}}.hpp"
{% if requires is defined -%}
{% for require in requires -%}
#include "{{ as_name(require) }}/{{ as_name(require) }}.h"
{% endfor %}
{%- endif %}

void {{package_name}}(){
    #ifdef NDEBUG
    std::cout << "{{name}}/{{version}}: Hello World Release!\n";
    #else
    std::cout << "{{name}}/{{version}}: Hello World Debug!\n";
    #endif

    // ARCHITECTURES
    #ifdef _M_X64
    std::cout << "  {{name}}/{{version}}: _M_X64 defined\n";
    #endif

    #ifdef _M_IX86
    std::cout << "  {{name}}/{{version}}: _M_IX86 defined\n";
    #endif

    #ifdef _M_ARM64
    std::cout << "  {{name}}/{{version}}: _M_ARM64 defined\n";
    #endif

    #if __i386__
    std::cout << "  {{name}}/{{version}}: __i386__ defined\n";
    #endif

    #if __x86_64__
    std::cout << "  {{name}}/{{version}}: __x86_64__ defined\n";
    #endif

    #if __aarch64__
    std::cout << "  {{name}}/{{version}}: __aarch64__ defined\n";
    #endif

    // Libstdc++
    #if defined _GLIBCXX_USE_CXX11_ABI
    std::cout << "  {{name}}/{{version}}: _GLIBCXX_USE_CXX11_ABI "<< _GLIBCXX_USE_CXX11_ABI << "\n";
    #endif

    // MSVC runtime
    #if defined(_DEBUG)
        #if defined(_MT) && defined(_DLL)
        std::cout << "  {{name}}/{{version}}: MSVC runtime: MultiThreadedDebugDLL\n";
        #elif defined(_MT)
        std::cout << "  {{name}}/{{version}}: MSVC runtime: MultiThreadedDebug\n";
        #endif
    #else
        #if defined(_MT) && defined(_DLL)
        std::cout << "  {{name}}/{{version}}: MSVC runtime: MultiThreadedDLL\n";
        #elif defined(_MT)
        std::cout << "  {{name}}/{{version}}: MSVC runtime: MultiThreaded\n";
        #endif
    #endif

    // COMPILER VERSIONS
    #if _MSC_VER
    std::cout << "  {{name}}/{{version}}: _MSC_VER" << _MSC_VER<< "\n";
    #endif

    #if _MSVC_LANG
    std::cout << "  {{name}}/{{version}}: _MSVC_LANG" << _MSVC_LANG<< "\n";
    #endif

    #if __cplusplus
    std::cout << "  {{name}}/{{version}}: __cplusplus" << __cplusplus<< "\n";
    #endif

    #if __INTEL_COMPILER
    std::cout << "  {{name}}/{{version}}: __INTEL_COMPILER" << __INTEL_COMPILER<< "\n";
    #endif

    #if __GNUC__
    std::cout << "  {{name}}/{{version}}: __GNUC__" << __GNUC__<< "\n";
    #endif

    #if __GNUC_MINOR__
    std::cout << "  {{name}}/{{version}}: __GNUC_MINOR__" << __GNUC_MINOR__<< "\n";
    #endif

    #if __clang_major__
    std::cout << "  {{name}}/{{version}}: __clang_major__" << __clang_major__<< "\n";
    #endif

    #if __clang_minor__
    std::cout << "  {{name}}/{{version}}: __clang_minor__" << __clang_minor__<< "\n";
    #endif

    #if __apple_build_version__
    std::cout << "  {{name}}/{{version}}: __apple_build_version__" << __apple_build_version__<< "\n";
    #endif

    // SUBSYSTEMS

    #if __MSYS__
    std::cout << "  {{name}}/{{version}}: __MSYS__" << __MSYS__<< "\n";
    #endif

    #if __MINGW32__
    std::cout << "  {{name}}/{{version}}: __MINGW32__" << __MINGW32__<< "\n";
    #endif

    #if __MINGW64__
    std::cout << "  {{name}}/{{version}}: __MINGW64__" << __MINGW64__<< "\n";
    #endif

    #if __CYGWIN__
    std::cout << "  {{name}}/{{version}}: __CYGWIN__" << __CYGWIN__<< "\n";
    #endif
}

void {{package_name}}_print_vector(const std::vector<std::string> &strings) {
    for (const auto& str : strings) {
        std::cout << "{{package_name}}/{{version}} " << str << '\n';
    }
}
