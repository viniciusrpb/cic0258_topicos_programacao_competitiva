#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd_extended(ll a, ll b, ll *x, ll *y){
    if(b == 0){
        *x = 1;
        *y = 0;
        return a;
    }
    else{
        ll d = gcd_extended(b, a%b, x, y);
        ll xx = *x;
        ll yy = *y;
        *x = yy;
        *y = xx - (a/b)*yy;
        return d;
    }
}

int main(){

    ll a,b,x,y,d;

    scanf("%lld %lld",&a,&b);

    d = gcd_extended(a,b,&x,&y);
  
    printf("gcd(%lld,%lld) = %lld\nx = %lld\ny = %lld\n",a,b,d,x,y);
  
    return 0;
}
