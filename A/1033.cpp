// 這題在處理的時候需要注意的是
// 首先判斷是否第一個點的距離爲0
// 其次判斷的過程需要採用貪心
// 设置maxdis作为目前能到达的最远点
// 在maxdis内寻找是否有下一个站点
//    如果有判断是否能到达
//Ⅰ此范围内有加油站

//    ①有比当前站点便宜的加油站，因为只从最小的局部考虑问题，如果有多个比当前便宜的，到达那个最近的而不是最便宜的（只需要在找到第一个比S便宜的站点时break即可）。

//    ②全部比S更贵（易错点）

//        2.1 如果从S无法到达终点，则选择最便宜的那个，从S加满油到达那个站点。

//        2.2 如果从S可以直接到达终点，则从S加油至能到达终点，直接开到终点。

//此范围内无加油站

//    ①如果从S可以直接到达终点，则加到能到达终点，直接到达。

//    ②如果从S无法到达终点，加满油，能跑多远跑多远。

#include <bits/stdc++.h>
using namespace std;

struct station{
    double price;
    double distance;
}sta[1000];

bool cmp(station a, station b){
    return a.distance < b.distance;
}
int main(){
    double  tank = 0, distance, avgcost;
    double curgas = 0,tolcost = 0,curdis =0,maxdis;
    int gasnum, nowidx=0;

    scanf("%lf%lf%lf%d",&tank, &distance, &avgcost, &gasnum);
    for(int i=0; i<gasnum; i++){
        scanf("%lf%lf", &sta[i].price, &sta[i].distance);
    }
    sort(sta, sta+gasnum, cmp);

    if(sta[0].distance != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    while(curdis < distance){
        int minidx = nowidx,j;
        bool findstation = false;
        maxdis = tank*avgcost+curdis;
        for(j = nowidx+1; j<gasnum; j++){
            if(sta[j].distance<= maxdis){
                findstation = true;
                if(sta[j].price<sta[minidx].price){
                    minidx = j;
                    break;
                }
            }else{
                break;
            }
        }
        //沒有可到達點
        if(!findstation){
            if(distance<=maxdis){
                double need = (distance-curdis)/avgcost;
                tolcost  = need>curgas? tolcost+(need-curgas)*sta[nowidx].price : tolcost;
                printf("%0.2lf",tolcost);
            }else{
                curdis+=tank*avgcost;
                printf("The maximum travel distance = %0.2lf", curdis);
            }
            return 0;
        }
        //沒有便宜的
        if(minidx == nowidx){
            // if can go to destinaction
            if(maxdis>=distance){
                double need = (distance-curdis)/avgcost;
                tolcost  = need>curgas? tolcost+(need-curgas)*sta[nowidx].price : tolcost;
                printf("%0.2lf",tolcost);
                break;
            }else{
                // go to the cheapest station
                int nextidx = minidx+1;
                for(int i=nextidx; i<gasnum && sta[i].distance<=maxdis; i++){
                    if(sta[i].price<sta[nextidx].price) nextidx = i;
                }
                double need = (sta[nextidx].distance-curdis)/avgcost;
                tolcost+=(tank-curgas)*sta[nowidx].price;
                curgas = tank-need;
                curdis=sta[nextidx].distance;
                nowidx = nextidx;
            }
        }else {
            double need = (sta[minidx].distance-curdis)/avgcost;
            if(need > curgas){
                tolcost +=(need-curgas)*sta[nowidx].price;
                curgas=0;
            }else{
                curgas-=need;
            }
            curdis = sta[minidx].distance;
            nowidx=minidx;
        }
    }
    return 0;
}
