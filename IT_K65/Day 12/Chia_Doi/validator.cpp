#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 10000, "n");
    inf.readSpace();
    int m = inf.readInt(1, 10000, "m");
    inf.readEoln();

    ensuref((n % 2 == 0), "La so le");
    
    for(int i = 1; i <= m; ++i)
    {
        int u = inf.readInt(1, n, "u");
        inf.readSpace();
        int v = inf.readInt(1, n, "v");
        if(i < m) inf.readEoln();
    }

    inf.readEoln();
    inf.readEof();
}