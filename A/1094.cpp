#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
vector<int>v[maxn];
int book[maxn];
void dfs(int root, int level){
    book[level]++;
    for(int i=0; i<v[root].size(); i++){
        dfs(v[root][i], level+1);
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    int t,k;
    for(int i = 1; i<=m; i++){
        scanf("%d%d", &t, &k);
        v[t].resize(k);
        for(int j = 0; j<k; j++){
            scanf("%d", &v[t][j]);
        }
    }
    dfs(1,1);
    int maxnum = 1, maxleavel = 1;
    for(int i = 1; i<= maxn; i++){
        if(maxnum<book[i]){
            maxnum = book[i];
            maxleavel = i;
        }
    }
    printf("%d %d", maxnum,maxleavel);
    return 0;
}
