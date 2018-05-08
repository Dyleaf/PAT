#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;

struct Customer{
    int window ;
    int start_time;
    int end_time ;
    int preocess_time;
    Customer():start_time(0),end_time(0){}
    bool operator<(const Customer c)const{
        //在结束时间相等的情况下，选择窗口id'小的
        if(end_time==c.end_time){
            return window>c.window;
        }else{
            return end_time>c.end_time;
        }
    }
}cus[1001];

int main(){
    int n,m,k,q;
    priority_queue<Customer> queueLine;
    scanf("%d%d%d%d",&n,&m,&k,&q);

    for(int i =1; i<=k; i++){
        scanf("%d", &cus[i].preocess_time);
    }

    int cur = 0; //当前的顾客
    Customer tmp;
    int window_free[maxn];
    memset(window_free, 0 , sizeof(window_free));

    //将m*n的顾客放入
    for(int i =1; i<=m && cur<k;i++){
        for(int j =1;j<=n && cur<k; j++){
            cur++;
            Customer& c = cus[cur];
            c.start_time = window_free[j];
            c.end_time = window_free[j] = c.start_time+c.preocess_time;
            c.window = j;
            queueLine.push(c);
        }
    }

    for(int i = cur+1; i<=k; i++){
        tmp = queueLine.top();
        queueLine.pop();
        Customer &c = cus[i];
        c.window = tmp.window;
        c.start_time = window_free[tmp.window];
        c.end_time = window_free[tmp.window] = c.start_time+c.preocess_time;
        queueLine.push(c);
    }

    int max_time = 540;
    int id =0;
    while(q--){
        scanf("%d", &id);
        Customer &c = cus[id];
        if(c.start_time>=max_time){
            printf("Sorry\n");
        }else{
            printf("%02d:%02d\n",c.end_time/60+8, c.end_time%60);
        }

    }
}
