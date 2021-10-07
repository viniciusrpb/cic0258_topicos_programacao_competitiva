/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0xxx - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 * 
 * Tópico: Geometria Computacional, Fecho Convexo (Convex Hull)
 * Objetivo: Implementação do Algoritmo Cadeia Monótona de Andrews
 * 
 * Compilar no terminal: g++ andrews_monotone_chain.cpp -std=c++11 -o convexhull
 * Executar: ./convexhull
 */

#include<bits/stdc++.h>

using namespace std;

typedef struct point Point2D;

struct point
{
    double x;
    double y;
    
    bool operator<(Point2D p)
    {
        return x < p.x || (x == p.x && y < p.y);
    }
};

// v=pq comparar p/ determinar se r estah a esq, direita ou col em relacao a v
double prod_vetorial(Point2D p, Point2D q, Point2D r)
{
    return (p.x-r.x)*(q.y-r.y) - (p.y-r.y)*(q.x-r.x);
}

vector<Point2D> andrews_convexhull(vector<Point2D> points)
{
    int tam_lower,tam_upper;
    sort(points.begin(),points.end());
    int n = points.size();
    
    vector<Point2D> lower,upper;
    
    // pega ponto por ponto ordenado crescente em rel. ao eixo x
    for(int i = 0; i < n; i++)
    {
        tam_lower = lower.size();
        
        while(tam_lower >= 2 && prod_vetorial(lower[tam_lower-2],lower[tam_lower-1],points[i]) <= 0)
        {
            lower.pop_back();
            tam_lower--;
        }
        lower.push_back(points[i]);
    }
    // lower hull
    
    reverse(points.begin(),points.end());
    
    // upper hull
    for(int i = 0; i < n; i++)
    {
        tam_upper = upper.size();
        
        while(tam_upper >= 2 && prod_vetorial(upper[tam_upper-2],upper[tam_upper-1],points[i]) <= 0)
        {
            upper.pop_back();
            tam_upper--;
        }
        upper.push_back(points[i]);
    }
    
    lower.pop_back();
    lower.insert(lower.end(),upper.begin(),upper.end());
    return lower;
}


int main()
{
    vector<Point2D> point_cloud;
    
    point_cloud.push_back({0,4});
    point_cloud.push_back({2,2});
    point_cloud.push_back({1,1});
    point_cloud.push_back({1,3});
    point_cloud.push_back({3,2});
    point_cloud.push_back({4,0});
    point_cloud.push_back({4,4});
    point_cloud.push_back({0,0});

    vector<Point2D> ans = andrews_convexhull(point_cloud);
    
    for(int i = 0; i < ans.size(); i++)
    {
        printf("(%lf,%lf)\n",ans[i].x,ans[i].y);
    }
    
    return 0;
}
