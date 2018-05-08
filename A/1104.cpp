#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    double sum=0, v;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf", &v);
        sum += v*(n-i)*(i+1);
    }
    printf("%.2lf", sum);
}
