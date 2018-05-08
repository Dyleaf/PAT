#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> a(n), b(n),v(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
        b[i] = a[i];
    }
    sort(a.begin(), a.end());
    int cnt =0, max = 0;
    for(int i=0; i<n; i++){
        if(a[i]==b[i] && b[i]>max)
            v[cnt++] = a[i];
      if(b[i]>max) max = b[i];
    }
    cout<<cnt<<endl;
    for(int i=0; i<cnt; i++){
        if(i==0) printf("%d", v[i]);
        else printf(" %d",v[i]);
    }
    printf("\n");
}
