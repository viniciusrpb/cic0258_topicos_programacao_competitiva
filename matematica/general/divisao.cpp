#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

vector<int> sieve(int n){
    vector<int> primos;
    vector<bool> ehPrimo(n+2,true);
    
    ehPrimo[0] = false;
    ehPrimo[1] = false;
    for(int x = 2; x <= n; x++){
        if(ehPrimo[x]){
            primos.push_back(x);
            for(int m = x+x; m <= n; m+=x){
                ehPrimo[m] = false;
            }
        }
    }
    return primos;
}

vector<int> sieve2(int n){
    vector<int> lp(n+2,-1);
    for(int x = 2; x <= n; x++){
        if(lp[x] == -1){
            for(int m = x; m <= n; m+=x){
                lp[m] = x;
            }
        }
    }
    return lp;
}

vector<pii> fatora(int n,vector<int>& lp){
    
    int expoente,fator;
    map<int,int> exp;
    vector<pii> ans;
    fator = 2;
    
    while(n > 1){
        exp[lp[n]]++;
        n/=lp[n];
    }
    
    for(auto a : exp){
        ans.push_back(a);        
    }
    /*while(n > 1){
        expoente = 0;
        while(n%fator == 0){
            n=n/fator;
            expoente++;
        }
        ans.push_back({fator,expoente});
        fator+=1;
    }*/
    return ans;
}

int main(){

    int n;
    
    scanf("%d",&n);
    
    vector<int> primos = sieve(n);
    
    for(int i = 0; i < primos.size(); i++){
        printf("%d ",primos[i]);
    }
    printf("\n");
    
    vector<int> lp = sieve2(n);
    
    for(int i = 2; i < lp.size(); i++){
        printf("%d - %d\n",i,lp[i]);
    }
    printf("\n");
    
    vector<pii> ans = fatora(n,lp);
    
    for(int i = 0; i < ans.size(); i++){
        printf("%d^%d * ",ans[i].first,ans[i].second);
    }
    printf("\n");
    
    return 0;
}
