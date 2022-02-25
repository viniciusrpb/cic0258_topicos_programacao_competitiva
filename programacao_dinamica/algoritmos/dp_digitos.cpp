/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 * 
 * Tópico: Programação Dinâmica
 * Objetivo: Código-fonte que implementa uma DP de Dígitos - versão recursiva
 * Autor: Alberto Duarte
 * 
 * Compilar no terminal: g++ dp_digitos.cpp -std=c++11 -o dig
 * Executar: ./dig
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX = (int)1e5;

string r;

int dp(int i, bool menor, int dnn) {
    if(i >= (int)r.size()) return 1;
    if(dnn > 3) return 0;
    
    int dr = r[i]-'0';
    int res = 0;

    for(int d = 0; d <= 9; d++) {
        int dnn2 = dnn + (d > 0);
        if(menor == true) {
            res += dp(i+1, true, dnn2);
        }
        else if(d < dr) {
            res += dp(i+1, true, dnn2);
        }
        else if(d == dr) {
            res += dp(i+1, false, dnn2);
        }
        
        // if(menor == true or d <= dr) {
        //     bool menor2 = (menor) or (d < dr);
        //     int dnn2 = dnn + (d > 0);

        //     res += dp(i+1, menor2, dnn2);
        // }
    }    
    return res;
}

            
int main() {

    return 0;
}
