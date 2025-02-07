#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    if(b == 0)
        return a;
    return gcd(b,a%b);
}

int main(){
    ll a,b;

    scanf("%lld %lld",&a,&b);

    printf("%lld\n",gcd(a,b));

    return 0;
}
