#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n;
void posTraval(int idx){
    if(idx>=n) return;
    posTraval(idx*2+1);
    posTraval(idx*2+2);
    printf("%d%s", v[idx], idx==0?"\n":" ");
}
int main(){
    int k;
    scanf("%d%d", &k,&n);
    v.resize(n);
    while(k--){
        for(int i=0; i<n; i++){
            scanf("%d",&v[i]);
        }
        int flag = v[0]>v[1]? 1:-1;
        for(int i=0; i<=(n-1)/2; i++){
            int left = i*2+1, right = i*2+2;
            if(flag==1 && (v[left]>v[i] || (right<n && v[right]>v[i]))) flag = 0;
            if(flag==-1 && (v[left]<v[i] ||(right<n && v[right]<v[i]))) flag = 0;
        }
        if(flag==0){
            printf("Not Heap\n");
        }else{
            printf("%s\n", flag==1? "Max Heap":"Min Heap");
        }
        posTraval(0);
    }
}
