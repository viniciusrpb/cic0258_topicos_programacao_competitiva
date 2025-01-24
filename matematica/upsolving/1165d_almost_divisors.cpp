#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

//4
//3 6 9 18

vector<ll> allDivisors(ll n){
    vector<ll> divs;
    
    for(ll i = 2; i*i <= n; i++){
        if(n % i == 0){
            divs.push_back(i);
            if(i != (n/i)){
                divs.push_back(n/i);
            }
        }
    }
    sort(divs.begin(),divs.end());
    return divs;
}

int main(){
    int t,n,aux;
    
    scanf("%d",&t);
    
    while(t--){
        scanf("%d",&n);
        
        ll maior,menor;
        vector<ll> divisors,almost;
        
        scanf("%d",&aux);
        menor = aux;
        maior = aux;
        divisors.push_back(aux);
        
        for(int i = 1; i < n; i++){
            scanf("%d",&aux);
            divisors.push_back(aux);
            menor = min(aux,(int) menor);
            maior = max(aux,(int) maior);
        }
        
        sort(divisors.begin(),divisors.end());
        
        almost = allDivisors(menor*maior);
        
        bool flag = false;
        
        if(almost.size() == divisors.size()){
            flag = true;
        
            for(int i = 0; i < almost.size(); i++){
                if(almost[i] != divisors[i]){
                    flag = false;
                    break;
                }
            }
        }
    
        if(flag){
            printf("%lld\n",menor*maior);
        }
        else{
            printf("-1\n");
        }
        
    }
    return 0;
}
