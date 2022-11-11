/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 *
 * Tópico: Strings
 * Objetivo: Implementação de uma Trie
 *
 * Compilar no terminal: g++ trie.cpp -std=c++17 -o try
 * Executar: ./try
 */

#include<bits/stdc++.h>

using namespace std;

const int MAX_NODOS = 10005;
const int MAX_ALFABETO = 26;

int trie[MAX_NODOS][MAX_ALFABETO];

int nodos = 1;

void build(string s)
{
    int i;
    int current = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(trie[current][s[i]-'a'] == -1)
        {
            trie[current][s[i]-'a'] = nodos;
            current = trie[current][s[i]-'a'];
            nodos++;
        }
        else
        {
            current = trie[current][s[i]-'a'];
        }
    }
}

int main()
{
    int n;
    for(int i = 0; i < MAX_NODOS; i++)
    {
        for(int j = 0; j < MAX_ALFABETO; j++)
        {
            trie[i][j] = -1;
        }
    }
    
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        build(s);
    }
    
    for(int i = 0; i < nodos; i++)
    {
        for(int j = 0; j < MAX_ALFABETO; j++)
        {
            if(trie[i][j] > 0)
                printf("NODO atual: %d ALF: %c PROX: %d\n",i,j+'a',trie[i][j]);
        }
    }
    
    return 0;
}
