/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 *
 * Tópico: Busca Binária
 *
 * Funcao desse programa: Longest Increasing Subsequence (Non-contiguous)
 *
 * Based on: https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
 *
 * Compilar: g++ lis_bsearch.cpp -std=c++17 -o lis
 * Executar: ./lis
 *
 * Complexidade: O(n log n)
 */

#include<bits/stdc++.h>
#define MAX 100000

using namespace std;

int bsearch_index(int *v, int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}

int lis_nlogn(int *v, int n){

    int tail[n+1];

    int index,tam = 1;

    tail[0] = v[0];
    for(int i = 1; i < n; i++){

        if (v[i] < tail[0])
            tail[0] = v[i];
        else
            if (v[i] > tail[tam - 1])
                tail[tam++] = v[i];
            else{
                index = bsearch_index(tail,-1,tam-1,v[i]);
                tail[index] = v[i];
            }
    }

    return tam;
}

int main(){

    int n;
    int array[MAX+1];

    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        scanf("%d",array+i);
    }

    printf("%d\n",lis_nlogn(array,n));

    return 0;
}
