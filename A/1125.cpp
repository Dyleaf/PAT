#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    scanf("%d",&n);
    vector<int> v(n);
    for(int i =0; i<n; i++){
        scanf("%d",&v[i]);
    }
    sort(v.begin(),v.end());
    int len =v[0];
    for(int i=1; i<n; i++){
        len = (len + v[i])/2;
    }
    printf("%d", len);
}
