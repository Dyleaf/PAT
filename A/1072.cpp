//需要注意的是这题看出来了在linux上是不会进行四舍五入的。其他的倒是比较常规。
//通过多个点的dijkstra解决了这题
#include <bits/stdc++.h>
#include <string>
using namespace std;

const int INF = 0xfffffff;
const int maxn = 1200;
int mmap[maxn][maxn];

int main(){
    int n,m,k,ds;
    scanf("%d%d%d%d", &n,&m, &k, &ds);
    string x, y;
    int tmpdis,a, b;
        fill (mmap[0], mmap[0]+maxn*maxn,INF);
    for(int i=0; i< k;i++){
        cin>>x>>y>>tmpdis;
        if(x[0] == 'G'){
            x = x.substr(1);
            a= n+stoi(x);
        }else{
            a = stoi(x);
        }
        if(y[0] == 'G'){
            y = y.substr(1);
            b = n+stoi(y);
        }else{
            b = stoi(y);
        }
        mmap[a][b]  = mmap[b][a] = tmpdis;
    }
    double mindis = -1, avgdis = INF;
    int ansid = -1;
    int dis[maxn], book[maxn];
    for(int tt=n+1; tt<=n+m; tt++){
        fill (book, book+maxn,false);
        fill (dis, dis+maxn,INF);
        dis[tt] = 0;
        double tmpmindis = INF, tmpavgdis = 0;
        for(int i = 1; i<=n+m; i++){
            int u = -1, minn = INF;
            for(int j = 1; j<=n+m; j++){
                if(book[j] == false && dis[j]<minn){
                    u = j;
                    minn = dis[j];
                }
            }
            if(u==-1) break;
            book[u] = true;
            for(int v = 1; v<=n+m; v++){
                if(book[v] == false && mmap[u][v] + dis[u] < dis[v]){
                    dis[v] = dis[u] + mmap[u][v];
                }
            }
        }

        for(int i=1; i<=n; i++){
            if(dis[i]>ds){
                tmpmindis = -1;
                break;
            }
            if(dis[i] < tmpmindis){
                tmpmindis = dis[i];
            }
            tmpavgdis += dis[i];
        }
        if(tmpmindis == -1) continue;
        if(tmpmindis > mindis){
            mindis = tmpmindis;
            avgdis = tmpavgdis;
            ansid = tt;
        }else if(tmpmindis == mindis && tmpavgdis < avgdis){
            ansid = tt;
            avgdis = tmpavgdis;
        }
    }
    if(ansid == -1){
        printf("No Solution\n");
    }else{
        printf("G%d\n%0.1f %0.2f",ansid-n, mindis, avgdis/n);
    }
}

