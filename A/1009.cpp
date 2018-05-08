#include <bits/stdc++.h>
using namespace std;
const int MAX = 2001;

int main(){

    double a[2][MAX],res[MAX];
    int t, ai;
    double ci;
    memset(a, 0, sizeof(a));
    memset(res, 0, sizeof(res));
    for(int i =0; i<2 ;i++){
        scanf("%d", &t);
        for(int j =0; j<t; j++){
            scanf("%d%lf", &ai, &ci);
            a[i][ai] = ci;
        }
    }
    int num =0;
    for(int i = 0; i<=1000; i++){
        if(a[0][i]==0) continue;
        for(int j =0; j<=1000; j++){

            if(a[1][j] == 0) continue;
            if(res[i+j]==0) num++;
            res[i+j] += a[0][i]*a[1][j];
            if(res[i+j]==0) num--;
        }
    }
    printf("%d", num);
    for(int i =MAX-1; i>=0; i--){
        if(res[i]!=0)
            printf(" %d %.1lf",i, res[i]);
    }
    printf("\n");
}
