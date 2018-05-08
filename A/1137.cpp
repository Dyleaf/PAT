#include <bits/stdc++.h>
using namespace std;


struct stu{
    string name;
    int gp,gm,gf,g;
};


bool cmp(stu a, stu b){
    return a.g != b.g? a.g>b.g: a.name<b.name;
}

int main(){
    int p, m, n,score, cnt = 1;
    cin>>p>>m>>n;
    string s;
    vector<stu> v;
    map<string, int>idx;
    for(int i =0; i<p; i++)
    {
        cin>>s>>score;
        if(score>=200)
        {
            v.push_back(stu{s,score, -1, -1,0});
            idx[s] = cnt++;
        }
    }
    for(int i =0; i<m; i++)
    {
        cin>>s>>score;
        if(idx[s] !=0) v[idx[s] -1].gm = score;
    }
    for(int i = 0; i<n; i++)
    {
        cin>>s>>score;
        if(idx[s] != 0)
        {
            int index = idx[s] -1;
            v[index].gf = v[index].g = score;
            if(v[index].gm > v[index].gf) v[index].g = int (v[index].gm*0.4 + v[index].gf*0.6 +0.5);
        }
    }
    vector<stu> ans;
    for(int i =0; i< v.size(); i++)
        if(v[i].g >=60 ) ans.push_back(v[i]);
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++)
        printf("%s %d %d %d %d\n", ans[i].name.c_str(), ans[i].gp, ans[i].gm, ans[i].gf, ans[i].g);
    return 0;
}
