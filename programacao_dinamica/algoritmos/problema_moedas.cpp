/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 * 
 * Tópico: Programação Dinâmica
 * Objetivo: Código-fonte que implementa o problema das Moedas
 * 
 * Compilar no terminal: g++ problema_moedas.cpp -std=c++11 -o coins
 * Executar: ./coins
 */

#include <bits/stdc++.h>

using namespace std;

int tb[1005];

int n;
vector<int> moedas;

int dp(int i)
{
    if(i >= n)
        return 0;
    
    if(tb[i] != -1)
        return tb[i];

    tb[i] = max(dp(i+1), dp(i+2) + moedas[i]);
    return tb[i];
}

int main()
{
    memset(tb,-1,sizeof(tb));
    int aux;
    
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&aux);
        moedas.push_back(aux);
    }
        
    printf("%d\n",dp(0));
    
    return 0;
}
