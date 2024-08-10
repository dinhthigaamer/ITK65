#include<bits/stdc++.h>
using namespace std;

#define ll long long 

string a,b;
ll f[21][2][2][2];
vector<int> number;

struct item
{
    int digit,ok1,ok2,zero;
};

item trace[21][2][2][2];

int Maximize(ll &target,ll value)
{
    if(target < value)
    {
        target = value;
        return 1;
    }
    return 0;
}

int val(char x)
{
    return x-'0';
}

ll cal(int pos,int ok1,int ok2,int zero)
{
    //cout<<pos<<' '<<ok1<<' '<<ok2<<' '<<zero<<endl;
    if(pos==b.size()) return zero;

    ll *ptr = &f[pos][ok1][ok2][zero];
    if((*ptr)!=-1) return (*ptr);

    *ptr=0;

    for(int i=(ok1^1)*val(a[pos]) ; i<=max(ok2*9,val(b[pos]));++i)
    {   //cout<<pos<<' '<<i<<endl;
        if(zero && i==0) continue;
        int n_ok1 = ok1|(i > val(a[pos]));
        int n_ok2 = ok2|(i < val(b[pos]));
        
        if(zero==0 && i==0) 
        {
            *ptr = cal(pos+1,n_ok1,n_ok2,0);
            trace[pos][ok1][ok2][0] = {i, n_ok1, n_ok2,0};
        }
        else 
        {
            if(Maximize(*ptr,1ll*i*cal(pos+1,n_ok1,n_ok2,1)))
            {
                //cout<<*ptr<<endl;
                trace[pos][ok1][ok2][zero] = {i, n_ok1, n_ok2,1};
            }
        }
    }

    return *ptr;
}

void find_ans(int pos,int ok1,int ok2,int zero)
{
    if(pos==b.size()) return ;
    item tmp = trace[pos][ok1][ok2][zero];

    number.push_back(tmp.digit);

    find_ans(pos+1,tmp.ok1,tmp.ok2,tmp.zero);
}

int main()
{
    //freopen("file.inp","r",stdin);
    //freopen("file.out","w",stdout);
    cin>>a>>b;
    while(a.size()<b.size()) a="0"+a;

    memset(f,-1,sizeof(f));

    ll x=cal(0,0,0,0);
    if(x==0)
    {
        cout<<b;
        return 0;
    }
    //cout<<x<<endl;
    find_ans(0,0,0,0);

    reverse(number.begin(),number.end());
    while(number.size()>1 && number.back()==0) number.pop_back();
    reverse(number.begin(),number.end());

    for(int it:number) cout<<it;
    return 0;
}