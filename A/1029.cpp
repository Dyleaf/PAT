#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<long int> a,b;
    int n;
    scanf("%d", &n);
    a.resize(n);
    for(int i=0; i<n; i++){
        scanf("%ld",&a[i]);
    }
    scanf("%d", &n);
    b.resize(n);
    for(int i=0; i<n; i++){
        scanf("%ld",&b[i]);
    }
    int idxa = 0, idxb = 0, cnt = (a.size()+b.size()-1)/2+1;
    long int cur;
    while(cnt){
        if(idxa < a.size() && (a[idxa] <= b[idxb] || idxb>=b.size())){
            cur = a[idxa];
            idxa++;
            cnt--;
        }else if(idxb < b.size() &&  (a[idxa] >= b[idxb] || idxa>=a.size())){
            cur = b[idxb];
            idxb++;
            cnt--;
        }
    }
    printf("%ld\n",cur);
}
