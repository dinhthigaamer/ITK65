#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1e0, 2e5, "n");
    inf.readSpace();
    int m = inf.readInt(1e0, 2e5, "m");
    inf.readEoln();

    ensuref((n>0 && n<=2e5),"Invalid n !");

    for (int i=1; i<=m; ++i)
    {
        int l = inf.readInt(1, n, "l");
        inf.readSpace();
        int r = inf.readInt(l, n, "r");
        inf.readSpace();
        int p = inf.readInt(-1e9, 1e9, "p");
        if(i<m) inf.readEoln();
    }

    inf.readEoln(); 
    inf.readEof();
}