#include <bits/stdc++.h>
using namespace std;

const int MAX   = 1000;
const int INF = 0x7FFFFF;

int map[MAX][MAX];
int v[MAX] = {0};
int dist[MAX] = {0};
int teams[MAX] = {0};
int N, M, c1, c2;
int maxTeam = 0, minDist = INF, pathNum = 0;

void dfs(int s, int dist, int team){
	if(s==c2){
		if(minDist>dist){
			minDist = dist;
			pathNum = 1;
			maxTeam = team;
		}else if(minDist == dist){
			if(team>maxTeam) maxTeam = team;
			pathNum++;
		}
		return;
	}
	v[s] = 1;
	for (int i = 0; i < N; ++i)
	{
		if (v[i]==0 && map[s][i]>0)
		{
			dfs(i,dist+map[s][i],team+teams[i]);
		}
	}
	v[s] = 0;
}


int main(){

	scanf("%d%d%d%d", &N, &M, &c1, &c2);

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &teams[i]);
	}

	memset(map, -1, sizeof(map));
	for (int i = 0; i < M; ++i)
	{
		int x, y, dist;
		scanf("%d%d%d", &x, &y, &dist);
		map[x][y] = dist;
		map[y][x] = dist;
	}
	// print();
	dfs(c1, 0, teams[c1]);
	printf("%d %d\n",pathNum, maxTeam);
}
