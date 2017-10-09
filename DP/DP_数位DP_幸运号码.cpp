/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-09 20:51:31
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-09 20:52:11
*/

//一道神奇的数位dp题
//https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1043

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

const int N = 1010;
const int MOD = 1e9 + 7;

long long dp[2][N*9];

int main(void)
{
	int n;
	memset(dp, 0, sizeof(dp));
	scanf("%d", &n);
	dp[0][1] = 1;
	for(int i=0;i<10;i++){
		dp[1][i] = 1;
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<=i*9;j++){
			long long sum = 0;
			for(int k=0;k<10;k++){
				if(j >= k){
					sum = (sum + dp[(i-1)&1][j-k]) % MOD;
				}
			}
			dp[i&1][j] = sum;
		}
	}
	long long ans = 0;
	for(int i=0;i<=n*9;i++){
		ans = (ans + dp[n&1][i]*(dp[n&1][i] - dp[(n-1)&1][i])) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}
