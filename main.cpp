#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

#include <stdio.h>
#include <string.h>

#include <openssl/sha.h>

using namespace std;

void calculate_sha256(ifstream &file, unsigned char hash[SHA256_DIGEST_LENGTH])
{
  file.seekg(0, file.end);
  long length = file.tellg();
  file.seekg(0, file.beg);

  char* buffer = new char[length];
  cout << "Will be read " << length << " elements." << endl;
  file.read(buffer, length);

  SHA256_CTX sha256_context;
  SHA256_Init(&sha256_context);
  SHA256_Update(&sha256_context, buffer, length);
  SHA256_Final(hash, &sha256_context);
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

int main(int argc, char** argv)
{
  cout << "Starting compare files..." << endl;

  string file1 = "/tmp/file1.txt";
  string file2 = "/tmp/file2.txt";

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
