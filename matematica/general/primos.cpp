#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

vector<ll> crivo(ll n){

    vector<ll> primos;
    vector<bool> ehPrimo(n,true);
    
    ehPrimo[0] = false;
    ehPrimo[1] = false;
    primos.push_back(2);
    for(ll i = 3; i <= n; i=i+2){
        ehPrimo[i-1] = false;
        if(ehPrimo[i]){
            primos.push_back(i);
            for(ll m = i+i; m <= n; m+=i){
                ehPrimo[m] = false;
            }
        }
    }
    ehPrimo[2] = true;
    return primos;
}

vector<pll> fatoracao(ll n){

    vector<pll> fatores;
    vector<ll> lp(n+1,-1);
    map<int,int> expoentes;
    
    for(ll i = 2; i <= n; i++){
        if(lp[i] == -1){
            for(ll m = i; m <= n; m+=i){
                lp[m] = i;
            }
        }
    }
    
    for(int i = 2; i <= n; i++){
        printf("%d %lld\n",i,lp[i]);
    }
    
    while(n > 1){
        expoentes[lp[n]]++;
        n = n / lp[n];
    }
    
    for(auto p : expoentes){
        fatores.push_back(p);
    }
    
    return fatores;
}

int main(){
    int n;
    vector<pll> ans;
    
    scanf("%d",&n);
    
    /*ans = crivo(n);
    
    for(int i = 0; i < ans.size(); i++){
        printf("%lld\n",ans[i]);
    }*/
    
    ans = fatoracao(n);
    
    for(int i = 0; i < ans.size(); i++){
        printf("%lld^%lld\n",ans[i].first,ans[i].second);
    }
    
    return 0;
}
