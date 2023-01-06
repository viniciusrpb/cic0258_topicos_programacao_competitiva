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

ll tab[MAX_ITENS][MAX_CAPMOCHILA];
vector<int> g[N];

// there are four nodes in example graph (graph is 1-based)
const int n = 4;
// give appropriate maximum to avoid overflow
const int MAX = 1000000;

// dist[i][j] represents shortest distance to go from i to j
// this matrix can be calculated for any given graph using
// all-pair shortest path algorithms
int dist[n + 1][n + 1] = {
    { 0, 0, 0, 0, 0 },    { 0, 0, 10, 15, 20 },
    { 0, 10, 0, 25, 25 }, { 0, 15, 25, 0, 30 },
    { 0, 20, 25, 30, 0 },
};

// memoization for top down recursion
int memo[n + 1][1 << (n + 1)];

int fun(int i, int mask)
{
    // base case
    // if only ith bit and 1st bit is set in our mask,
    // it implies we have visited all other nodes already
    if (mask == ((1 << i) | 3))
        return dist[1][i];
    // memoization
    if (memo[i][mask] != 0)
        return memo[i][mask];

    int res = MAX; // result of this sub-problem

    // we have to travel all nodes j in mask and end the
    // path at ith node so for every node j in mask,
    // recursively calculate cost of travelling all nodes in
    // mask except i and then travel back from node j to
    // node i taking the shortest path take the minimum of
    // all possible j nodes

    for (int j = 1; j <= n; j++)
        if ((mask & (1 << j)) && j != i && j != 1)
            res = std::min(res, fun(j, mask & (~(1 << i)))
                                    + dist[j][i]);
    return memo[i][mask] = res;
}

int travelling_salesman(int current_city, int bitmask){
    int ans = INF;

    for(int i = 1; i <= n; i++){
        if foi == true
            continue

    }
}

int dijkstra(){


}


int main(){
    int x,y;

    // n vertices and m edges
    scanf("%d %d",&n,&m);

    for(int i = 0; i <= n;i++){
        for(int j = 0; j <= C; j++){
            tab[i][j] = -1;
        }
    }

    for(int i = 0; i < m; i++){
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    /* Calcula a matriz de distancias */
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= n; j++){
            D[i][j] = ;
        }
    }

    int ans = 99999999;
    for(int i = 1; i <= n; i++){
        ans = min(ans,traveling_salesman(i,(1 << (n+1))-1)+dist[i][1]);
    }
    printf("%d\n",ans);

    return 0;
}
