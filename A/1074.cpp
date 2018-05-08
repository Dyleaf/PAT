#include <bits/stdc++.h>
using namespace std;


const int maxn = 100001;

int main(){
    int first,n,m,cnt = 0;
    cin>>first>>n>>m;
    int temp, list[maxn], data[maxn],next[maxn],result[maxn];
    for(int i=0; i<n; i++){
        cin>>temp;
        cin>>data[temp]>>next[temp];
    }
    while(first!=-1){
        list[cnt] = first;
        result[cnt] = list[cnt];
        cnt++;
        first = next[first];
    }
    for (int i = 0; i < (cnt - cnt % m); i++)
        result[i] = list[i / m * m + m - 1 - i % m];
    for (int i = 0; i < cnt - 1; i++)
        printf("%05d %d %05d\n", result[i], data[result[i]], result[i + 1]);
    printf("%05d %d -1", result[cnt - 1], data[result[cnt - 1]]);
    return 0;
}
