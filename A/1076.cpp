//写完这题发现了一个问题，发现是链式前向星的空间开小了。直接开成1000000后最有一个点
//成功通过了，在此之前使用vector写过了这题，不过感觉还是使用链式前向星速度更快。

#include <bits/stdc++.h>
#include <queue>
using namespace std;

const int maxn = 1010*1010;
struct node{
    int from, to, next;
}e[maxn];
int idx = 1, head[maxn];

void add(int u, int v){
    e[idx].from = u;
    e[idx].to = v;
    e[idx].next = head[u];
    head[u] = idx++;
}
bool vis[maxn];
int n;
vector<vector<int> >v;

void bfs(int u,int&ans, int l){
    queue<pair<int,int> >q;
    q.push(make_pair(u, 0));
    vis[u] =true;
    while(!q.empty()){
        pair<int,int> tmp = q.front();
        q.pop();
        for(int i=head[tmp.first]; i!= -1; i = e[i].next){
            int nextid = e[i].to;
            if(vis[nextid] == false && tmp.second < l){
                pair<int,int> next = make_pair(nextid, tmp.second+1);
                q.push(next);
                vis[nextid] = true;
                ans++;
            }
        }
    }
}
void bfs2(int u,int&ans, int l){
    queue<pair<int,int> >q;
    q.push(make_pair(u, 0));
    vis[u] =true;
    while(!q.empty()){
        pair<int,int> tmp = q.front();
        q.pop();
        for(int i=0; i<v[tmp.first].size(); i++){
            int nextid = v[tmp.first][i];
            if(vis[nextid] == false && tmp.second < l){
                pair<int,int> next = make_pair(nextid, tmp.second+1);
                q.push(next);
                vis[nextid] = true;
                ans++;
            }
        }
    }
}


int main(){
    int m, l;
    scanf("%d%d", &n, &l);
    fill(head,head+maxn,-1);
    int k, tmp;
    v.resize(n+1);
    for(int i=1; i<=n; i++){
        scanf("%d", &k);
        for(int j = 0; j<k; j++){
            scanf("%d", &tmp);
            add(tmp,i);
            //v[tmp].push_back(i);
        }
    }
    scanf("%d", &m);
    int ans = 0;
    for(int i=0; i<m; i++){
         scanf("%d", &tmp);
        fill(vis, vis+maxn,false);
        ans = 0;
        bfs(tmp,ans,l);
        printf("%d\n", ans);
    }
}
