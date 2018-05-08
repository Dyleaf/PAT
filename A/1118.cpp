// 简单的并查集
#include <bits/stdc++.h>
using namespace std;

const int maxn = 10001;
int father[maxn], cnt[maxn];
int find(int x){
    int a = x;
    while(x != father[x]) x = father[x];
    while(a != father[a]){
        int t = a;
        a = father[a];
        father[t] = x;
    }
    return x;
}
void Union(int a, int b){
    int fa = find(a);
    int fb = find(b);
    if(fa != fb) father[fa] = fb;
}
bool birds[maxn];
int main(){
    int n, pre, next, k,m;
    scanf("%d", &n);
    for(int i=1; i<=maxn; i++){
        father[i] = i;
    }
    for(int i = 0; i<n; i++){
        scanf("%d%d", &k, &pre);
        birds[pre] = true;
        for(int j=1;j<k; j++){
            scanf("%d", &next);
            Union(pre, next);
            birds[next] = true;
        }
    }
    int birscnt = 0, treecnt = 0;
    for(int i=1; i<maxn; i++){
        if(birds[i]){
            if(father[i] == i) treecnt++;
            birscnt++;
        }
    }
    printf("%d %d\n", treecnt, birscnt);
    scanf("%d", &m);
    int ida, idb;
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &ida, &idb);
        printf("%s\n", (find(ida) == find(idb)) ? "Yes" : "No");
    }
}
