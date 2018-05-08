#include <bits/stdc++.h>
using namespace std;

int cmp(int a,int b){
    return a>b;
}

int getN(int n){
    int ans = sqrt(n);
    while(ans>=1){
        if(n%ans == 0){
            return ans;
        }
        ans--;
    }
    return 1;
}
int main(){
    int N,n,m;
    scanf("%d", &N);
    vector<int> v(N+1);
    for(int i=0; i<N; i++){
        scanf("%d", &v[i]);
    }
    sort(v.begin(),v.end(),cmp);
    n = getN(N);
    m = N/n;
    vector< vector<int> > b(m,vector<int>(n));
    int l=0,r = n-1,u = 0,d = m-1;
    int idx = 0;
    while(l<r && u<d){
        for(int i=l; i<=r; i++) b[u][i] = v[idx++];
        for(int i=u+1; i<=d; i++) b[i][r] = v[idx++];
        for(int i=r-1; i>=l; i--) b[d][i] = v[idx++];
        for(int i=d-1; i>=u+1; i--) b[i][l] = v[idx++];
        d--;u++;
        l++;r--;
    }
    if(l==r){
        for(int i=u;i<=d;i++) b[i][l]=v[idx++];
    }
    else if(u==d){
        for(int i=l;i<=r;i++) b[u][i]=v[idx++];
    }
    for(int i=0;i<m;i++)  {
        cout<<b[i][0];
        for(int j=1;j<n;j++){
            cout<<" "<<b[i][j];
        }
        cout<<endl;
    }
}

