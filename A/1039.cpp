#include <bits/stdc++.h>
using namespace std;

int getid(char * name)
{
    int id = 0;
    for(int i = 0; i<3; i++)
        id  =  id*26+ name[i] - 'A';
    id = id*10 + name[3]-'0';
    return id;
}
int main()
{
    map<int,vector<int> > stu;
    int n, k, classid, num,id;
    scanf("%d%d", &n, &k);
    char name[5];
    for(int i = 0; i< k; i++){
        scanf("%d%d",&classid, &num);
        for(int i = 0; i<num; i++){
            scanf("%s", name);
            id = getid(name);
            stu[id].push_back(classid);
        }
    }
    for(int i = 0; i<n; i++){

            scanf("%s", name);
       id = getid(name);
        vector<int> &v= stu[id];
        int len = v.size();
        printf("%s %d", name, len);
        sort(v.begin(), v.end());
        for(int i =0; i<len; i++)
        {
             printf(" %d", v[i]);
        }
        printf("\n");
    }
}
