#ifndef WALK_FUNCTION_H
#define WALK_FUNCTION_H

#include <string>

using namespace std;

class WalkFunction {

    public:
        WalkFunction();
        virtual ~WalkFunction();

    public:
        virtual void execute(string &ss) = 0;
};

#endif