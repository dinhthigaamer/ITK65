#include "testlib.h"
#include <iostream>

using namespace std;
#define ll long long 

int n,m;

void Gen(int limit)
{
    if(limit <= 5)
    {
        n = 2*rnd.next(1,2);
        m = rnd.next(1, 5);
    }
    else
    if(limit == 6)
    {
        n = 2*rnd.next(3, 500);
        m = rnd.next(6, 1000);
    }
    else 
    if(limit == 7)
    {
        n = 1000; 
        m = 1000;
    }
    else 
    if(limit == 8)
    {
        n = 2*rnd.next(502, 25000);
        m = rnd.next(1005, 50000);
    }
    else
    {
        n = 50000;
        m = 50000;
    }
    cout << n << ' ' << m << '\n';

    vector<int> t1, t2;
    for(int i = 1; i <= n; ++i)
    {
        if(t1.size() == n/2) t2.push_back(i);
        else 
        if(t2.size() == n/2) t1.push_back(i);
        else 
        {
            int t = rnd.next(0, 1);
            if(t == 0) t1.push_back(i);
            else 
            t2.push_back(i);
        }
    }

    int match = rnd.next(1, m);
    for(int i = 1; i <= m; ++i)
    {
        if(i <= match)
        {
            int u1 = t1[rnd.next(0, n/2 - 1)];
            int v1 = t2[rnd.next(0, n/2 - 1)];
            cout << u1 << ' ' << v1;
        }
        else 
        {
            int u1 = rnd.next(1, n);
            int v1 = rnd.next(1, n);
            if(v1 == u1) 
            {
                if(v1 < n) ++v1;
                else --v1;
            }

            cout << u1 << ' ' << v1;
        }

        if(i < m) cout << '\n';
    }

    cout << '\n';
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