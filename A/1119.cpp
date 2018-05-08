#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;
vector<int> pre, pos, in;

bool unique = true;
void getin(int preleft, int preright, int posleft, int posright){
    if(preleft == preright){
        in.push_back(pre[preright]);
        return;
    }
    if(pre[preleft] == pos[posright]){
        int i = preleft+1;
        while(i < preright && pre[i] != pos[posright-1]) i++;
        if(i - preleft > 1){
            getin(preleft+1, i-1, posleft, posleft+(i - preleft-1) -1);
        }else{
            unique = false;
        }
        in.push_back(pos[posright]);
        getin(i, preright, posleft+(i - preleft -1), posright -1);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    pre.resize(n);
    pos.resize(n);
    for(int i = 0; i<n; i++){
        scanf("%d", &pre[i]);
    }
    for(int i = 0; i<n; i++){
        scanf("%d", &pos[i]);
    }
    getin(0, n-1, 0, n-1);
    printf("%s\n%d", (unique == true? "Yes": "No"), in[0]);
    for(int i = 1; i<in.size(); i++){
        printf(" %d", in[i]);
    }
    printf("\n");
}
