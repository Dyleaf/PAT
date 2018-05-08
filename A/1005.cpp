#include <bits/stdc++.h>
using namespace std;


char table[10][100] ={"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(){

	char input[1000];
	while(scanf("%s",input)!=EOF){
		int len= strlen(input);
		int tol= 0;
		for(int i = 0; i<len; i++){
			tol+=input[i]-'0';
		}

		stack<int> res;

		if(tol==0)
			printf("%s\n", table[0]);
		while(tol!=0){
			int cur = tol%10;
			res.push(cur);
			tol/=10;
		}

		while(!res.empty()){
			int t = res.top();
			if(res.size()>1){
				printf("%s ", table[t]);
			}else{
				printf("%s\n", table[t]);
			}
			res.pop();
		}
	}
	return 0;
}
