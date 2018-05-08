#include <bits/stdc++.h>
using namespace std;

struct node{
    int x,y, z;
};
int brain[1300][130][80];
bool vis[1300][130][80];
int dx[6] = {1,0, 0, 0, 0, -1};
int dy[6] = {0,1, -1,0, 0, 0};
int dz[6] = {0, 0, 0, 1, -1, 0};

int n, m, l, minn;
bool judge(node t){
    if(t.x<0 || t.y<0 || t.z<0 || t.x>=m || t.y >=n|| t.z>=l) return false;
    else if(brain[t.x][t.y][t.z] == 0 || vis[t.x][t.y][t.z] ==true) return false;
    else return true;
}
int  bfs(int x , int y, int z){
    queue<node>q;
    node t = {x,y, z};
    int cnt  = 1;
    vis[t.x][t.y][t.z] = true;
    q.push(t);
    while(!q.empty()){
        node t =q.front();
        q.pop();
        for(int i=0; i<6;i++){
            node n;
            n.x = t.x+dx[i];
            n.y = t.y+dy[i];
            n.z = t.z+dz[i];
            if(judge(n)){
                q.push(n);
                vis[n.x][n.y][n.z] = true;
                cnt++;
            }
        }
    }
    if(cnt>=minn)
        return cnt;
    else return 0;
}
int main(){
    scanf("%d%d%d%d", &n, &m, &l, &minn);
    for(int i=0; i<l; i++){
        for(int y=0; y<n; y++){
            for(int x = 0; x<m; x++){
                scanf("%d", &brain[x][y][i]);
            }
        }
    }
    int cnt =0;
    //memset(vis, false, sizeof(vis));
    for(int i=0; i<l; i++){
        for(int y=0; y<n; y++){
            for(int x = 0; x<m; x++){
                if(brain[x][y][i] ==1 && vis[x][y][i]==false){
                cnt+=bfs(x,y,i);
                }
            }
        }
    }
    printf("%d", cnt);
}




































