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