#include <bits/stdc++.h>
using namespace std;

struct cake{
    double price, ton,tolprice;
};


bool cmp(cake a, cake b){
    return a.price>b.price;
}
int main(){
    int n;
    double w;
    scanf("%d%lf", &n, &w);
    vector<cake> v(n);
    double ans = 0;
    for(int i=0; i<n; i++){
        scanf("%lf", &v[i].ton);
    }
    for(int i=0; i<n; i++){
        scanf("%lf",&v[i].tolprice);
        v[i].price = v[i].tolprice/v[i].ton;
    }
    sort(v.begin(),v.end(), cmp);
    for(int i=0; i<n; i++){
        if(w<=0) break;
        else if(w>=v[i].ton){
            w-=v[i].ton;
            ans+=v[i].tolprice;
        }else{
            ans+=w*v[i].price;
            break;
        }
    }
    printf("%0.2lf\n", ans);
}
