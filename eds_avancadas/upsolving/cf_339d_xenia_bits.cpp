/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 * 
 * Tópico: Estruturas de Dados Avançadas - Segment Tree
 * Objetivo: Solução do problema no Codeforces #197 (Div. 2) - D. Xenia and Bit Operations
 *           https://codeforces.com/problemset/problem/339/D
 * 
 * Compilar no terminal: g++ cf_339d_xenia_bits.cpp -std=c++11 -o xenia.cpp
 * Executar: ./xenia
 */

#include<bits/stdc++.h>

using namespace std;

class SegTree{
    vector<int> st;
    vector<int> v;
    vector<bool> bitwise;
    int n;
    int elem_neutro = 1e9+7;

public:
    SegTree(int size, vector<int> source): st(4*size,0), v(size,0), bitwise(4*size,false)
    {
        n = size;
        for(int i = 0; i < size; i++)
            v[i] = source[i];
    }
    
    int getRoot()
    {
        return st[1];
    }
    
    int f(int a, int b, bool op)
    {
        if(op == false)
            return a^b;
        else
            return a|b;
    }
    
    void build(int l, int r, int nodo)
    {
        if(l == r)
        {
            st[nodo] = v[l];
            bitwise[nodo] = false;
            return ;
        }
        
        int mid = (l+r)/2;
        
        build(l,mid,2*nodo);
        build(mid+1,r,2*nodo+1);
        
        bitwise[nodo] = !bitwise[2*nodo];
        st[nodo] = f(st[2*nodo],st[2*nodo+1],bitwise[nodo]);
    }
    
    void update_range(int i, int value, int l, int r, int nodo)
    {
        if(l == r)
        {
            st[nodo] = value;
            return ;
        }
        
        int mid = (l+r)/2;
        if(i <= mid)
            update_range(i, value, l, mid, 2*nodo);
        else
            update_range(i, value, mid+1, r, 2*nodo+1);
        
        st[nodo] = f(st[2*nodo],st[2*nodo+1],bitwise[nodo]);
    }

    void update(int i, int x)
    {
        int l = 0;
        int r = n-1;
        int nodo = 1;
        update_range(i,x,l,r,nodo);
    }

    int query_range(int ql, int qr, int l, int r, int nodo)
    {
        
        if(l > qr or r < ql)
        {
            return elem_neutro;
        }
        
        if(l >= ql and r <= qr)
        {
            return st[nodo];
        }
        
        int mid = (l+r)/2;
        int bits_esq = query_range(ql,qr,l,mid,2*nodo);
        int bits_dir = query_range(ql,qr,mid+1,r,2*nodo+1);
        return f(bits_esq,bits_dir,bitwise[nodo]); 
    }

    int query(int ql, int qr)
    {
        int l = 0;
        int r = n-1;
        int nodo = 1;
        return query_range(ql,qr,l,r,nodo);
    }
};


int main(){
    
    int n,q,aux,op,x,y;
    vector<int> arr;
    
    scanf("%d %d",&n,&q);
    
    int tam = 1 << n;
    
    for(int i = 0; i < tam; i++)
    {
        scanf("%d",&aux);
        arr.push_back(aux);
    }
    
    SegTree tree(tam,arr);
      
    tree.build(0,tam-1,1);
    
    for(int i = 0; i < q; i++)
    {
        scanf("%d %d",&x,&y);
        tree.update(x-1,y);
        printf("%d\n",tree.getRoot());
    }
    
    return 0;
}
