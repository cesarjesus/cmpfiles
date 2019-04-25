
#include <sstream>
#include <iomanip>
#include <string>
#include <string.h>
#include <openssl/sha.h>

using namespace std;

class Utils
{
    public:
        static string getPrintableHash(unsigned char hash[SHA256_DIGEST_LENGTH]);
        static bool equalHash(unsigned char hash1[SHA256_DIGEST_LENGTH],
            unsigned char hash2[SHA256_DIGEST_LENGTH]);
};