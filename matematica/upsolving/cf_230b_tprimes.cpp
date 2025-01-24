#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
vector<ll> crivo2(ll n)
{
    vector<ll> flags(n+1,1);
    
    flags[0] = 0;
    flags[1] = 0;
    
    for(ll x = 3; x < n; x=x+2)
    {
        flags[x-1]=0;
        if(flags[x])
        {
            for(ll m = x+x; m < n; m=m+x)
            {
                flags[m] = 0;
            }
        }
    }
    flags[2] = 1;
    return flags;
}
 
int main()
{
    ll n,x,raiz;
    vector<ll> flags;
    scanf("%lld",&n);
    
    flags = crivo2(1e6+1);
 
    for(int i = 0; i < n; i++)
    {
        scanf("%lld",&x);
 
        raiz = sqrt(x);
        
        if(raiz*raiz == x && flags[raiz] == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
