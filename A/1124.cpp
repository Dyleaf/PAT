#include <bits/stdc++.h>
using namespace std;
int main()
{
    int M,N,S;
    while(cin >> M >> N >> S)
    {
       vector<string> List(M + 1);
       map<string,int> dic;
       bool hasWinner = false;
       for(int i = 1;i <= M;i++)
       {
           cin >> List[i];
       }

       for(int i = S;i <= M;i += N)
       {
           while(dic.count(List[i]) > 0 && i <= M) i++;
           if(i > M) break;
           hasWinner = true;
           cout << List[i] << endl;
           dic[List[i]]++;
       }
       if(!hasWinner)
          cout << "Keep going..." << endl;
    }
}
