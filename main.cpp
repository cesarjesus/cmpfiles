#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

#include <stdio.h>
#include <string.h>

#include <openssl/sha.h>

using namespace std;

/**
* &file, reference to the file stream to read
* hash, the calculated hash for the file.
* READ_BUFFER_SIZE, the block size at which the file will be read in bytes, default 4Mb.
*/
void calculate_sha256(ifstream &file, unsigned char hash[SHA256_DIGEST_LENGTH], unsigned long READ_BUFFER_SIZE = 4194304)
{
    file.seekg(0, file.end);
    unsigned long length = file.tellg();
    file.seekg(0, file.beg);

    cout << "Bytes to be read " << length << endl;
    char* buffer = new char[READ_BUFFER_SIZE];
    unsigned long counter = 0;

    SHA256_CTX sha256_context;
    SHA256_Init(&sha256_context);
    do {
        file.read(buffer, READ_BUFFER_SIZE);
        counter += file.gcount();
        cout << counter << " bytes read." << endl;
        SHA256_Update(&sha256_context, buffer, file.gcount());
    } while (counter < length);
    cout << "Total bytes read " << counter << endl;
    SHA256_Final(hash, &sha256_context);
    delete [] buffer;
}

void print_sha256(string &file, unsigned char hash[SHA256_DIGEST_LENGTH])
{
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }

    cout << file << ": " << ss.str() << endl;
}

bool files_has_same_sha256(
    unsigned char hash1[SHA256_DIGEST_LENGTH],
    unsigned char hash2[SHA256_DIGEST_LENGTH]
)
{
    return (memcmp(hash1, hash2, SHA256_DIGEST_LENGTH) == 0);
}

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
        calculate_sha256(f1, hash_f1);
        calculate_sha256(f2, hash_f2);
        print_sha256(file1, hash_f1);
        print_sha256(file2, hash_f2);
        if (files_has_same_sha256(hash_f1, hash_f2))
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
