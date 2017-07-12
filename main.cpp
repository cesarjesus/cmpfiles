#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
  cout << "Starting compare files..." << endl;

  string file1 = "/tmp/file1.txt";
  string file2 = "/tmp/file2.txt";

  cout << "Comparing: [" << file1 << "] with [" << file2 << "]" << endl;
  ifstream f1, f2;
  f1.open(file1.c_str());
  f2.open(file2.c_str());
  if (f1.is_open())
  {
    cout << "File [" << file1 << "] opened." << endl;
    f1.close();
    cout << "File [" << file1 << "] closed." << endl;
  }
  else
  {
    cout << "File [" << file1 << "] cannot be opened." << endl;
  }

  if (f2.is_open())
  {
    cout << "File [" << file2 << "] opened." << endl;
    f2.close();
    cout << "File [" << file2 << "] closed." << endl;
  }
  else
  {
    cout << "File [" << file2 << "] cannot be opened." << endl;
  }

  if (f1.is_open() && f2.is_open())
  {
    
  }

  cout << "... shutting down." << endl;

  return 0;
}
