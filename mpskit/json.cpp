#include "json.hpp"
#include <fmt/core.h>
#include <fstream>

auto load_json(const std::string &path) -> json
{
    std::ifstream istrm(path);
    if (!istrm.is_open())
    {
        throw std::runtime_error(fmt::format("Failed to open json file: {}", path));
    }
    json input;
    istrm >> input;
    istrm.close();
    return input;
}