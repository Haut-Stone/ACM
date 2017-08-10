/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-04 20:46:48
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-10 16:16:35
*/

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

const int N = 10;

int dp[N];
int bitMapping[N];

int dfs(int bitNow, bool beLimited)
{
	if(bitNow == 0) return 1;
	if(!beLimited && dp[bitNow] != -1) return dp[bitNow];

	int the_maxNumber_bitNow_can_reach;
	if(beLimited){
		the_maxNumber_bitNow_can_reach = bitMapping[bitNow];
	}else{
		the_maxNumber_bitNow_can_reach = 9;
	}

	int ans = 0;
	for(int i=0;i<=the_maxNumber_bitNow_can_reach;i++){
		if(i == 1) continue;
		ans += dfs(bitNow - 1, beLimited && i == the_maxNumber_bitNow_can_reach);
	}

	if(!beLimited) dp[bitNow] = ans;
	return ans;
}

int solve(int x)
{
	int all = 0;
	while(x){
		bitMapping[++all] = x%10;
		x /= 10;
	}
	return dfs(all, true);
}

int main(void)
{
	int n;
	memset(dp, -1, sizeof(dp));
	while(~scanf("%d", &n)){
		printf("%d\n", solve(n) - solve(0));
	}
	return 0;
}