#include <bits/stdc++.h>
using namespace std;

const int maxn  = 10000;

struct Recoder{
    int hh,mm, ss, tol;
    int type;
    char plate[8];
}r[maxn], ans[maxn];


bool cmp(Recoder a, Recoder b){
    if(strcmp(a.plate, b.plate)==0) return a.tol<b.tol;
    else return strcmp(a.plate, b.plate)< 0;
}
bool cmpTime(Recoder a, Recoder b){
    return a.tol < b.tol;
}

int main()
{
    int n, m;
    scanf("%d%d",&n, &m);
    char plate[8], type[4];
    int hh, mm, ss;
    for(int i =0; i<n; i++ )
    {
        scanf("%s %d:%d:%d %s", r[i].plate, &r[i].hh, &r[i].mm, &r[i].ss,type);
        r[i].type = strcmp("in", type) ==0? 1:-1;
        r[i].tol =r[i].hh*3600 + r[i].mm*60 + r[i].ss;
    }

    sort(r, r+n, cmp);
    int pair = 0, cur = 0, maxtime = 0;
    map<string, int > mapr;
    for(int i = 1; i< n; i++ )
    {
        if(strcmp(r[i].plate, r[i-1].plate)==0 && r[i].type == -1 && r[i-1].type==1){
            ans[cur++] = r[i-1];
            ans[cur++] = r[i];
            mapr[r[i].plate] += r[i].tol - r[i-1].tol;
            if(maxtime < mapr[r[i].plate]) maxtime = mapr[r[i].plate];
        }
    }
    vector<int>cnt(cur-1);
    sort(ans, ans+cur, cmpTime);
    for(int i =0; i<cur; i++)
    {
        if(i==0) cnt[i]  += ans[i].type;
        else cnt[i] += ans[i].type + cnt[i-1];
    }

    for(int i = 0; i<m; i++)
    {
        scanf("%d:%d:%d", &hh, &mm,&ss);
        int tol = hh*3600+ mm*60 + ss,k = 0;
        while(k< cur && tol >= ans[k].tol) k++;
        if (k == cur) printf("%d\n", cnt[cur-1]);
        else if(k==0) printf("%d\n", 0);
        else printf("%d\n", cnt[k-1]);

    }
    for(auto it = mapr.begin(); it!=mapr.end(); it++)
    {
        if(it->second == maxtime) cout<<it->first<<" ";
    }
    printf("%02d:%02d:%02d\n",maxtime/3600, maxtime/60%60, maxtime %60);
    return 0;
}
