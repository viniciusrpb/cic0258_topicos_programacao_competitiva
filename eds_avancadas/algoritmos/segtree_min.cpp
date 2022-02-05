/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 * 
 * Tópico: Estruturas de Dados Avançadas - Segment Tree
 * Objetivo: Implementar uma Segment Tree de Mínimos
 *           https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/B
 * 
 * Compilar no terminal: g++ classic_segtree_minimum.cpp -std=c++11 -o segtree_min
 * Executar: ./segtree_min
 */

#include<bits/stdc++.h>

using namespace std;

class SegTree{
    vector<int> st;
    vector<int> v;
    int n;
    int elem_neutro = 1e9+7;

public:
    SegTree(int size, vector<int> source): st(4*size,0), v(size,0)
    {
        n = size;
        for(int i = 0; i < size; i++)
            v[i] = source[i];
    }
    
    int f(int a, int b)
    {
        return min(a,b);
    }
    
    void build(int l, int r, int nodo)
    {
        if(l == r)
        {
            st[nodo] = v[l];
            return ;
        }
        
        int mid = (l+r)/2;
        
        build(l,mid,2*nodo);
        build(mid+1,r,2*nodo+1);
        
        st[nodo] = f(st[2*nodo],st[2*nodo+1]);
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
        
        st[nodo] = f(st[2*nodo],st[2*nodo+1]);
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
        int min_esq = query_range(ql,qr,l,mid,2*nodo);
        int min_dir = query_range(ql,qr,mid+1,r,2*nodo+1);
        return f(min_esq,min_dir); 
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
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&aux);
        arr.push_back(aux);
    }
    
    SegTree tree(n,arr);
      
    tree.build(0,n-1,1);
    
    for(int i = 0; i < q; i++)
    {
        scanf("%d %d %d",&op,&x,&y);
        
        if(op == 1)
            tree.update(x,y);
        else
            printf("%d\n",tree.query(x,y-1));
    }
    
    return 0;
}
