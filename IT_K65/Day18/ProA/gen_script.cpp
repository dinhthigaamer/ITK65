#include<bits/stdc++.h>
using namespace std;

int main() 
{
    freopen("file.out","w",stdout);
    for(int i=2;i<=40;++i) {
        cout<<"<#list "<<i<<".."<<i<<" as test> gen -value_t "<<i<<" -order "<<i<<" > $ "<<endl;
    }     
}
//<#list 2..2 as test> gen -value_t 2 -order 1 > $