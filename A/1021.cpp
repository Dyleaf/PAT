#include <bits/stdc++.h>
using namespace std;

const int maxn = 300000;

struct Node{
    int to;
	int from;
    int w;
    int next;
}e[maxn];

int cnt = 0;
int head[maxn];
bool mark[maxn];
void add(int u, int v, int w)
{
    e[cnt].from = u;
    e[cnt].to = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

int father[maxn];

void init(int n)
{
    for(int i=0; i<=n; i++)
    {
        father[i] = i;
    }
}

int find(int x)
{
    int p = x, t;
    while (father[p] != p) p = father[p];//返回根节点；
    while (x != p) { t = father[x]; father[x] = p; x = t; }//路径压缩
    return x;
}

void unionset(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return;
    else father[y] = x;
}

int height = 0;
void dfs(int root,int leavel,vector<int> &v){

	mark[root] = true;
	if(leavel > height)
	{
		height = leavel;
		v.clear();
		v.push_back(root);
	}else if(leavel == height){
     	v.push_back(root);
	}
	int y;
	for(int i=head[root]; i!=-1; i = e[i].next)
	{
		y= e[i].to;
		if(!mark[y]){
			dfs(y, leavel+1, v);
			mark[y] = false;
		}
	}
}

int main(){

    int n;
	scanf("%d",&n);
	init(n);
    memset(head, -1, sizeof(head));
	for(int i=0; i<n-1; i++){
        int x, y;
		scanf("%d%d", &x, &y);
		add(x, y, 1);
		add(y, x, 1);
		unionset(x, y);
	}
	int k = 0;
    for(int i=1; i<=n;i++)
	{
		if(father[i]== i) k++;
	}
	if(k>1){
      printf("Error: %d components", k);
	  return 0;
	}else{

        vector<int> farthestNode, res;
		memset(mark,false, sizeof(mark));
		dfs(1, 0, res);

		int k =res[0];

		memset(mark,false, sizeof(mark));
		dfs(k, 0,farthestNode);
		for(int i=0; i<farthestNode.size(); i++)
		{
			res.push_back(farthestNode[i]);
		}
		sort(res.begin(), res.end());

		for(int i=0; i< res.size();i++){
			printf("%d\n", res[i]);
			if(i+1<res.size() && res[i]== res[i+1]) i++;
		}
	}

}
