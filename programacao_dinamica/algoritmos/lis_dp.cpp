/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 *
 * Tópico: Programação Dinâmica
 *
 * Funcao desse programa: Longest Increasing Subsequence (Non-contiguous)
 *
 * Compilar: g++ lis_dp.cpp -std=c++17 -o lis
 * Executar: ./lis
 *
 * Complexidade: O(n*n)
 */

#include<bits/stdc++.h>
#define MAX 100000

using namespace std;

int lis_On2(int *v, int n){

    int ans,length[n];

    length[0] = 1;
    ans = 1;

    for(int j = 0; j < n; j++) {
        length[j] = 1;
        for (int i = 0; i < j; i++) {
            if (v[i] < v[j]) {
                length[j] = max(length[j],length[i]+1);
                ans = max(ans,length[j]);
            }
        }
    }

    return ans;
}

int main(){

    int n;
    int array[MAX+1];

    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        scanf("%d",array+i);
    }

    printf("%d\n",lis_On2(array,n));

    return 0;
}
