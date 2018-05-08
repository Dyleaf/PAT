#include <bits/stdc++.h>
using namespace std;

const int maxn = 10001;

struct Recoder{
    int type; //0 means on-line
    char  name[23] ;
    int month, day, hour, min;
    int totol;
    bool operator<(const Recoder &tmp)const {
        if(strcmp(name,tmp.name)!=0){
            return strcmp(name,tmp.name)<0;
        }else
            return totol<tmp.totol;
    }
}recoder[maxn], ans[maxn];



int rate[24];

double Cost(int tt){
    int i,cost=0,hours=tt/60,minutes=tt%60;
    for(i=0;i<hours;i++)
        cost+=rate[i%24]*60;
    cost+=rate[hours%24]*minutes;
    return (double)cost/100;
}

int main()
{

    int n;
    for(int i =0; i<24;i++){
        scanf("%d", &rate[i]);
    }

    scanf("%d", &n);
    char type[10];
    for(int i =0; i<n; i++){
        scanf("%s %d:%d:%d:%d %s",recoder[i].name, &recoder[i].month,&recoder[i].day,&recoder[i].hour,&recoder[i].min, type);
        if(strcmp(type, "on-line")==0){
            recoder[i].type=0;
        }else{
            recoder[i].type=1;
        }
        recoder[i].totol = recoder[i].min+recoder[i].hour*60+recoder[i].day*60*24;
    }
    sort(recoder,recoder+n);

    int pair=0, cnt =0;
    for(int i =1; i<n; i++){
        if(recoder[i-1].type==0 && recoder[i].type==1
                && strcmp(recoder[i-1].name, recoder[i].name)==0){
            ans[cnt++] = recoder[i-1];
            ans[cnt++] = recoder[i];
            i++;
        }
    }


    double mount = 0, cost = 0;
    if(cnt>0){
    for(int i=0; i<cnt; i++){
        if(i==0){
            printf("%s %02d\n",ans[i].name,ans[i].month);
        }else{
            if(strcmp(ans[i].name, ans[i-1].name)!=0){
                 printf("Total amount: $%.2lf\n",mount);
                 mount = 0;
                 printf("%s %02d\n",ans[i].name,ans[i].month);
            }
        }
        if(i+1<n){
            cost = Cost(ans[i+1].totol) - Cost(ans[i].totol);
            mount+=cost;
             printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", ans[i].day,ans[i].hour,ans[i].min,ans[i+1].day,ans[i+1].hour,ans[i+1].min, ans[i+1].totol-ans[i].totol, cost);
             i++;
        }
    }
        printf("Total amount: $%.2lf\n",mount);
    }
}
