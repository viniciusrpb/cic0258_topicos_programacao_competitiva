#include<bits/stdc++.h>
 
using namespace std;
 
vector<bool> ehPrimo(1002,true);
 
vector<int> crivo(int n)
{
    vector<int> primos;
    
    primos.push_back(2);
    ehPrimo[0] = false;
    ehPrimo[1] = false;
    
    for(int x = 3; x <=n; x=x+2)
    {
        ehPrimo[x+1] = false;
        if(ehPrimo[x])
        {
            primos.push_back(x);
            for(int m = x+x; m <=n; m=m+x)
            {
                ehPrimo[m]=false;
            }
        }
    }
    return primos;
}
 
int main()
{
    int n,k,ans,num3;
    
    scanf("%d %d",&n,&k);
    vector<int> primos;
    
    primos = crivo(1002);
    
    ans = 0;
    for(int i = 2; primos[i-1] < n/2; i++)
    {
        num3 = primos[i-1] + primos[i] + 1;
        if(ehPrimo[num3] == true)
        {
            ans++;
        }
    }
    
    if(ans >= k)
        printf("YES\n");
    else
        printf("NO\n");
    
    return 0;
}
