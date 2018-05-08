#include <bits/stdc++.h>
using namespace std;


struct node{
    int val;
    vector<int>child;
};

vector<node> v;
double p, r, ans = 0;

void dfs(int root, int depth){
    if(v[root].child.size() == 0){
        ans += v[root].val*pow(r+1,depth);
    }else{
        for(int i = 0; i<v[root].child.size(); i++){
            dfs(v[root].child[i], depth+1);
        }
    }
}

int main(){
    int n, k, idx;
    scanf("%d%lf%lf", &n, &p, &r);
    v.resize(n);
    r = r/100;
    for(int i = 0; i<n; i++){
        cin>>k;
        if(k==0){
            scanf("%d",&v[i].val);
        }else{
            for(int j = 0; j<k; j++){
                scanf("%d", &idx);
                v[i].child.push_back(idx);
            }
        }
    }
    dfs(0, 0);
    printf("%0.1lf", ans*p);

}
