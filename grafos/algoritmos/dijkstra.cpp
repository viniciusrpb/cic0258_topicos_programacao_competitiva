/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 *
 * Tópico: Grafos
 * Objetivo: Código-fonte que implementa o algoritmo de Dijsktra
 *
 * Compilar no terminal: g++ dijkstra.cpp -std=c++17 -o shortpath
 * Executar: ./shortpath
 *
 * Vértices são representados por inteiros de 1 a N.
 *
 * Complexidade: O( (|M| + |N|) + log|N|) para um grafo representado por lista de adjacências com N vértices e M arestas
 *
 * Exemplo de input:
   5 6
   1 2 2
   2 5 5
   2 3 4
   1 4 1
   4 3 3
   3 5 1
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,int> pli; // tipo p/ fila de prioridade min
typedef pair<int,ll> pil; // tipo p/ o grafo

const ll oo = 4e18; // + infinito

int n,m; // numero de vertices, numero de arestas
vector<ll> d(100001,oo);
vector<int> predecessor(100001,-1);
vector<vector<pil>> g(100001);

void dijkstra(int s){
    int u,v;
    ll mindist_su,w;

    priority_queue<pli,vector<pli>,greater<pli>> pq;

    for(u = 1; u <= n; u++)
        d[u] = oo;

    d[s] = 0;
    predecessor[s] = s;
    pq.push({d[s],s});

    while(!pq.empty()){
        //pega o primeiro nodo da fila
        tie(mindist_su,u) = pq.top();
        pq.pop();

        if(mindist_su > d[u])
            continue; /// ignora

        for(auto edge : g[u]){
            tie(v,w) = edge; // peso w para chegar de u ateh v
            if(d[v] > d[u] + w){
                d[v] = d[u]+w;  // relaxamento
                predecessor[v] = u;
                pq.push({d[v],v});
            }
        }
    }
}

int main(){

    int u,v,w;
    scanf("%d %d",&n,&m);

    for(int i = 0; i < m; i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        //g[v].push_back({u,w}); // grafo nao direcionado
    }

    int start = 1;

    dijkstra(start);

    for(int i = 1; i <= n; i++){
        printf("%lld ",d[i]);
    }
    printf("\n");

    for(int i = 1; i <= n; i++){
        printf("%d ",predecessor[i]);
    }
    printf("\n");

    return 0;
}
