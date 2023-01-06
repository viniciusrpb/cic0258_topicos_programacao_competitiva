/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 *
 * Tópico: Caminhos mínimos em grafos
 *
 * Funcao desse programa: Algoritmo básico de Floyd-Warshall
 *
 * Compilar: g++ floyd_warshall.cpp -std=c++17 -o floyd
 * Executar: ./floyd
 */
#include<bits/stdc++.h>
#define MAX 100
#define oo 1e18

using namespace std;

int main(){
    int W[MAX][MAX],D[MAX][MAX];
    int n,m,a,b,w;

    scanf("%d %d",&n,&m);

    /* Ler inform. do grafo
        ...
        scanf("%d %d %d",&a,&b,&w);
        W[a][b] = w;
    */

    for(int i =1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)
                D[i][j] = 0;
            else
                if(W[i][j])
                    D[i][j] = W[i][j];
                else
                    D[i][j] = oo;
        }
    }

    /* Solucao da recorrencia Dij = min(Dij,Dik+Dkj)*/
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            if(i != k){
                for(int j = 1; j <= n; j++){
                    if(i != j && j != k){
                        D[i][j] = min(D[i][j],D[i][k] + D[k][j]);
                    }
                }
            }
        }
    }

    /* Imprime resposta: por exemplo, o menor caminho
     entre o vertice 1 e n */
    printf("%d",D[1][n]);


    return 0;
}
