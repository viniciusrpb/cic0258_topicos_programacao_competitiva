#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAX = 1e6 + 1;

int n, duration[1000001];
double dp[1000001], cost[1000001];

int main() {

    int d;
    double ans;
    scanf("%d",&n);

    for(int i = 1; i <= n; i++){
        scanf("%d %lf",duration+i, cost+i);
        dp[i] = 1e15;
    }
    
    for(int i = 1; i <= n; i++) {
        
        dp[i] = min(dp[i], dp[i - 1] + cost[i]);
        
        d = duration[i];
        
        if(d < 120)
            dp[i + 1] = min(dp[i + 1], dp[i - 1] + cost[i] + 0.5 * cost[i + 1]);
        
        ans = 0;
        
        for(int j = 1; j <= 4; j++){
            
            d += duration[j + i];
            
            ans += cost[i + j + 1];
            
            if(d < 120)
                dp[i + j + 1] = min(dp[i + j + 1], dp[i - 1] + cost[i] + 0.5 * cost[i + 1] + 0.25 * ans);
        }
    }

    printf("%.2lf\n",dp[n]);

    return 0;
}
