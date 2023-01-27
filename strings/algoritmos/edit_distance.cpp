/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 *
 * Tópico: Strings
 * Objetivo: Implementação do Algoritmo Z para encontrar a maior substring que eh um prefixo
 *           da string de entrada
 *
 * Compilar no terminal: g++ z_algorithm.cpp -std=c++17 -o zfunc
 * Executar: ./zfunc
 */

#include<bits/stdc++.h>
#define MAX 10005

using namespace std;

int dp[MAX][MAX];

int edit_distance_iter(string s1, string s2){
    
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = 0;
    int c;
    
    int N = s1.size();
    int M = s2.size();
    
    for (int i = 1; i <= N; i++){
        dp[i][0] = i;
        
        for (int j = 1; j <= M; j++){
            dp[0][j] = j;
            
            c=1;
            if (s1[i - 1] == s2[i - 1])
                c = 0;
            
            dp[i][j] = min(min(dp[i][j - 1] + 1, dp[i - 1][j] + 1), dp[i - 1][j - 1]+c);
            
        }
    }

    return dp[N][M];
}

int edit_distance_rec(string s1, string s2, int a, int b){   
    if (a == 0 || b == 0){
        dp[a][b] = max(a, b);
        return max(a, b);
    }
        
    if (dp[a][b] != -1)
        return dp[a][b];
    
    int custo = 1;
    
    int parte1 = edit_distance_rec(s1, s2, a, b-1)+custo;
    int parte2 = edit_distance_rec(s1, s2, a-1, b)+custo;

    if (s1[a-1] == s2[b-1])
        custo--;
    
    int parte3 = edit_distance_rec(s1, s2, a-1, b-1)+custo;
        
    dp[a][b] = min(min(parte1, parte2), parte3);
            
    return dp[a][b];
}

int main(){
    
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            dp[i][j] = -1;
        }
    }
    
    printf("%d\n",edit_distance_rec("cape", "gap",4,3));
    
    for(int i = 0; i <= 4; i++){
        for(int j = 0; j <= 5; j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            dp[i][j] = -1;
        }
    }
    
    printf("%d\n",edit_distance_iter("gap", "cape"));
    
    return 0;
}
