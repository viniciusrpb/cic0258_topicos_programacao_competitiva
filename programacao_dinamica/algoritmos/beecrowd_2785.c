/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 * 
 * Tópico: Programação Dinâmica
 * Problema: beecrowd 2785 - Pirâmide
 * 
 * Compilar no terminal: gcc beecrowd_2785.c -o caixas
 * Executar: ./caixas
 */

#include<stdio.h>

int min(int a, int b){
    if(a < b){
        return a;
    } else {
        return b;
    } 
}

int main(){
    
    int i,j,n,k,soma,limite;
    int piramide[102][102], peso[102][102];
    
    scanf("%d",&n);
    
    /* padding das matrizes e inicializacao */
    for(i = 0; i < 102; i++){    
        for(j = 0; j < 102; j++){
            piramide[i][j] = 0;
            peso[i][j] = 0;
        }
    }
    
    /* peso[i][j] guarda a menor soma possível do peso de uma pirâmide com base na linha i, com inicio na coluna j */
    
    for(i = 1; i <= n; i++){    
        for(j = 1; j <= n; j++){
            scanf("%d",&piramide[i][j]);
        }
    }
    
    /* assim, devemos copiar os pesos da piramide na linha 1 para os pesos totais */
    for(j = 1; j <= n; j++){
        peso[1][j] = piramide[1][j];
    }
    
    /* passa por cada linha da piramide, começando da linha 2 */
    for(i = 2; i <= n; i++){
        
        /* cada linha que desce na matriz, desconta-se uma coluna a ser analisada */
        limite = n - i + 1;
        
        /* para cada coluna, determina a soma de i caixas consecutivas */
        for(j = 1; j <= limite; j++){
            
            soma = 0;
            
            /* soma i caixas adjacentes da matriz na linha i,
             partindo-se da coluna k 
             p.ex, se k =1, soma-se os pesos das caixas das colunas j, j+1,j+2,..,j+i*/
            for(k = 0; k < i; k++){
                soma += piramide[i][j+k];
            }
            
            /* soma os pesos das caixas da linha atual, comecando da coluna j e contando i caixas consecutidas, com o menor valor dentre:
             * - peso das caixas da linha anterior a partir da coluna j, OU
             * - peso das caixas da linha anterior a partir da coluna j+1 em diante */
            peso[i][j] = soma + min(peso[i-1][j], peso[i-1][j+1]);
        }
    }

    /* na piramide com n niveis, a resposta esta armazenada considerando as caixas
     consecutivas a partir da coluna 1 */
    printf("%d\n",peso[n][1]);
  
    return 0;
}
