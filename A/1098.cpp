#include <bits/stdc++.h>
using namespace std;

vector<int> a,b;

void downadject(int low,int high){
    int i = 1, j = i*2;
    while(j<=high){
        if(j+1<=high && b[j]<b[j+1])
            j = j+1;
        if(b[i]< b[j]){
            swap(b[i], b[j]);
            i = j; j = i*2;
        }else{
            break;
        }
    }
}


int main(){
    int n, cur = 2;// let begin index = 1 for heap sort
    scanf("%d",&n);
    a.resize(n+1);
    b.resize(n+1);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    for(int i=1; i<=n; i++){
        scanf("%d", &b[i]);
    }
    while(cur <=n && b[cur] >= b[cur-1]) cur++;
    int index = cur;
    while(cur <=n && a[cur] == b[cur]) cur++;
    if(cur == n+1){
        printf("Insertion Sort\n");
        sort(b.begin(), b.begin()+index+1);
        printf("%d",b[1]);
        for(int i = 2; i<=n; i++){
            printf(" %d",b[i]);
        }
    }else{
        printf("Heap Sort\n");
        cur = n;
        while(cur>=2 && b[cur]>=b[cur-1]) cur--;
        swap(b[1], b[cur]);
        downadject(1, cur-1);
        printf("%d",b[1]);
        for(int i = 2; i<=n; i++){
            printf(" %d",b[i]);
        }
    }
}
