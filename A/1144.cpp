#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,t;
    cin>>n;
    map<int,int>m;
    for(int i=0;i<n;i++){
        cin>>t;
        m[t] = 1;
    }
    int i=1;
    while(true){
        if(m[i]!=1){
            printf("%d",i);
            break;
        }
        i++;
    }
}
