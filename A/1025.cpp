//这题错在了格式上最一个测试点的格式需要注意
#include <bits/stdc++.h>
using namespace std;

struct Stu{
    long long int id;
    int loc,locRank, falRank,score;
}s[1000];

bool cmp(Stu a, Stu b){
    return a.score!=b.score? a.score > b.score: a.id<b.id;
}


int main(){
    int Case, n;
    scanf("%d", &Case);
    vector<Stu> ans;
    for(int j =1; j<=Case; j++){
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%lld %d", &s[i].id,&s[i].score);
            s[i].loc = j;
        }
        sort(s, s+n, cmp);
        for(int i =0; i<n; i++){
            if(i>0 && s[i].score == s[i-1].score)
                s[i].locRank = s[i-1].locRank;
            else s[i].locRank = i+1;
            ans.push_back(s[i]);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    for(int i =0; i<ans.size(); i++){
        if(i>0 && ans[i].score == ans[i-1].score)
            ans[i].falRank = ans[i-1].falRank;
        else  ans[i].falRank = i+1;
    }
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++){
        printf("%013lld %d %d %d\n", ans[i].id, ans[i].falRank, ans[i].loc, ans[i].locRank);
    }
}
