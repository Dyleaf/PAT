// erfen
#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    long long  p;
    scanf("%d%lld", &n,&p);
    vector<int> v(n);
    for(int i = 0;i<n; i++){
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    int result = 0, tmp = 0;
    for(int i =0; i<n; i++){
        for(int j =i+result; j<n; j++){
            if(v[j]<=v[i]*p){
                tmp = j-i+1;
                if(tmp>result) result = tmp;
            }else{
                break;
            }
        }
    }
    printf("%d", result);
}
