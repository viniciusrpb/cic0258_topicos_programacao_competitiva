/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 * 
 * Tópico: Estruturas de Dados Avançadas - Union-find Disjoint Sets
 * Objetivo: Solução do problema no Codeforces #170 (Div. 1) - A. Learning Languages
 * 
 * Compilar no terminal: g++ cf_277a_learning_languages.cpp -std=c++11 -o dsu
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

    int find_set(int x)
    {
        while(x != parent[x])
            x = parent[x];
        return x;
    }

    bool same_set(int a, int b)
    {
        return find_set(a) == find_set(b);
    }

    int find_set2(int x)
    {
        if(x == parent[x])
            return x;
        
        return parent[x] = find_set2(parent[x]);
    }

    int connectedComponents(int n)
    {
        set<int> s;
        
        for(int i = 1; i <= n; i++)
            s.insert(find_set(parent[i]));
        
        return s.size();
    }

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
    
    int n,m,l,k,ans,none;
    
    scanf("%d %d",&n,&m);
    
    DSU conj(n);
    vector<int> lang[m+1],representante(m+1,0);
    
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&k);
        for(int j = 0; j < k; j++)
        {
            scanf("%d",&l);
            lang[l].push_back(i);
            if(!representante[l])
                representante[l] = i;
        }
    }
    
    none = 0;
    
    for(int l = 1; l <=m; l++)
    {
        if(lang[l].size())
        {
            for(int i = 0; i < lang[l].size();i++)
            {
                if(not conj.same_set(representante[l],lang[l][i]))
                    conj.join_sets(representante[l],lang[l][i]);
            }
        }
        else
            none++;
    }
    
    if(none == m)
        ans = n;
    else
        ans = conj.connectedComponents(n)-1;
    
    printf("%d\n",ans);

    return 0;
}
