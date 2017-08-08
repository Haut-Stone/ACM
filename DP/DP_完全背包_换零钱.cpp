/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-07 15:47:37
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-07 15:48:35
*/

//https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1101
//基本的完全背包题，但是注意初始条件一定呀要给

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

const int N = 100010;
const int MOD = 1e9 + 7;

int w[15] = {0, 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
int v[15] = {0, 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
int dp[N];

int main(void)
{
	int n;
	while(~scanf("%d", &n)){
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(int i=1;i<=13;i++){
			for(int j=w[i];j<=n;j++){
				dp[j] = (dp[j] + dp[j - w[i]]) % MOD;
			}
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}