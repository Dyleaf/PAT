// 这题就是通过并查集进行家庭的集合分类
#include <bits/stdc++.h>
using namespace std;

const int maxn = 10100;
struct person{
    int id,father, mather;
    double num,area;
    int flag, people;
    vector<int> child;
}ans[maxn];
int father[maxn];
bool vis[maxn];
int getfather(int x){
    int a = x;
    while(x != father[x]) x = father[x];
    while(a != father [a]){
        int t = father[a];
        a = father[a];
        father[t] = x;
    }
    return x;
}


void Union(int a, int b){
    int fa = getfather(a);
    int fb = getfather(b);
    if(fa > fb) father[fa] = fb;
    else
        father[fb] = fa;
}
bool cmp(person a, person b){
    if(a.area != b.area)
        return a.area > b.area;
    else
        return a.id<b.id;

}
int main(){
    int n;
    scanf("%d", &n);
    vector<person> p(n);
    int id, k;
    for(int i=0; i<maxn; i++)
        father[i] = i;
    for(int i=0; i<n; i++){
        scanf("%d%d%d%d", &p[i].id, &p[i].father, &p[i].mather,&k);
        vis[p[i].id] = true;
        if(p[i].father != -1){
           vis[p[i].father] = true;
           Union(p[i].father, p[i].id);
        }
        if(p[i].mather != -1){
           vis[p[i].mather] = true;
           Union(p[i].mather, p[i].id);
        }
        p[i].child.resize(k);
        for(int j = 0; j<k; j++){
            scanf("%d", &p[i].child[j]);
           vis[p[i].child[j]] = true;
           Union(p[i].child[j], p[i].id);
        }
        scanf("%lf%lf",&p[i].num, &p[i].area);
    }
    for(int i=0; i<n; i++){
        id = getfather(p[i].id);
        ans[id].id = id;
        ans[id].num += p[i].num;
        ans[id].area += p[i].area;
        ans[id].flag = true;
    }
    int cnt = 0;
    for(int i=0; i<maxn; i++)
        if(vis[i]) ans[getfather(i)].people++;

    for(int i = 0; i<maxn; i++){
        if(ans[i].flag) {
            cnt++;
            ans[i].num = (double)(ans[i].num *1.0/ans[i].people);
            ans[i].area = (double)(ans[i].area *1.0/ans[i].people);
        }
    }
    sort(ans, ans+maxn,cmp);
    printf("%d\n", cnt);
    for(int i=0; i<cnt; i++){
        printf("%04d %d %0.3lf %0.3lf\n", ans[i].id, ans[i].people, (double)ans[i].num, (double)ans[i].area);
    }
}

