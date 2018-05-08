#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    vector<int>child;
};

vector<node> v;
double p, r, ans = 0;
int lowestLeavel,lowestNum = 0;

void dfs(int root, int depth){
    if(v[root].child.size() == 0 && lowestLeavel>= depth){
        if(lowestLeavel > depth){
            lowestNum = 1;
            lowestLeavel = depth;
            ans = pow(r+1,depth);
        }else if(lowestLeavel == depth)
            lowestNum++;
        return;
    }
    for(int i = 0; i<v[root].child.size(); i++){
        dfs(v[root].child[i], depth+1);
    }

}

int main(){
    int n, k, idx;
    scanf("%d%lf%lf", &n, &p, &r);
    v.resize(n);
    r = r/100;
    for(int i = 0; i<n; i++){
        cin>>k;
        if(k!=0){
            for(int j = 0; j<k; j++){
                scanf("%d", &idx);
                v[i].child.push_back(idx);
            }
        }
    }
    lowestLeavel = n;
    dfs(0, 0);
    printf("%0.4lf %d", ans*p, lowestNum);

}
