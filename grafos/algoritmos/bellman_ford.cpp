/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 *
 * Tópico: Grafos
 * Objetivo: Código-fonte que implementa o algoritmo de Bellman Ford
 *
 * Compilar no terminal: g++ bellman_ford.cpp -std=c++17 -o shortpath
 * Executar: ./shortpath
 *
 * Vértices são representados por inteiros de 1 a N.
 *
 * Complexidade: O(N x M) para um grafo representado por lista de adjacências com N vértices e M arestas
 *
 * Exemplo de input:
   5 6
   2 5 4
   3 4 2
   1 2 3
   3 1 2
   2 3 1
   4 5 6
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,int> pli; // tipo p/ fila de prioridade min
typedef pair<int,ll> pil; // tipo p/ o grafo

const ll oo = 4e18; // + infinito

int n,m; // numero de vertices, numero de arestas
vector<ll> d(100001,oo);
vector<vector<pil>> g(100001);

bool bellman_ford(int start){
    int u,v;
    ll w;

    d[start] = 0;

    for(int i = 1; i < n; i++){
        for(u = 1; u <= n; u++){
            // u ---> w ---> v
            for(pil elem : g[u]){
                tie(v,w) = elem;
                if (d[u] != oo and d[u] + w < d[v])
                    d[v] = d[u] + w;
            }
        }
    }

    for(u = 1; u <= n; u++){
        for(pil elem : g[u]){
            tie(v,w) = elem;
            if (d[u] != oo and d[u] + w < d[v])
                return true;
        }
    }

    return false;
}

int main(){

    int u,v,w;
    scanf("%d %d",&n,&m);

    for(int i = 0; i < m; i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        //g[v].push_back({u,w}); // grafo nao direcionado
    }

    bool negative_cycle = bellman_ford(1);

    if(negative_cycle)
        printf("Grafo contem ciclo negativo\n");
    else{
        for(int i = 1; i <= n; i++){
            printf("%lld ",d[i]);
        }
    }




    return 0;
}

