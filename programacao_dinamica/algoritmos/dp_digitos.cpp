/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 * 
 * Tópico: Programação Dinâmica
 * Objetivo: Código-fonte que implementa uma DP de Dígitos para determinar a soma dos digitos dos numeros entre [a,b].
 * 
 * Compilar no terminal: g++ dp_digitos.cpp -std=c++17 -o dig
 * Executar: ./dig
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll tab[20][2][180];

void getDigits(int n, vector<int>& digits){
    while(n){
        digits.push_back(n%10);
        n=n/10;
    }
}

ll dp(int idx, int tight, int sum, vector<int>& digits){
    int k, newtight;
    
    if(idx == -1){
        return sum;
    }
    
    if(tab[idx][tight][sum] != -1 and tight != 1){
        return tab[idx][tight][sum];
    }
    
    ll ans = 0;
    if(tight == 1)
        k = digits[idx];
    else
        k = 9;
    
    for(int i = 0; i <= k ; i++){
        newtight = 0;
        if(digits[idx] == i)
            newtight = tight;

        ans+=dp(idx-1,newtight,sum+i,digits);
    }
    
    if(!tight)
        tab[idx][tight][sum]=ans;
    
    return ans;
}

ll solve(int l, int r){
    
    memset(tab, -1, sizeof(tab));
    
    vector<int> digitsL;
    getDigits(l-1,digitsL);
    
    ll ans_l = dp(digitsL.size()-1,1,0,digitsL);
    
    vector<int> digitsR;
    getDigits(r,digitsR);
    
    ll ans_r = dp(digitsR.size()-1,1,0,digitsR);
    
    return ans_r - ans_l;
    
}

int main(){
    int t,a,b;
    
    scanf("%d",&t);
    
    while(t--){
        scanf("%d %d",&a,&b);
        printf("%lld\n",solve(a,b));
    }
    return 0;
}
