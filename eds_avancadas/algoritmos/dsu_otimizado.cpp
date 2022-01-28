/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 * 
 * Tópico: Estruturas de Dados Avançadas - Union-find Disjoint Sets
 * Objetivo: Código-fonte da versão otimizada, complexidade no tempo O(log n)
 * 
 * Compilar no terminal: g++ dsu_otimizado.cpp -std=c++11 -o dsu
 * Executar: ./dsu
 */

#include<bits/stdc++.h>

using namespace std;

class DSU
{
    vector<int> parent;
    vector<int> card;
    
public:
    DSU(int n): parent(n+1), card(n+1,1)
    {
        for(int i = 1; i <= n; i++)
            parent[i] = i;
    }

    /* O(log n) */
    int find_set(int x)
    {
        if(x == parent[x])
            return x;
        
        return parent[x] = find_set(parent[x]);
    }

    bool same_set(int a, int b)
    {
        return find_set(a) == find_set(b);
    }

    /* O(log n) */
    void join_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        
        if(card[a] < card[b])
            swap(a,b);
        
        card[a] += card[b];
        parent[b] = a;
    }
};

int main(){

    // Cria 5 conjuntos contendo 1 elemento cada: {1}, {2}, {3}, {4} e {5}
    DSU conj(5);
    
    conj.join_sets(2,3);
    conj.join_sets(1,3);
    
    if(conj.same_set(1,2))
        printf("1 e 2 estão no mesmo conjunto.\n");
    else
        printf("1 e 2 NÃO estão no mesmo conjunto.\n");
    
    conj.join_sets(5,4);
    
    if(conj.same_set(2,4))
        printf("2 e 4 estão no mesmo conjunto.\n");
    else
        printf("2 e 4 NÃO estão no mesmo conjunto.\n");
    
    printf("Representante do conjunto que contém 4: %d\n",conj.find_set(4));
    
    printf("Representante do conjunto que contém 2: %d\n",conj.find_set(2));
    
    printf("Representante do conjunto que contém 1: %d\n",conj.find_set(1));

    return 0;
}
