#include <bits/stdc++.h>
using namespace std;

map<string,set<int> > title, author, key, pub, year;

void query(map<string, set<int> > & m, string & key)
{
    if(m.find(key)!= m.end())
    {
        for(auto it = m[key].begin(); it!=m[key].end();it++)
        {
            printf("%07d\n", *it);
        }
    }else {
        printf("Not Found\n");
    }
}
int main()
{
    int n, m, id, num;
    scanf("%d",&n);
    string stitle, sauther, skey, spub, syear;
    for(int i=0;i<n; i++) {
        scanf("%d\n", &id);
        getline(cin,stitle);
        title[stitle].insert(id);
        getline(cin,sauther);
        author[sauther].insert(id);
        while(cin>>skey)
        {
            key[skey].insert(id);
            char c = getchar();
            if(c == '\n') break;
        }
        getline(cin, spub);
        pub[spub].insert(id);
        getline(cin, syear);
        year[syear].insert(id);
    }
    scanf("%d", &m);

    string temp;
    for(int i=0; i<m; i++)
    {
        scanf("%d: ",&num);
        getline(cin, temp);
        cout << num << ": " << temp << "\n";
        if(num==1)query(title, temp);
        else if(num==2)query(author, temp);
        else  if(num==3)query(key, temp);
        else  if(num==4)query(pub, temp);
        else  if(num==5)query(year, temp);

    }
    return 0;
}
