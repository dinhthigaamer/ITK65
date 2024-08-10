#include "testlib.h"

int n,m;
int k;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    m = inf.readInt(1, 400, "m");
    inf.readSpace();
    n = inf.readInt(1, 400, "n");
    inf.readEoln();

    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            char x = inf.readChar();
        }
        if(i<m) inf.readEoln();
    }

    inf.readEoln();
    
    inf.readEof();
}