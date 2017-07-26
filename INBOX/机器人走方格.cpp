/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2016 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-16 14:17:31
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-16 14:30:25
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int LEN = 1010;
const int MOD = 1e9+7;
int dp[LEN][LEN];

int main(void)
{
	int m ;
	int n ;
	int ans = 0;
	scanf("%d %d", &n, &m);
	for(int i=1;i<=m;i++){
		dp[1][i] = 1;
	}
	for(int i=1;i<=n;i++){
		dp[i][1] = 1;
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
		}
	}
	ans = dp[n][m];
	printf("%d\n", ans);
    return 0;
}