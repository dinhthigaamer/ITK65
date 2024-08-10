#include "testlib.h"
#include <iostream>

using namespace std;
#define ll long long 

int n,m;

void Gen(int limit)
{
    if(limit <= 5)
    {
        cout << limit;
    }
    else 
    if(limit <= 10)
    {
        cout << limit;
    }
    else
    if(limit == 11) 
    {
        cout << rnd.next(1, 1000000);
    }
    else 
    {
        cout << 1000000;
    }

    cout << endl;
}

void File()
{
    freopen("file.inp","w",stdout);
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    prepareOpts(argc, argv);
    //File();
    int value_t = opt<int>("value_t"); 
    int order = opt<int>("order");

    Gen(value_t);
    

    return 0;
}