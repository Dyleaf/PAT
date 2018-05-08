#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    vector<int> child;
};

vector<node>v;
double p, r;
int maxnum = 0, maxdepth;

void dfs(int root, int depth){
    if(v[root].child.size() == 0){
        if(depth>maxdepth){
            maxdepth = depth;
            maxnum = root;
            maxnum = 1;
        }else if(depth == maxdepth){
            maxnum++;
        }
        return;
    }
    for(int i  = 0; i< v[root].child.size(); i++){
        dfs(v[root].child[i], depth+1);
    }

}
int main(){
    int n, root, idx;
    scanf("%d%lf%lf", &n, &p, &r);
    v.resize(n);
    for(int i = 0; i<n; i++){
        scanf("%d", &idx);
        if(idx == -1){
            root = i;
            continue;
        }
        v[idx].child.push_back(i);
    }
    dfs(root, 0);
    printf("%0.2f %d",p*pow(1+r/100, maxdepth), maxnum);
}
