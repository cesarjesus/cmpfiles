#include "walk_directory.h"

WalkDirectory::WalkDirectory(const string &path)
{
    s_path = path;
}

WalkDirectory::~WalkDirectory()
{

}

void WalkDirectory::apply(WalkFunction* function)
{
    function->execute(s_path);
}