#include <bits/stdc++.h>
using namespace std;
struct NODE{
    int value,id;
    vector<NODE>son;
};
vector<NODE> v;
int s;
int path[1000];
void dfs(int id, int w, int cnt){
    if(w == s && v[id].son.size() ==0){
        printf("%d", v[path[0]].value);
        for(int i=1; i<cnt; i++){
            printf(" %d", v[path[i]].value);
        }
        printf("\n");
        return;
    }
    for(int i=0; i<v[id].son.size(); i++){
        if( w + v[id].son[i].value <= s){
            path[cnt] = v[id].son[i].id;
            dfs(v[id].son[i].id, w+v[id].son[i].value, cnt+1);
        }
    }
}

bool cmp(NODE a, NODE b){
    return a.value > b.value;
}

int main(){
    int n, m;
    scanf("%d%d%d", &n, &m,&s);
    v.resize(n);
    for(int i=0; i<n; i++){
        scanf("%d", &v[i].value);
        v[i].id = i;
    }
    for(int i = 0; i<m; i++){
        int id, num;
        scanf("%d%d", &id, &num);
        int value;
        for(int j = 0; j<num; j++){
            scanf("%d", &value);
            v[id].son.push_back(v[value]);
        }
        sort(v[id].son.begin(), v[id].son.end(), cmp);
    }
    path[0] = 0;
    dfs(0,v[0].value,1);
}
