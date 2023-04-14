/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 * 
 * Tópico: Estruturas de Dados Avançadas - Binary Indexed Tree - BIT (Fenwick Tree)
 * Objetivo: Código-fonte com complexidade O(log n) para consultas e atualizações
 *                                         O(n) para construcao
 * 
 * Compilar no terminal: g++ bit.cpp -std=c++17 -o fenwick
 * Executar: ./fenwick
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

class BIT {
    vector<ll> bit;
    int n;

    ll get1_LSB(ll i){
        return i & (-i);
    }
    
public:
    
    BIT(int tam): bit(tam+1,0){ // desconsidera o indice zero
        n = tam;
    }
    
    BIT(vector<int> a): bit(a.size()+1){ // desconsidera o indice zero
        n = a.size();
        bit[0]=0;
        for(int i = 1; i <= n; i++){
            bit[i] += a[i-1];
            int flip_next = i | (i+1);
            if(flip_next < n)
                bit[flip_next] += bit[i];
        }
    }

    ll sum(int i){
        ll s = 0;
        
        while (i >= 1){
            s += bit[i];
            i += get1_LSB(i);
        }
        
        return s;
    }
    
    ll range_sum(int l, int r){
        return sum(r)-sum(l-1);
    }

    void add(int i, int x){
        if(i == 0)
            return ;
        
        while(i <= n){
            bit[i] += x;
            i += get1_LSB(i);
        }
    }
};

int main(){

    // Cria 5 conjuntos contendo 1 elemento cada: {1}, {2}, {3}, {4} e {5}
    vector<int> arr = {1,2,3,4,5,6,7,8};

    BIT tree(arr);
    
    printf("Consulta soma entre [0,3] = %lld\n",tree.range_sum(0,3));
    
    printf("Consulta soma entre [2,5] = %lld\n",tree.range_sum(2,5));
    
    printf("Adiciona 1\n");
    tree.add(2,4);
    
    printf("Consulta soma entre [2,5] = %lld\n",tree.range_sum(2,5));

    return 0;
}
