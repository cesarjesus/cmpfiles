#include "walk_function.h"

class WalkDupsFunction : public WalkFunction
{
    public:
        WalkDupsFunction();
        virtual ~WalkDupsFunction();

    public:
        void execute(string &ss);
};