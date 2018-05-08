#include<iostream>  
#include<vector>  
#include<algorithm>  
using namespace std;  
const int INF = 0x3fffffff;  
const int MAX = 1000;  
vector<int> pre[MAX];//存放最短路径上节点的前驱，可能不止一条路径   
int G[MAX][MAX];  
bool visited[MAX]={false};  
int weight[MAX],need[MAX];//节点的现有自行车数量，及需要的自行车数量负数代表需要，反之多余   
int d[MAX];  
int weightmax,n,index,m;  
//求need数组  
void calneed(){  
    for(int i=1;i<n;i++){  
        need[i]=weight[i]-weightmax/2;  
    }  
}   
void Dijkstra(int s){  
    fill(d,d+MAX,INF);  
    d[s]=0;  
    for(int i=0;i<n;i++){  
        int u=-1,min=INF;//找到最小的d[u]  
        for(int j=0;j<n;j++){  
            if(visited[j]==false&&d[j]<min){  
                u=j;  
                min=d[j];  
            }  
        }  
        if(u==-1) return;//节点不连通  
        visited[u]=true;  
        for(int v=0;v<n;v++){  
            if(visited[v]==false&&G[u][v]!=INF){  
                if(d[u]+G[u][v]<d[v]){  
                   d[v]=d[u]+G[u][v];  
                   pre[v].clear();  
                   pre[v].push_back(u);  
                }  
                else if(d[u]+G[u][v]==d[v]){  
                    pre[v].push_back(u);  
                }  
            }     
        }  
    }  
}   
//先选择需要派遣的自行车最少路径，在此基础上如果有多条路径，  
//再选择回收最少的路径   
int sentmin=INF,backmin=INF;//派遣最少，回收最少   
vector<int> optpath, temppath;//最优路径、临时路径  
//从目标节点递归访问直到起点（PBMC）  
void DFS(int v){  
    //递归边界  
    if(v==0){  
        temppath.push_back(v);  
        int sent=0,back=0,temp=0;//存放路径temppath的sent，back值  
        vector<int> sum;//利用need数组计算路径temppath上从起点（pbmc）到各节点的need数组和  
        sum.clear();        //找到最小值（显然如果是负的，最小值的绝对值就是从PBMC出发是应该带的  
                            //自行车数量（不然路上不够用，尽管后面可能有的节点剩的多，但是回不了头）  
                            //如果sum数组值都非负，那么很好开始的时候不用带自行车，sent=0；  
                            //这种情况下找back最小的路径   
        for(int i=temppath.size()-2;i>=0;i--){//temppath存放路径是倒序的,最后一个必为零，没必要计算,同时省去为need[0]及weight[0]赋值   
            temp+=need[temppath[i]];  
            sum.push_back(temp);//sum存放路径前k节点的need数组之和    
        }  
        if(*min_element(sum.begin(),sum.end())<0){  
            sent=-*min_element(sum.begin(),sum.end());  
        }  
        else{  
            sent=0;//路径顺序上任意缺车节点前面多余的车足够补充缺少的车   
        }  
        back=temp+sent;//sent意思就是PCMB派出的车数    
        if(sent<sentmin){//选派遣车辆最少的   
            sentmin=sent;  
            backmin=back;  
            optpath=temppath;  
        }  
        else if(sent==sentmin&&back<backmin){//派遣车辆都为最少，选取回收最少的   
            backmin=back;  
            optpath=temppath;  
            }  
        temppath.pop_back();  
    }   
    //递归式  
    temppath.push_back(v);  
    for(int i=0;i<pre[v].size();i++){  
        DFS(pre[v][i]);//递归v的前驱节点   
    }   
    temppath.pop_back();   
}  
int main(){  
    int n_temp;  
    scanf("%d%d%d%d",&weightmax,&n_temp,&index,&m);  
    n=n_temp+1;  
    for(int i=1;i<n;i++){  
        scanf("%d",&weight[i]);  
    }  
    calneed();  
    int itemp,jtemp,weighttemp;  
    fill(G[0],G[0]+MAX*MAX,INF);  
    for(int i=0;i<m;i++){  
        scanf("%d%d%d",&itemp,&jtemp,&weighttemp);  
        G[itemp][jtemp]=G[jtemp][itemp]=weighttemp;  
    }   
    Dijkstra(0);  

    DFS(index);  
    printf("%d 0",sentmin);  
    for(int i=optpath.size()-2;i>=0;i--){  
        printf("->%d",optpath[i]);  
    }  
    printf(" %d\n",backmin);  
    return 0;  
}   