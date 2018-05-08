#include <bits/stdc++.h>
using namespace std;
char n1[20],n2[20];
int t,r;
long long tmp;

/*
val2为n2在k进制下的值
val2<target,return -1
val2==target,return 0
val2>target,return 1
*/
int cmp(long long*a,long long k,long long target,int len){
    long long val2=0;
    for(int i=0;i<len;i++)
        val2=val2*k+a[i];
    //val2可能存在溢出的问题，这里要注意。
    if(val2<0 || val2>target)
        return 1;
    if(val2<target)
        return -1;
    if(val2==target)
        return 0;
}
//二分搜索进制k
long long binarySearch(long long *a,long long low,long long high,long long target,int len){
    long long l=low,r=high;
    long long mid;
    while(l<=r){
        mid=(l+r)/2;
        if(cmp(a,mid,target,len)==0)
            return mid;
        if(cmp(a,mid,target,len)<0){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return -1; //impossible
}
int main()
{
    scanf("%s %s %d %d",n1,n2,&t,&r);
    if(t==2){
        swap(n1,n2); //交换一下，方便后面处理
    }
    char num[20];
    strcpy(num,n1);
    int len=strlen(num);
    long long val1=0; //转化成十进制
    for(int i=0;i<len;i++){
        if('0'<=num[i] && num[i]<='9')
            tmp=num[i]-'0';
        else if('a'<=num[i] && num[i]<='z')
            tmp=num[i]-'a'+10;
        val1=val1*r+tmp;
    }
    strcpy(num,n2);
    len=strlen(num);
    long long low=0;
    long long a[20]; //将n2的字符表示转化成数组存储
    for(int i=0;i<len;i++){
        if('0'<=num[i] && num[i]<='9')
            tmp=num[i]-'0';
        else if('a'<=num[i] && num[i]<='z')
            tmp=num[i]-'a'+10;
        a[i]=tmp;
        if(tmp>low)
            low=tmp;
    }
    low=low+1;
    long long high=max(low,val1)+1;
    long long ans=binarySearch(a,low,high,val1,len);
    if(ans==-1)
        printf("Impossible\n");
    else
        printf("%lld\n",ans);
    return 0;
}
