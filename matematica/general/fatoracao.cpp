#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<ll,ll> pll;

vector<ll> crivo(ll n){
    vector<ll> primos;
    vector<ll> ehPrimo(n+1,true);

    ehPrimo[0] = false;
    ehPrimo[1] = false;

    primos.push_back(2);
    for(ll x = 3; x <=n; x=x+2){
        ehPrimo[x-1] = false;
        if(ehPrimo[x]){
            primos.push_back(x);
            for(ll m = x*x;m <=n;m=m+x){
                ehPrimo[m] = false;
            }
        }
    }
    ehPrimo[2] = true;

    return primos;
}

vector<pll> fatorizacao(ll n){

    vector<pll> fatores;
    vector<ll> primos = crivo(n);
    // O(log n)
    int ind = upper_bound(primos.begin(),primos.end(),n)-primos.begin();

    // O(f) em que f eh a quantidade de fatores primos em analise
    for(int i = ind-1; i >= 0; i--){
        int exp = 0;
        while(n%primos[i] == 0){
            n = n / primos[i];
            exp++;
        }
        if(exp)
            fatores.push_back(make_pair(primos[i],exp));
    }
    return fatores;
}

vector<pll> fastFatorization(ll n){

    vector<ll> lp(n+1,-1);
    vector<pll> exp;

    for(ll x = 2; x <= n; x++){

        //lp[x] = -1, eh primo
        if(lp[x] == -1){
            for(ll m = x; m <= n; m=m+x){
                lp[m] = x;
            }
        }
    }

    /*for(int i = 2; i <= n; i++){
        printf("%d %lld\n",i,lp[i]);
    }*/

    map<ll,ll> expoentes;
    while(n>1){
        expoentes[lp[n]]++;
        n=n/lp[n];
    }

    for(auto p: expoentes){
        exp.push_back(make_pair(p.first,p.second));
    }
    return exp;
}

int main(){

    int n;
    scanf("%d",&n);

    //vector<ll> ans = crivo(n);

    /*for(int i = 0; i < ans.size(); i++){
        printf("%lld ",ans[i]);
    }
    printf("\n");*/

    /*vector<pll> fat = fatorizacao(n);

    for(int i = 0; i < fat.size(); i++){
        printf("%lld^%lld ",fat[i].first,fat[i].second);
    }
    printf("\n");*/

    vector<pll> ans = fastFatorization(n);
    for(int i = 0; i < fat.size(); i++){
        printf("%lld^%lld ",fat[i].first,fat[i].second);
    }
    printf("\n");

    return 0;
}



