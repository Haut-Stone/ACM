/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-09 17:00:32
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-09 17:02:06
*/

//HDU 4734
//和不要62略有些不同的变形版，这次的限制条件变成了和要小于F(A)。

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

const int N = 21;

int dp[N][200000];
int bitMapping[N];
int A, B;

int dfs(int bitNow, int sum, bool beLimited)
{
	if(sum < 0) return 0;
	
	if(bitNow == 0) return 1;
	if(!beLimited && dp[bitNow][sum] != -1) return dp[bitNow][sum];

	int res = 0;
	int the_maxNumber_bitNow_can_reach;
	if(beLimited){
		the_maxNumber_bitNow_can_reach = bitMapping[bitNow];
	}else{
		the_maxNumber_bitNow_can_reach = 9;
	}

	for(int i=0;i<=the_maxNumber_bitNow_can_reach;i++){
		res += dfs(bitNow-1,sum - i*(1<<(bitNow-1)),beLimited && i==the_maxNumber_bitNow_can_reach);
	}
	if(!beLimited) dp[bitNow][sum] = res;
	return res;
}

//计算题目中F(A)的值
int F(int x)
{
	int ans = 0;
	int all = 0;
	while(x){
		ans += (x%10) * (1<<all);
		all++;
		x /= 10;
	}
	return ans;
}

int solve(int x)
{
	int all = 0;
	while(x){
		bitMapping[++all] = x%10;
		x /= 10;
	}
	return dfs(all, F(A), true);
}

int main(void)
{
	int T;
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	for(int cas=1;cas<=T;cas++){
		scanf("%d%d", &A, &B);
		printf("Case #%d: %d\n", cas, solve(B));
	}
	return 0;
}