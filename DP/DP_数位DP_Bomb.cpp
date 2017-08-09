/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-09 15:31:56
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-09 15:32:52
*/

//HDU 3555
//不多说，正难则反，把49去掉就好了，直接用不要62的模版就行了。

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

const long long N = 110;

long long dp[N][N];
long long bitMapping[N];

long long dfs(long long bitNow, bool preBitIs4, bool beLimited)
{
	if(bitNow == 0) return 1;
	if(!beLimited && dp[bitNow][preBitIs4] != -1) return dp[bitNow][preBitIs4];
	
	long long the_maxNumber_bitNow_can_reach = 0;
	long long res = 0;
	if(beLimited){
		the_maxNumber_bitNow_can_reach = bitMapping[bitNow];
	}else{
		the_maxNumber_bitNow_can_reach = 9;
	}
	
	for(long long i=0;i<=the_maxNumber_bitNow_can_reach;i++){
		if(preBitIs4 && i == 9) continue;
		res += dfs(bitNow-1, i == 4, beLimited && i == the_maxNumber_bitNow_can_reach);
	}
	
	if(!beLimited) dp[bitNow][preBitIs4] = res;
	return res;
}

long long solve(long long x)
{
	long long all = 0;
	while(x){
		bitMapping[++all] = x%10;
		x /= 10;
	}
	return dfs(all, false, true);
}

int main(void)
{
	long long r;
	long long T;
	memset(dp, -1, sizeof(dp));
	while(~scanf("%lld",&T)){
		for(long long i=0;i<T;i++){
			scanf("%lld", &r);
			printf("%lld\n", r - solve(r) + solve(0));
		}
	}
	return 0;
}