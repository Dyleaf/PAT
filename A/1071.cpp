#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string,int> s;
    string line, str;
    while(getline(cin, line))
    {
        for(int i =0; i<line.length(); i++)
        {
            if(isalnum(line[i]))
            {
                line[i] = tolower(line[i]);
                str+=line[i];
            }
            if(!isalnum(line[i]) || i == line.length()-1)
            {
                if(str.length()>0) s[str]++;
                str = "";
            }
        }

        auto k = s.begin();
        for(auto it = s.begin(); it!=s.end(); it++)
        {
            if(it->second > k->second) k =it;
            }
            cout<<k->first<<" "<<k->second<<endl;

    }
    return 0;
}
