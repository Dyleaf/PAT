#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;
stack<int> s;
int c[maxn];
int lowbit(int x){
    return x & -x;
}

void update(int i, int  v){
    for(int j = i; j<maxn; j+=lowbit(j))
        c[j] +=v;
}

int getsum(int x){
    int sum = 0;
    for(int i=x; i>=1; i -= lowbit(i))
        sum+=c[i];
    return sum;
}

void  peekMedian(){
    int left = 1, right = maxn, mid, k = (s.size()+1)/2;
    while(left<right){
        mid = (left+right)/2;
        if(getsum(mid)>=k){
            right = mid;
        }else{
            left = mid+1;
        }
    }
    printf("%d\n", left);
}
int main(){
    int n, tmp;
    scanf("%d", &n);
    char str[20];
    for(int i=0; i<n; i++){
        scanf("%s", str);
        if(str[1] ==  'u'){
            scanf("%d", &tmp);
            s.push(tmp);
            update(tmp, 1);
        }else if(str[1] == 'o'){
            if(s.empty()){
                printf("Invalid\n");
            }else{
                update(s.top(),-1);
                printf("%d\n", s.top());
                s.pop();
            }
        }else{
            if(!s.empty()){
                peekMedian();
            }else{
                printf("Invalid\n");
            }
        }
    }
    return 0;
}
