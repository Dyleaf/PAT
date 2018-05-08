#include <bits/stdc++.h>
using namespace std;

struct NODE{
    int value;
    int  left, right;
}v[1000];

bool first = true;

void posTreval(int idx){
    if(v[idx].left != -1)
        posTreval(v[idx].left);
    if(v[idx].right != -1)
        posTreval(v[idx].right);
    if(!first) printf(" ");
    else first = false;
    printf("%d", v[idx].value);
}
int main(){
    int n, cnt = 0;
    scanf("%d",&n);
    string s;
    getchar();
    stack<int> trstack;
    int parent = -1,root;
    for(int i=0; i< 2*n; i++){
        getline(cin, s);
        if(s[1] == 'u'){
            s = s.substr(5);
            int num = stoi(s);
            if(first){
                root = num;
                first = false;
            }
            trstack.push(num);
            NODE t = {num, -1, -1};
            if(v[parent].left != -1){
                v[parent].right = num;
            }else{
                v[parent].left = num;
            }
            parent = num;
            v[num] =t;
        }else{
            parent = trstack.top();
            trstack.pop();
        }
    }
    first = true;
    posTreval(root);
}
