#include "compilation.ih"

string output_name(string const &file, string const &folder)
{
    fs::path path{file};
    path = fs::path{folder + "/" + path.filename().string()};
    path.replace_extension(".o");

    return path.string();
}