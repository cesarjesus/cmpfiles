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
        uid_t uid = getuid();
        gid_t gid = getgid();
        // check if the current user has read permissions as the owner
        if ((uid == buffer.st_uid && (buffer.st_mode & S_IRWXU))
            // check if the current user has read permissions as part of group
            || (gid == buffer.st_gid && (buffer.st_mode & S_IRWXG))
            // check if there are read permissions as part of others
            || (buffer.st_mode & S_IRWXO))
        {
            return true;
        }
    }

    return false;
}