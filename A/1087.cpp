
#include <bits/stdc++.h>
using namespace std;

const int INF = 0xfffffff;
const int maxn = 1000;
map<int,string>int2str;
map<string,int>str2int;
int  e[maxn][maxn];
int hpy[maxn], dis[maxn];
bool vis[maxn] = {false};
vector<int>pre[maxn], path;

int  cnt = 0, tolhappy = 0,diff = 0;
double avghappy = 0;

void dfs(int idx, int end, int happy, vector<int> tpath){
    if(idx == end){
        double tmpavg =1.0 *happy/(tpath.size()-1);
        if(happy>tolhappy){
            path = tpath;
            tolhappy = happy;
            avghappy = tmpavg;
        }else if(happy == tolhappy && tmpavg>avghappy){
            avghappy = tmpavg;
            path = tpath;
        }
        diff++;
        return;
    }
    for(int i=0; i<pre[idx].size(); i++){
        tpath.push_back(pre[idx][i]);
        dfs(pre[idx][i], end, happy+hpy[pre[idx][i]],tpath);
        tpath.pop_back();
    }
}

int main(){
    int n, k, happy,begin = 0,end;
    string s;
    scanf("%d%d", &n, &k);
    cin>>s;
    int2str[0] = s;
    str2int[s] = 0;
    hpy[0] = 0;
    for(int i=1; i<n; i++){
        cin>>s>>happy;
        if(s=="ROM") end = i;
        int2str[i]=s;
        str2int[s]=i;
        hpy[i] = happy;
    }
    string x,y;
    int cost;
    fill(dis,dis+maxn,INF);
    fill(e[0],e[0]+maxn*maxn,INF);
    for(int i=0; i<k; i++){
        cin>>x>>y>>cost;
        e[str2int[x]][str2int[y]] = cost;
        e[str2int[y]][str2int[x]] = cost;
    }
    dis[begin] = 0;
    for(int j=0; j<n; j++){
        int u= -1, minn  = INF;
        for(int i=0; i<n; i++){
            if(vis[i] == false && dis[i] <minn){
                u = i;minn = dis[i];
            }
        }
        if(u==-1) break;
        vis[u] = true;
        for(int i=0; i<n; i++){
            if(vis[i] ==false && e[u][i] !=INF){
                if(dis[u]+e[u][i] < dis[i]){
                    dis[i] = dis[u]+e[u][i];
                    pre[i].clear();
                    pre[i].push_back(u);
                }else if(dis[u]+e[u][i] == dis[i]){
                    pre[i].push_back(u);
                }
            }
        }
    }

    vector<int>tpath;
      tpath.push_back(end);
    dfs(end, begin, hpy[end], tpath);
    printf("%d %d %d %d\n", diff, dis[end], tolhappy, (int)avghappy);
    for(int i=path.size()-1; i>=0; i--){
        if(i!=path.size()-1) printf("->");
        cout<<int2str[path[i]];
    }
}
