#include <bits/stdc++.h>
using namespace std;

struct student{
    int ge,gi,rank,grade, id;
    vector<int> school;
};
struct school{
    int curNum,maxNum, lastId;
    vector<int> stuId;
};
bool cmp(student a, student b){
    return a.grade == b.grade ? a.ge>b.ge:a.grade>b.grade;
}
int main(){
    int n,m,k,tmp;
    scanf("%d%d%d",&n,&m,&k);
    vector<student> stu(n);
    vector<school> sch(m);
    for(int i=0; i<m; i++){
        scanf("%d",&tmp);
        sch[i] = {0,tmp,-1};
    }
    for(int i=0; i<n; i++){
        scanf("%d %d", &stu[i].ge, &stu[i].gi);
        stu[i].grade = (stu[i].ge + stu[i].gi)/2;
        stu[i].id = i;
        stu[i].school.resize(k);
        for(int j = 0; j<k; j++){
            scanf("%d", &stu[i].school[j]);
        }
    }
    sort(stu.begin(), stu.end(), cmp);
    stu[0].rank = 1;
    for(int i = 1; i < n; i++) {
        if(stu[i].grade == stu[i - 1].grade && stu[i].ge == stu[i - 1].ge)
            stu[i].rank = stu[i-1].rank;
        else
            stu[i].rank = stu[i-1].rank + 1;
    }
    for(int i=0; i<n; i++){
        for(int it : stu[i].school){
            if(sch[it].curNum<sch[it].maxNum || (sch[it].lastId == stu[i].rank)){
                sch[it].curNum++;
                sch[it].stuId.push_back(stu[i].id);
                sch[it].lastId=stu[i].rank;
                break;
            }
        }
    }
    for(int i=0; i<m; i++){
        sort(sch[i].stuId.begin(), sch[i].stuId.end());
        for(int j=0; j<sch[i].stuId.size(); j++){
            if(j!=0) printf(" ");
            printf("%d", sch[i].stuId[j]);
        }
        printf("\n");
    }
}
