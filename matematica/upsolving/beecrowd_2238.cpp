#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(int a, int b, int c, int d){

    ll i;
    vector<ll> ans;
    
    for(i = 1; i*i <= c; i++){
        if(c%i == 0){
            if(i%a == 0 and i%b!=0 and d%i!=0)
                ans.push_back(i);
            
            ll t = c/i;
        
            if(t%a == 0 and t%b!=0 and d%t!=0)
                ans.push_back(t);
        }
    }
    
    if(ans.size() == 0)
        return -1;
    else{
        sort(ans.begin(),ans.end());
        return ans[0];
    }
}

int main(){
    int a,b,c,d;
    
    scanf("%d %d %d %d",&a,&b,&c,&d);
    
    printf("%lld\n",solve(a,b,c,d));
    
    return 0;
}
