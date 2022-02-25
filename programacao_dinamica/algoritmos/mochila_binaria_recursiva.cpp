/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 * 
 * Tópico: Programação Dinâmica
 * Objetivo: Código-fonte que resolve o Problema da Mochila Binária - versão recursiva
 * Autor: Alberto Duarte
 * 
 * Compilar no terminal: g++ mochila_binaria_recursiva.cpp -std=c++11 -o knapsack
 * Executar: ./knapsack
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX = (int)1e5;
const int INF = (int)1e9;

string r;
int tab[20][2][4];

// (20 * 2 * 4) * 10

// n itens 
// valor = {}
// peso = {}

int dp(int i, int capacidade){
    if(i >= n) return 0;
    if(capacidade < 0) return -INF;
    if(tab[i][capacidade] != -1) return tab[i][capacidade];
    int pega = 0;
    int npega = 0;
    
    // pega
    pega = valor[i] + dp(i+1, capacidade-peso[i]);

    // npega
    npega = dp(i+1, capacidade);

    return tab[i][capacidade] = max(pega, npega);
}

int main() {

    

    return 0;
}
