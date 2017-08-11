/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-11 11:28:44
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-11 11:31:01
*/

//POJ 2955
//这题。。。md本来想完全自己做，结果思路还是错了，看题解吧

#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#define INPUT_TEST freopen("in.txt", "r", stdin)
using namespace std;

const int N = 110;
int dp[N][N];

void solve(char brucket[], int len){
	memset(dp, 0, sizeof(dp));
	for(int k=1;k<len;k++){
		for(int l=0,r=k;r<len;l++, r++){
			if((brucket[l]=='(' && brucket[r]==')') || (brucket[l]=='[' && brucket[r]==']')){
				dp[l][r] = dp[l+1][r-1] + 2;
			}
			for(int m=l;m<r;m++){
				dp[l][r] = max(dp[l][r], dp[l][m] + dp[m+1][r]);
			}
		}
	}
	printf("%d\n", dp[0][len-1]);
}

int main(void)
{
	char brucket[N];
	while(scanf("%s", brucket)){
		if(strcmp(brucket, "end") == 0) break;
		int len = (int)strlen(brucket);
		solve(brucket, len);
	}
	return 0;
}