/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0xxx - Tópicos Especiais em Programação Competitiva
 * Prof. Dr. Vinicius R. P. Borges
 * 
 * Tópico: Geometria Computacional, Sweep Line
 * Objetivo: Implementação do Algoritmo para Encontrar a Distância (Euclidiana) Mínima entre Pares de Pontos
 * 
 * Compilar no terminal: g++ mindist_sweepline.cpp -std=c++11 -o mindist
 * Executar: ./mindist
 */

#include<bits/stdc++.h>

using namespace std;

typedef pair<double,double> pdd;

typedef struct point Point2D;

const double EPS = 1e-18;

struct point
{
    double x;
    double y;
    
    bool operator<(Point2D p)
    {
        return x < p.x || (fabs(x - p.x) < EPS && y < p.y);
    }
};

double mindist_sweepline(vector<Point2D>& points)
{
    int n = points.size();
    sort(points.begin(),points.end());
    
    set<pdd> conj;
    
    double ans = 1e18;
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        double d = ceil(sqrt(ans));
        
        while(j < n && points[i].x - points[j].x >= d)
        {
            conj.erase({points[j].y,points[j].x});
            j++;
        }
        
        auto it_lower = conj.lower_bound({points[i].y-d,points[i].x});
        auto it_up = conj.upper_bound({points[i].y+d,points[i].x});
        
        for(auto it = it_lower; it != it_up; it++)
        {
            double dx = points[i].x - it->second;
            double dy = points[i].y - it->first;
            ans = min(ans,dx*dx + dy*dy);
        }
        
        conj.insert({points[i].y,points[i].x});
    }
    return sqrt(ans);
}

int main()
{
    int n;
    double x,y;
    vector<Point2D> points;
    
    /*scanf("%d",&n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%lf %lf",&x,&y);
        points({x,y});
    }*/
    
    n=5;
    points.push_back({-2, -1});
    points.push_back({0, 3});
    points.push_back({1, -2});
    points.push_back({3, 4});
    points.push_back({4, 2});
    
    double ans = mindist_sweepline(points);
    
    printf("Minimum distance: %lf\n",ans);
    
    return 0;
}
