/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 *
 * Aula: Programacao Dinamica (Problema do Caixeiro Viajante) - Travelling Salesman Problem
 *
 * Complexidade: O(n 2^n)
 *
 * Compilar: g++ travelling_salesman.cpp -std=c++17 -o caixeiro
 * Executar: ./caixeiro
 */

#include<bits/stdc++.h>
#define oo 2e9
#define MAX 100000

using namespace std;

typedef long long ll;

int n=4;

int dist[5][5] = {
    { 0, 0, 0, 0, 0 },    { 0, 0, 10, 15, 20 },
    { 0, 10, 0, 25, 25 }, { 0, 15, 25, 0, 30 },
    { 0, 20, 25, 30, 0 },
};

ll tab[7][MAX+2];

int travelling_salesman(int current_city, int bitmask){

    int next_city,ans = oo;
    
    //printf("current_city %d bitmask %d\n",current_city,bitmask);
    
    if (bitmask == ((1 << current_city) | 3))
        return dist[1][current_city];
        
    if (tab[current_city][bitmask] != 0)
        return tab[current_city][bitmask];

    for(int i = 1; i <= n; i++){
        if( (bitmask & (1<<i)) and i != current_city and i != 1){
            next_city = travelling_salesman(i, bitmask & (~(1<<current_city)));
            ans = min(ans,next_city+dist[i][current_city]);
        }
    }
    
    tab[current_city][bitmask] = ans;
    return ans;
}

int main(){

    // grafo com n vertices
    //scanf("%d %d",&n,&m);

    for(int i = 0; i < 7;i++){
        for(int j = 0; j <= MAX; j++){
            tab[i][j] = 0;
        }
    }

    // Calcula a matriz de distancias
    /*for(int i = 1; i <= n;i++){
        for(int j = 1; j <= n; j++){
            D[i][j] = ;
        }
    }*/

    int ans = oo;
    for(int i = 1; i <= n; i++){
        ans = min(ans,travelling_salesman(i,(1 << (n+1))-1)+dist[i][1]);
    }
    printf("%d\n",ans);

    return 0;
}
