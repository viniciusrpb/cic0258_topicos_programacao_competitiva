/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 * 
 * Tópico: Programação Dinâmica
 * Objetivo: Código-fonte que implementa o Algoritmo de Kadane - versão recursiva
 * Autor: Alberto Duarte
 * 
 * Compilar no terminal: g++ kadane.cpp -std=c++11 -o kdn
 * Executar: ./kdn
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX = (int)1e5;

bool vis[MAX][2];
int tab[MAX][2];
vi v;
int x;

int kadane(int i, bool m) {
    if(i == 0) {
        if(m == 0) return v[0];
        else if(m == 1) return x*v[0];
    }
    if(vis[i][m]) return tab[i][m];
    vis[i][m] = 1;

    // alguem nesse subarray que termina em i
    // tem que ta multiplicado
    if(m == 1) {
        int s1 = x*v[i];
        int s2 = x*v[i] + kadane(i-1, 0);
        int s3 = v[i] + kadane(i-1, 1);
    }

    // ninguem ta multiplicado
    else if(m == 0) {
        int res = max(v[i], kadane(i-1, 0) + v[i]);
    }
    
    return tab[i][m] = res;
}

            
int main() {
    // int n;
    // cin >> n;

    // v.assign(n, 0);
    // v = {-1, -1, 3, 4, 0};

    tab[0][0] = v[0]; // caso base
    tab[0][1] = x*v[0];


    for(int i = 1; i < n; i++) {
        // queremos calcular tab[i]
        // alguem nesse subarray que termina em i
        // tem que ta multiplicado
        if(m == 1) {
            int s1 = x*v[i];
            int s2 = x*v[i] + tab[i-1][0];
            int s3 = v[i] + tab[i-1][1];
        }
        
        // ninguem ta multiplicado
        else if(m == 0) {
            int res = max(v[i], tab[i-1][0] + v[i]);
        }    
    }
    

    return 0;
}
