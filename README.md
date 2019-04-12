** Playing with files and file attributes **

Dependencies
============

* libssl-dev
* pkg-config (to solve the library flags)

Compile
=======

`$ g++ -Wall -o compare main.cpp -lssl -lcrypto`

Run
===
`$ ./compare <file1> <file2>`
