#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<bool> ehPrimo(1000001,true);

void sieve(int n){

    vector<int> primos;
    
    primos.push_back(2);
    
    for(ll i = 3; i <= n; i=i+2){
        if(ehPrimo[i]){
            primos.push_back(i);
            for(ll x = i+i; x <= n; x=x+i){
                ehPrimo[i] = false;
            } 
        }
    }
}

bool is_prime(ll n){
    if(n < 2)
        return false;
        
    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

vector<ll> allDivisors(ll n){
    vector<ll> divs;
    
    for(ll i = 1; i*i <= n; i++){
        if(n % i == 0){
            if(is_prime(i))
                divs.push_back(i);
            if(i != n/i && is_prime(n/i)){
                divs.push_back(n/i);
            }
        }
    }
    sort(divs.begin(),divs.end());
    return divs;
}


int main(){

    int ans,n;

    scanf("%d",&n);
    
    ans = 0;
    for(int i = 1; i <= n; i++){
        vector<ll> divs = allDivisors(i);
        if(divs.size() == 2)
            ans++;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
