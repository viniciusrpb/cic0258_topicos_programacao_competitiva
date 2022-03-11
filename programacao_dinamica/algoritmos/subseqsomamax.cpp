#include<bits/stdc++.h>

using namespace std;

int scsm_n3(vector<int>& vetor)
{
    int N = vetor.size();
    int ans = -1e9;

    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            int sum = 0;

            for (int k = i; k <= j; k++)
                sum += vetor[k];

            ans = max(ans, sum);
        }
    }

    return ans;
}

int scsm_n2(vector<int>& vetor)
{
    int N = vetor.size();
    int ans = 0;
    
    for (int i = 0; i < N; i++){
        int sum = 0;
        for(int j = i; j < N; j++){
            sum += vetor[j];
            ans = max(ans,sum);
        }
    }
    
    return ans;
}

int scsm_n(vector<int>& vetor)
{
    int l,r,ans = 0, sum = 0,s=0;
    int N = vetor.size();
    
    for (int k = 0; k < N; k++){
        sum = max(vetor[k],sum+vetor[k]);
        ans = max(ans,sum);
        if(sum >= ans)
        {
            l = s;
            r = k;
        }
        if(ans < sum)
            s = k+1;
    }
    
    printf("%d %d\n",l,r);
    return ans;
}


int main()
{

    vector<int> a;
    
    a.push_back(3);
    a.push_back(-5);
    a.push_back(0);
    a.push_back(2);
    a.push_back(4);
    a.push_back(-1);
    a.push_back(-3);
    
    int s = 0;
    for(int i = 0; i < a.size(); i++)
    {
        s = s+a[i];
        printf("%d ",s);
    }
    printf("\n");
    
    printf("%d\n",scsm_n3(a));
    printf("%d\n",scsm_n2(a));
    printf("%d\n",scsm_n(a));
    return 0;
}
