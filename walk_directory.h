#include "walk_function.h"

class WalkDirectory {

    private:
        string s_path;

    public:
        WalkDirectory(const string &path);
        virtual ~WalkDirectory();

    public:
        void apply(WalkFunction*);
};