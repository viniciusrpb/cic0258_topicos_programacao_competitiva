/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0258 - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 * 
 * Tópico: Geometria Computacional, Fecho Convexo (Convex Hull)
 * Objetivo: Implementação do Algoritmo Cadeia Monótona de Andrews
 * 
 * Compilar no terminal: g++ andrews_monotone_chain.cpp -std=c++17 -o convexhull
 * Executar: ./convexhull
 */

#include<bits/stdc++.h>
 
using namespace std;

typedef long long ll;
 
typedef struct point Point2D;
 
struct point{
    double x;
    double y;
    
    bool operator<(Point2D p){
        return x < p.x || (x == p.x && y < p.y);
    }
};
 
// verifica se o ponto r estah a esq, direita ou col em relacao ao vetor u = (q-p)
double cross(Point2D p, Point2D q, Point2D r){
    double rx = r.x-p.x;
    double ry = r.y-p.y;
    
    double ux = q.x-p.x;
    double uy = q.y-p.y;
    
    return rx*uy - ry*ux;
}
 
vector<Point2D> andrews_convexhull(vector<Point2D> points){
    
    vector<Point2D> hull;
    int tam_upper;
    int n = points.size();
    
    // ordena crescente em relacao ao eixo x
    sort(points.begin(),points.end());
    
    // pega ponto por ponto ordenado crescente em rel. ao eixo x
    for(int i = 0; i < n; i++){
        while((int) hull.size() >= 2){
            double pv = cross(hull[(int) hull.size()-2],hull[(int) hull.size()-1],points[i]);
            if(pv <= 0)
                break;
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    
    reverse(points.begin(),points.end());
    hull.pop_back();
    tam_upper = hull.size();
    
    // lower hull
    for(int i = 0; i < n; i++){       
        while(hull.size() - tam_upper >= 2){
            double pv = cross(hull[(int) hull.size()-2],hull[(int) hull.size()-1],points[i]);
            if(pv <= 0)
                break;
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    hull.pop_back();
    return hull;
}

int main(){
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
    
    for(int i = 0; i < ans.size(); i++){
        printf("%lld %lld\n", (ll) ans[i].x, (ll) ans[i].y);
    }
    
    return 0;
}
