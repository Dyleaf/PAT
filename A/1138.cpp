#include <bits/stdc++.h>
using namespace std;
const int maxn = 50001;
int root;
void dfs(int *in,int *pre, int size){
    if(size==1){
        root = in[0];
        return;
    }
    int mid ;
    for(int i=0; i<size; i++){
        if(in[i] == pre[0]){
            mid = i;
            break;
        }
    }
    if(mid!=0){
        dfs(in,pre+1,mid);
    }else{
        dfs(in+1, pre+1, size-1);
    }
}
int main(){
    int n;
int pre[maxn], in[maxn];
cin>>n;
    for(int i=0; i<n; i++){
        scanf("%d", &pre[i]);
    }
    for(int i=0; i<n; i++){
        scanf("%d", &in[i]);
    }
    dfs(in,pre,n);
    cout<<root<<endl;
}
