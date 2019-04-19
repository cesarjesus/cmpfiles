#include <fstream>
#include <openssl/sha.h>

using namespace std;

class SHA256Sum {

    public:
        SHA256Sum();
        virtual ~SHA256Sum();

    public:
        /**
        * &file, reference to the file stream to read
        * hash, the calculated hash for the file.
        * READ_BUFFER_SIZE, the block size at which the file
        *  will be read in bytes, default 4Mb.
        */
        void GetSHA256(
            ifstream&,
            unsigned char hash[SHA256_DIGEST_LENGTH],
            unsigned long READ_BUFFER_SIZE = 4194304);
};
