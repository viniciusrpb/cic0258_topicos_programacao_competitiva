/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 *
 * Tópico: Strings
 * Objetivo: Implementação da Edit Distance para determinar a menor quantidade
 * de operacoes para transformar uma string a em uma string b
 *
 * Compilar no terminal: g++ edit_distance.cpp -std=c++17 -o dist
 * Executar: ./dist
 * 
 * Complexidade: O(nm) para duas strings de comprimento n e M
 */

#include<bits/stdc++.h>
#define MAX 10005

using namespace std;

int dp[MAX][MAX];

int edit_distance_iter(string& s1, string& s2){
       
    int N = s1.size();
    int M = s2.size();
    
    for (int i = 0; i <= N; i++){        
        for (int j = 0; j <= M; j++){
            
            if(i == 0)
            dp[i][j] = j;
        else
            if(j == 0)
                dp[i][j] = i;
            else
                if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(min(dp[i][j - 1] + 1, dp[i - 1][j] + 1), dp[i - 1][j - 1]+1);
            
        }
    }
    return dp[N][M];
}

int edit_distance_rec(string& s1, string& s2, int a, int b){   
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
