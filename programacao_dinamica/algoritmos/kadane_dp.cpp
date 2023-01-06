/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 *
 * Tópico: Programação Dinâmica
 * Objetivo: Código-fonte que implementa o algoritmo iterativo de Kadane para
 *           resolver o problema do sub-array de soma máxima
 *
 * Compilar no terminal: g++ kadane_dp.cpp -std=c++17 -o kadane
 * Executar: ./kadane_dp
 */

#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

typedef long long ll;

ll tab[MAX];

ll kadane(int *v, int n){

    ll soma = v[0];
    tab[0] = v[0];

    for(int i = 1; i < n; i++){
        tab[i] = max(tab[i-1]+v[i], (ll) v[i]);

        if(tab[i] >= soma)
            soma=tab[i];
    }

    return soma;
}

int main(){

    int arr[MAX];
    int n;

    scanf("%d",&n);

    /*Inicializar a tabela da DP com valores neutros: aqui no caso é -1*/
    for(int i =0; i < n ; i++){
        tab[i] = -1;
    }

    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }

    printf("%lld\n",kadane(arr,n));

    return 0;
}
