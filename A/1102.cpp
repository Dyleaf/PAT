#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct NODE{
    int value, left, right;
    NODE(){
        value = 0;
        left = -1;
        right = -1;
    }
}tree[1000];

bool first = true;
vector<int> leave, mid;
void leaveTravel(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(tree[t].left != -1) q.push(tree[t].left);
        if(tree[t].right != -1) q.push(tree[t].right);
        if(!first) printf(" ");
        else first = false;
        printf("%d", t);
    }
}

void midTravel(int root){
    if(root == -1) return;
    midTravel(tree[root].left);

    if(!first) printf(" ");
    else first = false;

    printf("%d", root);

    midTravel(tree[root].right);
}

int main(){
    int n;
    scanf("%d", &n); getchar();
    char left, right;
    int mark[100] = {0};
    for(int i=0; i<n; i++){
        scanf("%c %c", &right, &left); getchar();
        tree[i].left = (left=='-'? -1:(left-'0') );
        tree[i].right =( right=='-'? -1 : (right-'0'));
        if(tree[i].left != -1) mark[tree[i].left]++;
        if(tree[i].right != -1) mark[tree[i].right]++;
    }
    int root;
    if(n==0) return 0;
    for(int i=0; i<n; i++){
        if(mark[i]==0){
            root = i;
            break;
        }
    }
    first = true;
    leaveTravel(root);
    printf("\n");
    first = true;
    midTravel(root);
    printf("\n");
}
