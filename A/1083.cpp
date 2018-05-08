#include <bits/stdc++.h>
using namespace std;

struct Stu{
    char name[16],id[16];
    int grade;
};

bool cmp(Stu a, Stu b){
     return a.grade>b.grade;
}
int main(){
    int n, left, right;
    scanf("%d", &n);
    vector<Stu> s(n);
    for(int i=0; i<n; i++){
        scanf("%s %s %d",s[i].name, s[i].id, &s[i].grade);
    }
    scanf("%d %d", &left, &right);
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(s[i].grade >= left && s[i].grade <=right) cnt++;
        else s[i].grade = -1;
    }
    sort(s.begin(), s.end(), cmp);
    for(int i=0; i<cnt; i++){
        printf("%s %s\n", s[i].name, s[i].id);
    }
    if(cnt==0) printf("NONE\n");
}
