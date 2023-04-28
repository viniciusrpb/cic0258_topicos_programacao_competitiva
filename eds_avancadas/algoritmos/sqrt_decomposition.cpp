/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 *
 * Tópico: Estruturas de Dados Avançadas - SQRT Decomposition
 * Objetivo: Código-fonte da versão tradicional, complexidade no tempo O(sqrt(n))
 *
 * Compilar no terminal: g++ sqrt_decomposition.cpp -std=c++17 -o sqrt
 * Executar: ./sqrt
 */

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int BLOCK_SIZE;
const int MAX = 100001;

vector<int> v;
vector<ll> soma_bloco(MAX,0);

void constroi_bloco(int idx){

    int p;

    soma_bloco[idx] = 0;

    p = min((idx+1)*BLOCK_SIZE, n);

    for(int i = idx * BLOCK_SIZE; i < p; i++){
        soma_bloco[idx] += v[i];
    }
}

ll query(int l, int r){

    ll ans = 0;

    int idl = l/BLOCK_SIZE, idr = r/BLOCK_SIZE;

    if(idl == idr){

        for(int i = l; i <= r; i++)
            ans += v[i];

        return ans;
    }

    for(int i = l; i < (idl+1)*BLOCK_SIZE; i++)
        ans += v[i];

    for(int i = idl+1; i < idr; i++)
        ans += soma_bloco[i];

    for(int i = idr*BLOCK_SIZE; i <= r; i++)
        ans += v[i];

    return ans;
}

int main(){

    int l,r,q,x,idx,aux,tipo;

    scanf("%d %d",&n,&q);

    BLOCK_SIZE = sqrt(n);

    for(int i = 0; i < n; i++){
        scanf("%d",&aux);
        v.push_back(aux);
        soma_bloco.push_back(0);
    }

    /* tipo 0: update ;  tipo 1: consulta */
    for(int i = 0; i < q; i++){

        scanf("%d",&tipo);

        if(!tipo){

            scanf("%d %d",&idx,&x);
            v[idx] = x;
            constroi_bloco(idx / BLOCK_SIZE);

        }else{

            scanf("%d %d",&l,&r);

            ll ans = query(l,r);

            printf("%lld\n",ans);
        }
    }

    return 0;
}
