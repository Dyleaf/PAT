#include <bits/stdc++.h>
using namespace std;

int w=1; // the op to define cmp

struct Stu{

    int id;
    int c;
    int m;
    int e;
    int a;
    int best;
    int cc;
    int mm;
    int ee;
    int aa;
};


bool cmp(Stu a, Stu b){
    if(w==2){
        return a.c>b.c;
    }else if(w==3){
        return a.m>b.m;
    }else if(w==4){
        return a.e>b.e;
    }else{
        return a.a>b.a;
    }
}


void print(Stu s){
    char c = 'A';
    int d = s.aa;
    if(d>s.cc) c= 'C', d = s.cc;
    if(d>s.mm) c = 'M', d =s.mm;
    if(d>s.ee) c = 'E', d = s.ee;
    printf("%d %c\n", d, c);
}

int main(){

    int n, m;
    Stu s[2001];
    map<int,int>stu_map;
    scanf("%d%d", &n, &m);

    for(int i =0; i<n; i++){
        scanf("%d%d%d%d", &s[i].id, &s[i].c, &s[i].m, &s[i].e);
        s[i].a =(s[i].c+s[i].m+s[i].e)/3;
    }


    w = 2;
    sort(s,s+n, cmp);

    for(int i = 0;i<n; i++){
        if(i>0 && s[i].c==s[i-1].c)
            s[i].cc = s[i-1].cc;
        else
            s[i].cc = i+1;
    }



     w = 3;
    sort(s,s+n, cmp);
    for(int i = 0;i<n; i++){
        if(i>0 && s[i].m==s[i-1].m)
            s[i].mm = s[i-1].mm;
        else
            s[i].mm = i+1;
    }



    w = 4;
    sort(s,s+n, cmp);
    for(int i = 0;i<n; i++){
        if(i>0 && s[i].e==s[i-1].e)
            s[i].ee = s[i-1].ee;
        else
            s[i].ee = i+1;
    }

    w = 1;
    sort(s,s+n, cmp);
    for(int i = 0;i<n; i++){
        Stu ss = s[i];
        if(i>0 && s[i].a==s[i-1].a)
            s[i].aa = s[i-1].aa;
        else
            s[i].aa = i+1;
        stu_map[s[i].id] = i;
    }

   // queue
    int id;
    for(int i =0; i<m; i++){
        scanf("%d",&id);
        map<int, int >::iterator it = stu_map.find(id);
        if(it!=stu_map.end()){
            int index = it->second;
            print(s[index]);
        }else{
            printf("N/A\n");
        }
    }
}
