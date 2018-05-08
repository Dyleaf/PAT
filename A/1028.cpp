#include <bits/stdc++.h>
using namespace std;


struct Recoder{
    int id, grade;
    char name[20];
}r[100000];

int c;

bool cmp(Recoder a, Recoder b){
    if(c==1) return a.id<b.id;
    else if(c==2) return strcmp(a.name, b.name)==0? a.id<b.id : strcmp(a.name,b.name)<0;
    else if(c==3) return a.grade==b.grade ? a.id<b.id: a.grade<b.grade;
}

int main(){
    int n;
    cin>>n>>c;
    for(int i=0; i<n; i++){
        cin>>r[i].id>>r[i].name>>r[i].grade;
    }
    sort(r, r+n, cmp);
    for(int i=0; i<n; i++)
        printf("%06d %s %d\n", r[i].id, r[i].name, r[i].grade);
}
