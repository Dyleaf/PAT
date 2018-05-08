#include <bits/stdc++.h>
using namespace std;
const int maxn = 510, INF = 0xfffffff;
int e[maxn][maxn], dis[maxn], book[maxn], cost[maxn][maxn];
vector<int> pre[maxn], path, tmpPath;
int mincost = INF;
int n, m, s,d;

void dfs(int v,int tmpcost){
    tmpPath.push_back(v);
    if(v==s){
        if(tmpcost < mincost){
            path = tmpPath;
            mincost = tmpcost;
        }
        tmpPath.pop_back();
        return;
    }
    for(int i=0; i<pre[v].size(); i++){
        dfs(pre[v][i], tmpcost+cost[v][pre[v][i]]);
    }
    tmpPath.pop_back();
}
void dijkstra(){
    fill(e[0], e[0]+maxn*maxn,INF);
    fill(dis, dis+maxn, INF);
    memset(book, 0, sizeof(book));

    int x, y, d, c;
    for(int i = 0; i<m; i++){
        scanf("%d%d%d%d", &x, &y, &d ,&c);
        e[x][y] = e[y][x] = d;
        cost[x][y]= cost[y][x] = c;
    }
    pre[s].push_back(s);
    dis[s] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = INF;
        for(int j = 0; j < n; j++) {
            if(book[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        book[u] = true;
        for(int v = 0; v < n; v++) {
            if(book[v] == false && e[u][v] != INF) {
                if(dis[v] > dis[u] + e[u][v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d",&n, &m, &s, &d);
    dijkstra();
    dfs(d,0);
    int pathlen = 0;
    for(int i=path.size()-1; i>=0; i--){
        if(i!=path.size()-1) printf(" ");
        printf("%d",path[i]);
    }
    printf(" %d %d", dis[d], mincost);
}
