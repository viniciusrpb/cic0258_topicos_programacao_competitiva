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
#define MAX 200001

using namespace std;

int pred[200001],ind_bucket[200001];

int lis_binsearch(int *v, int n){

    int bucket[200001];

    bucket[0] = v[0];
    ind_bucket[0] = 0;

    pred[0] = -1;

    int k = 1;
    for(int i = 1; i < n; i++){
        if(v[i] > bucket[k-1]){
            pred[i] = ind_bucket[k-1];
            ind_bucket[k] = i;
            bucket[k] = v[i];
            k++;
        }
        else{
            int index = lower_bound(bucket,bucket+k,v[i])-bucket;
            bucket[index] = v[i];
            ind_bucket[index] = i;

            if(index > 0)
                pred[i] = ind_bucket[index-1];
            else
                pred[i] = -1;
        }
    }

    return k;
}

int main(){

    int ans,n;
    int arr[MAX];
    vector<int> subsequence;

    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }

    ans = lis_binsearch(arr,n);
    printf("%d\n",ans);

    int index = ind_bucket[ans-1];
    while(index != -1) {
        subsequence.push_back(arr[index]);
        index = pred[index];
    }

    reverse(subsequence.begin(), subsequence.end());
    for(int i = 0; i < subsequence.size(); i++){
        printf("%d ", subsequence[i]);
    }
    printf("\n");

    return 0;
}
