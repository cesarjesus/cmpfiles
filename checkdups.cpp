#include <iostream>

#include "utils.h"

using namespace std;

void usage(char** argv)
{
    cout << "Usage:" << endl;
    cout << "\t" << argv[0] << " " << "<dir>" << endl;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        usage(argv);
        return 0;
    }

    string path = argv[1];
    if (Utils::isDirectory(path) && Utils::hasPermissions(path))
    {
        cout << "will check for dups on: " << path << endl;
    }
    else
    {
        cout << path << ": is not a directory or there is no permissions." << endl;
    }
    

    return 0;
}