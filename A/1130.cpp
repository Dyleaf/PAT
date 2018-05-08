#include<bits/stdc++.h>
#define MAXN 21
using namespace std;
int n, Root;
int vis[MAXN];

struct Node{
    string s;
    int l, r;
}node[MAXN];


void dfs(int root)
{   //border
    if(root==-1) return ;
    //判断是否是根节点或者叶子结点
    if(root!=Root&&(node[root].l!=-1||node[root].r!=-1)) cout<<"(";
    //中序遍历
    dfs(node[root].l);
    cout<<node[root].s;
    dfs(node[root].r);

    if(root!=Root&&(node[root].l!=-1||node[root].r!=-1)) cout<<")";
}

int main()
{
    scanf("%d",&n);
    memset(vis,0,sizeof(vis));

    for(int i=1 ;i<=n ;i++){
        cin>>node[i].s>>node[i].l>>node[i].r;
        vis[node[i].l] = vis[node[i].r] = 1;
    }
    //找到根节点
    Root = 1;
    while(vis[Root])Root++;

    dfs(Root);

    return 0;
}
