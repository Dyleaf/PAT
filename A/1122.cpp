#include <bits/stdc++.h>
using namespace std;

const int maxn = 210;
int graph[maxn][maxn];
vector<int> path;
bool isConnect(int n){
    int x = path[0], y;
    for(int i=1; i<n; i++){
        y = path[i];
        if(graph[x][y] != 1) return false;
        x = y;
    }
    return true;
}
bool isHamilt(int n) {
    if (path[0] != path[n-1])
        return false;
    vector<int> times(n, 0);
    for (int i = 0; i < n; i++)
        times[path[i]]++;
    for (int i = 1; i < n; i++)
        if ((i == path[0] && times[i] != 2) || (i != path[0] && times[i] != 1)) return false;
    return true;
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int x, y;
    fill (graph[0], graph[0]+maxn*maxn, 0);
    for(int i=0; i<m; i++){
        scanf("%d%d",&x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    int Case, k, tmp;
    scanf("%d",&Case);
        for(int i =0; i<Case; i++){
            scanf("%d", &k);
            path.resize(k);
            for(int j = 0; j<k; j++){
                scanf("%d", &tmp);
                path[j] = tmp;
            }
            printf("%s\n",(n+1==k && isConnect(k) && isHamilt(k))? "YES":"NO");
        }
}
