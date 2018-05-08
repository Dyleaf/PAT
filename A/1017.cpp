#include <bits/stdc++.h>
using namespace std;


const int maxn = 10001;

struct Cumtomer{
    int window;
    int arrive_time;
    int op_time;
    int wait_time;
    bool operator<(Cumtomer const  c)const {
        return arrive_time<c.arrive_time;
    }
}cus[maxn];



int main()
{
    int n,m, hh, mm, ss, i;
    scanf("%d%d", &n, &m);
    for(i =0;i<n; i++){
        scanf("%d:%d:%d %d", &hh, &mm, &ss,&cus[i].op_time);
        cus[i].arrive_time = hh*3600+mm*60+ss;
        cus[i].op_time*=60;
    }

    sort(cus, cus+n);

    int win[101],t = 0, maxtime = 17*3600;
    // 前m个wait_time =60*480
    for(int i =0;i<m; i++){
        win[i] = 60*480;
    }
    double tol = 0;
    int cur = 0;
    for(int i =0; i<n ;i++ ){
        t = 0;
        if(cus[i].arrive_time>=maxtime)
            break;
        // find the earlist
        for(int j = 0; j<m; j++){
            if(win[j]<win[t])
                t = j;
        }
        cur++;
        tol += max(0, win[t]-cus[i].arrive_time);
        win[t] =max(cus[i].arrive_time, win[t])+cus[i].op_time;
    }
    printf("%.1lf\n",tol/(60*cur)) ;
}
