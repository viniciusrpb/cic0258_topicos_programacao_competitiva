/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 * 
 * Tópico: Programação Dinâmica
 * Objetivo: Código-fonte que implementa o problema do Troco Mínimo
 * 
 * Compilar no terminal: g++ problema_troco_minimo.cpp -std=c++11 -o exch
 * Executar: ./exch
 */

#include <bits/stdc++.h>

using namespace std;

int tabela[10005];

int n;
vector<int> valores;

int dp(int l){

    if(l == 0){
        return 0;
    }

    if(tabela[l] != -1)
        return tabela[l];

    int melhor = 1e9; 

    for(int i = 0; i < n; i++){
        if(valores[i] <= l)
            melhor = min(melhor,1 + dp(l - valores[i]));
    }
    
    return tabela[l] = melhor;
}

int main()
{
    memset(tabela,-1,sizeof(tabela));
    int aux;
    
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&aux);
        valores.push_back(aux);
    }
        
    printf("%d\n",dp(n-1));
    
    return 0;
}
