** Playing with files and file attributes **

Dependencies
============

* libssl-dev
* pkg-config (to solve the library flags)

Compile
=======

* g++ -Wall -o compare main.cpp -lssl -lcrypto

Run
===
./compare
Read /tmp/file1.txt and /tmp/file2.txt
