/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 *
 * Tópico: Programação Dinâmica
 * Objetivo: Código-fonte que implementa três soluções para
 *           resolver o problema do sub-sequência de soma máxima:
 *           sssm_n3 : solução Naive O(N^3)
 *           sssm_n2 : solução Naive O(N^2)
 *           sssm_n  : solução Gulosa O(N)
 *
 * Compilar no terminal: g++ subseqsomamax.cpp -std=c++17 -o sssm
 * Executar: ./sssm
 */

#include<bits/stdc++.h>
#define MAX 1000

using namespace std;

typedef long long ll;

/* Abordagem de complexidade O(N*N*N) */
ll sssm_n3(int *v, int N){
    ll ans = -1e9;

    for (int i = 0; i < N; i++){
        for (int j = i; j < N; j++){
            ll soma = 0;

            for (int k = i; k <= j; k++)
                soma += v[k];

            ans = max(ans, (ll) soma);
        }
    }

    return ans;
}

/* Abordagem de complexidade O(N*N) */
ll sssm_n2(int *v, int N){
    ll ans = 0;

    for (int i = 0; i < N; i++){
        ll soma = 0;
        for(int j = i; j < N; j++){
            soma += v[j];
            ans = max(ans, soma);
        }
    }

    return ans;
}

/* Abordagem Gulosa, complexidade O(N) */
ll sssm_n(int *v, int N){
    int l,r,j;
    ll somamax,somatemp;

    j = 0;
    somamax = -1e9;
    somatemp = 0;

    for(int i = 0; i < N; i++){
        somatemp = somatemp + v[i];

        if(somatemp > somamax){
            somamax = somatemp;
            l = j;
            r = i;
        }

        if(somatemp < 0){
            somatemp = 0;
            j = i+1;
        }
    }

    //printf("%d %d\n",l,r);
    return somamax;
}

int main(){

    int arr[MAX];
    int n;

    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }

    printf("%lld\n",sssm_n3(arr,n));
    printf("%lld\n",sssm_n2(arr,n));
    printf("%lld\n",sssm_n(arr,n));

    return 0;
}
