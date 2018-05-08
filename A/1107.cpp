// 这题是一个并查集，刚开始没看清题意，题意是这样的如果两个人的爱好一致
// 就形成了一个社交圈，比如3 5 的人和3 以及6 8 1 5是一个社交圈
//在写的时候course没有初始化，导致了bug
//基本思想是将course 设置为第一个选这课的人的id ，然后每次
//遇到已经有人选过的课时就可以根据course的根节点将当前的人的id加入并查集
#include <bits/stdc++.h>
using namespace std;

vector<int> father;
int findfather(int x){
    int a = x;
    while(x != father[x]){
        x = father[x];
    }
    while(a!=father[a]){
        int t = a;
        a = father[a];
        father[t] = x;
    }
    return x;
}
void Union(int a, int b){
    int fa = findfather(a);
    int fb = findfather(b);
    if(fa != fb){
        father[fa] = fb;
    }
}
bool cmp(int a, int b){
    return a>b;
}
int main(){
    vector<int>course(1001, 0), cluster;
    int n;
    scanf("%d", &n);
    cluster.resize(n+1);
    father.resize(n+1);
    for(int i=1; i<=n; i++)
        father[i] = i;
    for(int i=1; i<=n;i++){
        int k, t;
        scanf("%d:", &k);
        while(k--){
            scanf("%d", &t);
            if(course[t]==0)a
            course[t] =i;
            Union(i,findfather(course[t]));
        }
    }
    for(int i=1; i<=n; i++){
        cluster[findfather(i)]++;
    }
    int cnt= 0;
    for(int i=0; i<=n; i++){
        if(cluster[i] !=0) cnt++;
    }
    sort(cluster.begin(), cluster.end(), cmp);
    printf("%d\n", cnt);
    for(int i=0; i<cnt; i++){
        if(i!=0) printf(" ");
        printf("%d", cluster[i]);
    }
}
