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
typedef pair<int,int> pii;
typedef pair<ll,int> plli;
typedef pair<int,ll> pill;

const int N = 100002;
const ll oo = 1e18;

ll d[N];
int predecessor[N];
int n;

vector<vector<pill>> g(N);

void dijkstra(int s){

    ll dist_su,w;
    int u,v;

    for(int i = 1; i <=n;i++)
        d[i] = oo;

    priority_queue<plli,vector<plli>,greater<plli>> pq;

    d[s] = 0;
    predecessor[s] = s;

    pq.push(make_pair(d[s],s));

    while(!pq.empty())    {
        tie(dist_su,u) = pq.top();
        pq.pop();

        //skip
        if(dist_su > d[u])
            continue;

        for(auto aresta : g[u]){
            tie(v,w) = aresta;

            if(d[v] > d[u] + w)
            {
                d[v] = d[u]+w;
                predecessor[v] = u;
                pq.push(make_pair(d[v],v));
            }
        }
    }
}

int main()
{
    int m,a,b,w;

    scanf("%d %d",&n,&m);

    for(int e = 0; e < m; e++)
    {
        scanf("%d %d %d",&a,&b,&w);
        g[a].push_back(make_pair(b,w));
        g[b].push_back(make_pair(a,w));
    }

    int start = 1;

    dijkstra(start);

    if(d[n] < oo){

        list<int> l;
        l.push_front(n);
        b = predecessor[n];

        while(b != start){
            l.push_front(b);
            b = predecessor[b];
        }

        l.push_front(b);

        while(l.size()){
            b = l.front();
            l.pop_front();
            printf("%d ",b);
        }
        printf("\n");
    }
    else
        printf("-1\n");

    return 0;
}
