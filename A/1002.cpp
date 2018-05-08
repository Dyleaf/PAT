#include <bits/stdc++.h>
using namespace std;
const int length = 1010;

int main()
{
    double N[length] = {0};
    int lineNum, ai, i;
    double ci;

    for( i =0; i<2; i++){
    	scanf("%d", &lineNum);
	    for(int j = 0; j<lineNum; j++){
		    cin>>ai>>ci;
		    N[ai] += ci;
	    }
    }
    int tol = 0;
    for(i = 0; i<length; i++){
        if(N[i]!=0){
            tol++;
        }
    }
    printf("%d",tol);
    for(i = length-1;i>=0; i--){
	    if(N[i]!=0)
        printf(" %d %.1lf", i, N[i]);
    }
    printf("\n");
}
