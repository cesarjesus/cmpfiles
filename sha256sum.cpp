#include "sha256sum.h"

#include <iostream>

SHA256Sum::SHA256Sum()
{

}

SHA256Sum::~SHA256Sum()
{

}

void SHA256Sum::GetSHA256(
    ifstream &file,
    unsigned char hash[SHA256_DIGEST_LENGTH],
    unsigned long READ_BUFFER_SIZE)
{
    file.seekg(0, file.end);
    unsigned long length = file.tellg();
    file.seekg(0, file.beg);
#ifdef DEBUG
    cout << "Bytes to be read " << length << endl;
#endif
    char* buffer = new char[READ_BUFFER_SIZE];
    unsigned long counter = 0;

    SHA256_CTX sha256_context;
    SHA256_Init(&sha256_context);
    do {
        file.read(buffer, READ_BUFFER_SIZE);
        counter += file.gcount();
#ifdef DEBUG
        cout << counter << " bytes read." << endl;
#endif
        SHA256_Update(&sha256_context, buffer, file.gcount());
    } while (counter < length);
#ifdef DEBUG
    cout << "Total bytes read " << counter << endl;
#endif
    SHA256_Final(hash, &sha256_context);
    delete [] buffer;
}
