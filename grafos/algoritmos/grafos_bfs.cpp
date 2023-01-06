/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 *
 * Tópico: Grafos (Busca)
 * Objetivo: Código-fonte que implementa uma busca em Largura (BFS) em um grafo
 *
 * Compilar no terminal: g++ grafos_bfs.cpp -std=c++17 -o bfs
 * Executar: ./bfs
 *
 * Vértices são representados por inteiros de 1 a N.
 *
 * Complexidade: O(|M| + |N|) para um grafo representado por lista de adjacências com N vértices e M arestas
 *
 * Exemplo de input:
   6 6
   1 2
   2 4
   4 6
   1 3
   3 5
   5 6
 */

#include<bits/stdc++.h>
#define MAX 100

using namespace std;

vector<vector<int>> g(MAX);
vector<bool> visited(MAX,false);

/* breadth first search: busca em largura */
void bfs(int start){

    vector<bool> visitado(11,false);
    queue<int> fila;

    fila.push(start);
    visitado[start] = true;

    while(fila.size()){
        int u = fila.front();
        fila.pop();

        printf("%d ",u+1);

        for(int v : g[u]){
            if(visitado[v] == false){
                fila.push(v);
                visitado[v] = true;
            }
        }
    }
}

int main(){

    int n,e,u,v;

    scanf("%d %d",&n,&e);

    for(int i = 0; i < e; i++){
        scanf("%d %d",&u,&v);
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0; i < n; i++){
        printf("%d: ",i+1);
        for(int j = 0; j < g[i].size(); j++)        {
            printf("=> %d ",g[i][j]+1);
        }
        printf("\n");
    }
    printf("\n");

    printf("BFS: ");
    bfs(0);
    printf("\n");

    return 0;
}
