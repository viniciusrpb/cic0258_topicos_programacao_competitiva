/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 * 
 * Tópico: Grafos, Algoritmo de Kruskal for MST
 * Objetivo: Código-fonte da versão otimizada, complexidade no tempo O(n log n), n = num vertices do grafo
 * 
 * Compilar no terminal: g++ kruskal.cpp -std=c++17 -o krs
 * Executar: ./krs
 */

#include<bits/stdc++.h>

using namespace std;

typedef tuple<int,int,int> tii;
typedef pair<int,int> pii;
typedef long long ll;

vector<pii> g[200001];

class DSU{
    
    int n;
    vector<int> parent;
    vector<int> cardinality;
    
public:
    DSU(int num){
        n = num;
        parent.push_back(0);
        cardinality.push_back(0);
        for(int i = 1; i <= n; i++){
            parent.push_back(i);
            cardinality.push_back(1);
        }
    }
    
    int find_set(int x){
        if(x == parent[x])
            return x;
            
        parent[x] = find_set(parent[x]);
        return parent[x];
    }
        
    bool same_set(int a, int b){
        return find_set(a) == find_set(b);
    }
        
    void union_sets(int a, int b){
        int rep_a = find_set(a);
        int rep_b = find_set(b);
                
        if(rep_a != rep_b){
                
            if(cardinality[rep_a] > cardinality[rep_b]){
                parent[rep_b] = rep_a;
                cardinality[rep_a] += cardinality[rep_b];
            }else{
                parent[rep_a] = rep_b;
                cardinality[rep_b] += cardinality[rep_a];
            }
        }            
    }
};

int main(){
    int n,m,u,v,w;
    
    scanf("%d %d",&n,&m);
    
    DSU vertices(n);
    
    priority_queue<tii,vector<tii>,greater<tii>> pq_min;
    
    for(int i = 0; i < m; i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        pq_min.push({w,u,v});
    }
    
    int j = 1;
    ll cost = 0;
    vector<tii> mst;
    while(!pq_min.empty()){
        tie(w,u,v) = pq_min.top();
        pq_min.pop();
        if(!vertices.same_set(u,v)){
            mst.push_back({u,v,w});
            cost+=w;
            vertices.union_sets(u,v);
        }
        j++;
    }
    
    printf("%lld\n",cost);
    
    return 0;
}
