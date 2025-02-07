#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

ll fast_exp_mod(ll a, ll b, ll mod){
    
    if(b == 0)
        return 1;
    
    if(b%2)
        return a*fast_exp_mod(a*a%mod, b/2, mod)%mod;
    else
        return fast_exp_mod(a*a%mod, b/2, mod);
}
 
int main(){
     int n,a,b;
    
     scanf("%d",&n);
    
     while(n--){
         scanf("%d %d",&a,&b);
         printf("%lld\n",fast_exp_mod(a,b,1000000007LL));
     }

     return 0;
}
