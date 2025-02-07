#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool ehPrimo(ll n){
    
    for(ll x = 2; x*x <= n; x++){
        if(n % x == 0){
            return false;
        }
    }
    
    return true;
}

void encontraPrimos(ll n, ll *p, ll *q){
    
    for(ll x = 2; x*x <= n; x++){
        if(n%x == 0 and ehPrimo(x)){
            *p = x;
            *q = n/x;
        }
    }
}

ll gcdExtended(ll a, ll m, ll &x, ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return m;
    }
    ll x1, y1;
    ll gcd = gcdExtended(m % a, a, x1, y1);

    x = y1 - (m / a) * x1;
    y = x1;

    return gcd;
}

ll modularInverse(ll a, ll m) {
    ll x, y;
    ll ans = gcdExtended(a, m, x, y);
    if(ans != 1){
        return -1;
    }
    else{
        return (x % m + m) % m;
    }
}

ll fast_exp(ll base, ll e, ll mod){
    if(e == 0)
        return 1;
    
    if(e%2 == 0)
        return fast_exp((base*base)%mod,e/2,mod)%mod;
    else
        return (base*fast_exp((base*base)%mod,e/2,mod))%mod;
}

int main(){

    ll tot,n,c,e,q,p,d;
    
    scanf("%lld %lld %lld",&n,&e,&c);
    
    encontraPrimos(n,&p,&q);
    
    tot = (p-1)*(q-1);
    
    d = modularInverse(e,tot);
    
    printf("%lld\n",fast_exp(c,d,n));   
    
    return 0;
}
