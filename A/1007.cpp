#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[10010], k;
    scanf("%d", &k);
    bool flag = true;
    for(int i = 0; i<k; i++){
        scanf("%d", &a[i]);
        if(a[i]>=0) flag = false;
    }

    int begin = 0 , end = 0, max = -1, temp = 0;
    int t_begin = 0;
    for(int i = 0; i< k; i++)
    {
        temp = temp+a[i];
        if(temp>max){
            max = temp;
            begin = t_begin;
            end = i;
        }else if(temp<0){
            temp = 0;
            t_begin = i+1;
        }
    }
    if(flag){
        printf("0 %d %d\n", a[0], a[k-1]);
    }else{
      printf("%d %d %d\n", max, a[begin], a[end]);
    }
}
