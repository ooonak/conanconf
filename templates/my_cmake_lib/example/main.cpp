#include "{{name}}/{{name}}.hpp"
#include <vector>
#include <string>

int main() {
    {{package_name}}();

    std::vector<std::string> vec;
    vec.emplace_back("test_package");

    {{package_name}}_print_vector(vec);
}
