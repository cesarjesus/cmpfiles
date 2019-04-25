#include <iostream>
#include <fstream>
#include <string>

#include <stdio.h>

#include "sha256sum.h"
#include "utils.h"

using namespace std;

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        cout << "Usage:" << endl;
        cout << "\t./compare <file1> <file2>" << endl;
        return 1;
    }

    cout << "Starting compare files..." << endl;

    string file1 = argv[1];
    string file2 = argv[2];

    cout << "Comparing: [" << file1 << "] with [" << file2 << "]" << endl;
    ifstream f1, f2;
    f1.open(file1.c_str());
    f2.open(file2.c_str());

    if (f1.is_open() && f2.is_open())
    {
        unsigned char hash_f1[SHA256_DIGEST_LENGTH];
        unsigned char hash_f2[SHA256_DIGEST_LENGTH];
        SHA256Sum hashSum;
        hashSum.GetSHA256(f1, hash_f1);
        hashSum.GetSHA256(f2, hash_f2);
        cout << file1 << ":" << Utils::getPrintableHash(hash_f1) << endl;
        cout << file2 << ":" << Utils::getPrintableHash(hash_f2) << endl;
        if (Utils::equalHash(hash_f1, hash_f2))
        {
            cout << "Files are same based on the SHA256 sum." << endl;
        }
        else
        {
            cout << "Files are different based on the SHA256 sum." << endl;
        }
    }

    if (f1.is_open())
    {
        f1.close();
    }

    if (f2.is_open())
    {
        f2.close();
    }

    cout << "... shutting down." << endl;

    return 0;
}
