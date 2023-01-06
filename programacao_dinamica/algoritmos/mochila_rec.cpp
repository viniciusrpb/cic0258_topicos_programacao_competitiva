/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 *
 * Aula: Programacao Dinamica (Problema da Mochila Recursiva)
 *
 * Funcao desse programa: Dado um conjunto de N itens I={I1, I2, ... , IN}, em que,
 *
 * Ii = (pi,vi)             p/ i <= N
 *    - pi eh o peso do item Ii;
 *    - vi eh o valor do item Ii;
 *
 *... o algoritmo da mochila calcula o valor maximo ao inserir os itens na mochila que nao ultrapassem sua capacidade maxima C
 *
 * Complexidade: O(nC)
 *
 * Compilar: g++ mochila_rec.cpp -std=c++17 -o mochilarec
 * Executar: ./mochilarec
 */

#include<bits/stdc++.h>
#define MAX_ITENS 1000
#define MAX_CAPMOCHILA 1000

using namespace std;

typedef long long ll;

int n;
vector<int> peso;
vector<int> valor;

ll tab[MAX_ITENS][MAX_CAPMOCHILA];

ll mochila_rec(int i, int c)
{
    ll pegar,naopegar;

    if(i <= 0 || c <= 0)
        return 0;

    if(tab[i][c] > -1)
        return tab[i][c];

    pegar = -1e9;

    if(peso[i] <= c)
    {
        pegar = mochila_rec(i-1,c-peso[i])+valor[i];
    }

    naopegar = mochila_rec(i-1,c);

    tab[i][c] = max(pegar,naopegar);

    return tab[i][c];
}


int main(){
    int aux,p,v,C;

    scanf("%d %d",&n,&C);

    for(int i = 0; i <= n;i++){
        for(int j = 0; j <= C; j++){
            tab[i][j] = -1;
        }
    }

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

    printf("%lld\n",mochila_rec(n,C));

    return 0;
}
