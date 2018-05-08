// 这题是dfs题目大意：给三个正整数N、K、P，将N表示成K个正整数（可以相同，递减排列）的P次方和，如果有多种方案，选择底数n1+…+nk最大的方案，如果还有多种方案，选择底数序列的字典序最大的方案～
#include <bits/stdc++.h>
using namespace std;

const int maxn = 400;
int cnt = 1;
int book[maxn];
int n,p,l,flag = 0;

void initdata(){
    int tmp = 0;
    for(int i=1; i<maxn && tmp<n; i++){
        tmp = pow(i,p);
        book[i] = tmp;
        cnt++;
    }
}
vector<int>ans;
int maxfacsum = -1;

void dfs(int remain,int idx,vector<int> &path, int facsum){
    if(remain==0 && path.size()==l){
        flag = 1;
        if(facsum>maxfacsum){
            ans = path;
            maxfacsum = facsum;
        }
        return;
    }

    for(int i=idx; i>=1; i--){
        if(remain>=book[i]){
            path.push_back(i);
            dfs(remain-book[i], i, path, facsum+i);
            path.pop_back();
        }
    }
    return;
}

int main(){
    scanf("%d%d%d", &n,&l,&p);
    initdata();
    vector<int> path;
    dfs(n,cnt-1,path,0);
    if(!flag) printf("Impossible\n");
    else{
        printf("%d = ",n);
        for(int i=0; i<ans.size() ;i++){
            if(i!=0) printf(" + ");
                printf("%d^%d",ans[i],p);
        }
        printf("\n");
    }
}
