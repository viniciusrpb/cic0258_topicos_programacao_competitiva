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

ll inverso_multiplicativo(ll a, ll b){
      ll x, y;
      d = gcd_extended(a, b,&x,&y);
}

int main(){

    
    return 0;
}
