#include "utils.h"

string Utils::getPrintableHash(unsigned char hash[SHA256_DIGEST_LENGTH])
{
    stringstream strm;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        strm << hex << setw(2) << setfill('0') << (int)hash[i];
    }

    return strm.str();
}

bool Utils::equalHash(unsigned char hash1[SHA256_DIGEST_LENGTH],
    unsigned char hash2[SHA256_DIGEST_LENGTH])
{
    return (memcmp(hash1, hash2, SHA256_DIGEST_LENGTH) == 0);
}

bool Utils::isDirectory(const string &path)
{
    struct stat buffer;
    int ret = stat(path.c_str(), &buffer);
    if (0 != ret)
    {
        cout << path << ": does not exists." << endl;
        return false;
    }

    return buffer.st_mode & S_IFDIR;
}

bool Utils::hasPermissions(const string &path)
{
    struct stat buffer;
    if (0 == stat(path.c_str(), &buffer))
    {
        // TODO: its not enough, we should check and compare with
        // user id?
        return buffer.st_mode & S_IRUSR;
    }

    return false;
}