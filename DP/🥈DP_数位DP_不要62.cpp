/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-09 13:47:48
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-09 14:33:56
*/

//这题我理解了一上午，现在终于会做了，写一篇题解加深一下记忆。
//

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
int bitMapping[N];
int l, r;

int dfs(int bitNow, bool preBitIs6, bool beLimited)
{
	if(bitNow == 0) return 1;
	if(!beLimited && dp[bitNow][preBitIs6] != -1) return dp[bitNow][preBitIs6];

	int res = 0;

	int the_maxNumer_bitNow_can_reach;
	if(beLimited){
		the_maxNumer_bitNow_can_reach = bitMapping[bitNow];
	}else{
		the_maxNumer_bitNow_can_reach = 9;
	}

	for(int i=0;i<=the_maxNumer_bitNow_can_reach;i++){
		if(i == 4 || (preBitIs6 && i == 2)) continue;
		res += dfs(bitNow-1, i==6, beLimited && i == the_maxNumer_bitNow_can_reach);
	}

	if(!beLimited) dp[bitNow][preBitIs6] = res;
	return res;
}

int solve(int x)
{
	int all = 0;
	while(x){
		bitMapping[++all] = x%10;
		x /= 10;
	}
	return dfs(all, false, true);
}

int main(void)
{	
	memset(dp, -1, sizeof(dp));
	while(~scanf("%d%d", &l, &r)){
		if(l == 0 && r == 0) break;
		printf("%d\n", solve(r) - solve(l-1));
	}
	return 0;
}