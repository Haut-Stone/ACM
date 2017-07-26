/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-15 10:50:19
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-15 11:27:49
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

int dp[100001][11];//用来标记，该秒中，该位置落下了几个馅饼。

int maxInThree(int a, int b, int c)
{
	int ans;
	ans = a>b?a:b;
	ans = ans>c?ans:c;
	return ans;
}

int main(void)
{
	int n;
	int time, x;
	while(scanf("%d", &n)){
		if(n == 0) return 0;
		memset(dp, 0, sizeof(dp));
		int maxTime = 0;
		for(int i=0;i<n;i++){
			scanf("%d%d", &x, &time);
			dp[time][x]++;
			if(time > maxTime){
				maxTime = time;
			}
		}
		for(int i=maxTime-1;i>=0;i--){
			for(int j=1;j<=9;j++){
				dp[i][j] += maxInThree(dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]);//这种东西只要对i,j敏感，能在纸上画出来，在脑海中出现画面感就可以了。
			}
			dp[i][0] += max(dp[i+1][0], dp[i+1][1]);
			dp[i][10] += max(dp[i+1][10], dp[i+1][9]);
		}
		printf("%d\n", dp[0][5]);
	}
    return 0;
}