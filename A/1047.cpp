#include <bits/stdc++.h>
using namespace std;

char stu[40001][5];
vector<int> course[2510];

bool cmp(int a, int b)
{
    return strcmp(stu[a], stu[b])<0;
}


int main()
{
    int n, m;
    scanf("%d%d", &n,  &m);
    char name[5];
    int num, courseid;
    for(int i = 0; i<n; i++ ){
        scanf("%s %d", name, &num);
        strcpy(stu[i], name);
        for(int j = 0; j<num; j++)
        {
            scanf("%d", &courseid);
            course[courseid].push_back(i);
        }
    }
    for(int i = 1; i<= m; i++)
    {
        printf("%d %d\n", i,(int)course[i].size() );
        sort(course[i].begin(), course[i].end(), cmp);
        for(int j =0; j< course[i].size(); j++)
        {
            printf("%s\n", stu[course[i][j]]);
        }
    }
    return 0;
}
