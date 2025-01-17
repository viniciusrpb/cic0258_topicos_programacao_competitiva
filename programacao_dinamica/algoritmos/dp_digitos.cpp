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

ll tab[20][2][200];

void num2digits(int n, vector<int>& digits){
    while(n){
        digits.push_back(n%10);
        n = n/10;
    }
}

ll dp(int idx, int trava, int soma, vector<int>& digits){

    if(idx == -1)
        return soma;

    if(tab[idx][trava][soma] != -1 and trava != 1){
        return tab[idx][trava][soma];
    }

    int max_digit,next_trava;

    if(trava == 1)
        max_digit = digits[idx];
    else
        max_digit = 9;

    ll ans = 0;

    // i : valor literal do digito
    for(int i = 0; i <= max_digit; i++){
        next_trava = 0;
        if(trava == 1 && i == max_digit){
            next_trava = 1;
        }
        ans += dp(idx-1,next_trava,soma+i,digits);
    }

    if(trava == 0)
        tab[idx][trava][soma] = ans;

    return ans;
}

ll solve(int a, int b){

    // inicializacao da tabela
    memset(tab,-1,sizeof(tab));

    vector<int> digitsA;
    num2digits(a-1,digitsA);
    ll sum_a = dp(digitsA.size()-1,1,0,digitsA); // completar depois;

    vector<int> digitsB;
    num2digits(b,digitsB);
    ll sum_b = dp(digitsB.size()-1,1,0,digitsB); // completar depois;

    return sum_b - sum_a;
}

int main(){
    int t;
    ll a,b;

    scanf("%d",&t);

    while(t--){
        scanf("%lld %lld",&a,&b);
        printf("%lld\n",solve(a,b));
    }

    return 0;
}
