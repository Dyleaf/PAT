#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;
int road[5000001][2];

int father[1001];

void makeset(int num){
    int i;
    for(int i =0; i<=num;i++)
        father[i] = i;
}


int findSet(int x){
    int p = x, t;
    while (father[p] != p) p = father[p];//返回根节点；
    while (x != p) { t = father[x]; father[x] = p; x = t; }//路径压缩
    return x;
}

void joinset(int x, int y)
{
    x = findSet(x);
    y = findSet(y);
    if(x==y){
        return ;
    }else{
        father[y]=x;
    }
}

int main(){
    int n, m,k;
    while(scanf("%d%d%d",&n,&m, &k)!=EOF){

       for(int i = 0; i<m; i++){
            scanf("%d%d", &road[i][0],&road[i][1]);
        }

        int temp;
        for(int i =0; i<k; i++){
            scanf("%d", &temp);
            makeset(n);
            for(int i =0; i<m; i++){
                if(temp!=road[i][0] && temp != road[i][1]){
                    joinset(road[i][0], road[i][1]);
                }
            }

        // get the city need to repair
            int num = 0;
            for(int i =1; i<=n; i++){
                if(father[i]==i)
                    num++;
            }
            printf("%d\n", num-2);// one is delete and the other is a  dege
        }
    }

}

