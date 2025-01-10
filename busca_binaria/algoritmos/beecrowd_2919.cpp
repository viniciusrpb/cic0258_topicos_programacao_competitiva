#include<bits/stdc++.h>
#define MAX 200001
 
using namespace std;

int bucket[200001],pre[200001],ind[200001];
vector<int> lis_sequence;
 
int lis_nlogn(int *v, int n){
    
    bucket[0] = v[0];
    ind[0] = 0;
    pre[0] = -1;
    int ans = 1;
    for(int i = 1; i < n; i++){
        if(v[i] > bucket[ans-1]){
            pre[i] = ind[ans-1];
            ind[ans]=i;
            bucket[ans++] = v[i];
        }
        else{
            int index = lower_bound(bucket,bucket+ans,v[i])-bucket;
            bucket[index]=v[i];
            ind[ans]=i;
            if(index > 0)
                pre[i] = ind[index - 1];
            else
                pre[i] = -1;
        }
    }
 
    return ans;
}
 
int main(){
 
    int ans,n;
    
    while(scanf("%d",&n)!=EOF){
        
        int array[MAX];
        
        for(int i = 0; i < n; i++){
            scanf("%d",array+i);
        }
    
        ans = lis_nlogn(array,n);
        printf("%d\n",ans);
        
        lis_sequence.clear();
        int last_index = ind[ans - 1];
        while (last_index != -1) {
            lis_sequence.push_back(array[last_index]);
            last_index = pre[last_index];
        }
        reverse(lis_sequence.begin(), lis_sequence.end());
        for (int x : lis_sequence) {
            printf("%d ", x);
        }
        printf("\n");
    }
 
    return 0;
}
