/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-06-03 12:15:58
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-08-09 13:17:12
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

int a[10];//用来存放数字的每一位
int dp[10][2];//第一维带表数字的位数，第二维表示他的上一位是不是6

int dfs(int len,int preIsSix,int limit)
{
	if(!len) return 1;
	if(!limit && dp[len][preIsSix] != -1) return dp[len][preIsSix];
	int res = 0,n = limit ? a[len] : 9;
	for(int nowNumber=0;nowNumber<=n;nowNumber++){
		if(nowNumber == 4 || (preIsSix && nowNumber == 2)) continue;
		printf("dfs(%d,%d,%d)\n", len-1, nowNumber==6, (limit&&nowNumber == n));
		res += dfs(len-1,nowNumber == 6,limit && nowNumber == n);
	}
	if(!limit) dp[len][preIsSix] = res;
	return res;
}
int sum(int x)//表示从1到x有多少个符合条件的数字
{
	int len = 0;
	while(x)
	{
		a[++len] = x % 10;
		x /= 10;
	}
	return dfs(len,false,true);
}

int main(void)
{
	memset(dp,-1,sizeof(dp));
	int a,b;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(!a && !b)
			break;
		printf("%d\n",sum(b) - sum(a-1));//两者相减就得到区间中的个数了
	}
	
	return 0;
}