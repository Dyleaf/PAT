#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
int limit;
map<int,string> int2string;
map<string, int> string2int, ans;
int idxnum = 1;
int weight[maxn], vis[maxn];
int G[maxn][maxn];

int str2idx(string s){
    if(string2int[s] == 0){
        string2int[s] = idxnum;
        int2string[idxnum]  = s;
        return idxnum++;
    }else{
        return string2int[s];
    }
}


void dfs(int v,int &head,int &graphNum, int &totolweight){
    if(weight[v] > weight[head])
        head = v;
    vis[v] = true;
    graphNum++;
    for(int i=0;i<idxnum; i++){
        if(G[v][i]){
            totolweight+=G[v][i];
            // avoid the circle
            G[v][i] = G[i][v]  = 0;
            if(vis[i] == false){
                dfs(i, head,graphNum, totolweight);
            }
        }
    }
}

void dfsTravel(){
    for(int i = 0; i<idxnum; i++){
        if(!vis[i]){
            int graphNum = 0;
            int head  = i,totolweight = 0;
            dfs(i,head, graphNum,totolweight);
            if(graphNum>2 && totolweight>limit){
                ans[int2string[head]] = graphNum;
            }
        }
    }
}

int main(){
    int n,w;
    cin>>n>>limit;
    string s1, s2;
    for(int i=0; i<n; i++){
        cin>>s1>>s2>>w;
        int n1 = str2idx(s1);
        int n2 = str2idx(s2);
        weight[n1] +=w;
        weight[n2] +=w;
        G[n1][n2] += w;
        G[n2][n1] += w;
    }
    dfsTravel();
    cout<< ans.size()<<endl;
    for(auto it = ans.begin(); it!= ans.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}
