/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 *
 * Tópico: Programação Dinâmica (Abordagem Iterativa)
 *
 * Funcao desse programa: Dado um conjunto de n itens I={I1, I2, ... , In}, em que,
 *
 * Ii = (pi,vi)             p/ i <= n
 *    - pi eh o peso do item Ii;
 *    - vi eh o valor do item Ii;
 *
 *... o algoritmo da mochila calcula o valor maximo ao inserir os itens na mochila que nao ultrapassem sua capacidade maxima C
 *
 * Compilar: g++ mochila_dp.cpp -std=c++17 -o mochila_dp
 * Executar: ./mochila_dp
 *
 * Complexidade: O(nC)
 */

#include<bits/stdc++.h>

using namespace std;

int n; /* quantidade total de itens */
int C; /* capacidade maxima da mochila */
vector<int> peso; /* trabalha com no max. 100 itens */
vector<int> valor;
int tab[101][101];  /* tabela prog dinamica que armazena
                    os resultados intermediarios
                    armazena no max 100 itens, com capacidade
                    maxima da mochila = 100 */

int mochila_dp(){

    for(int i = 0; i<=n; i++){
        for(int j=0; j <=C;j++){
            tab[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int c = 1; c <= C; c++){

            if(peso[i] <= c)
                tab[i][c] = max(tab[i-1][c-peso[i]]+valor[i],tab[i-1][c]);
            else
                tab[i][c] = tab[i-1][c];
        }
    }

    return tab[n][C];
}

int main(){
    int v,p;

    scanf("%d %d",&n,&C);

    valor.push_back(0);

    for(int i = 0; i < n; i++){
        scanf("%d",&v);
        valor.push_back(v);
    }

    peso.push_back(0);

    for(int i = 0; i < n; i++){
        scanf("%d",&p);
        peso.push_back(p);
    }

    printf("Valor max. da mochila DP: %d\n",mochila_dp());

    return 0;
}
