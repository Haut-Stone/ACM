/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-22 11:12:17
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-22 21:58:30
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 110;

int main(void)
{
	int m,n;
	int dp[N][N];
	int raw[N][N];
	//m row n col
	while(scanf("%d%d", &m, &n) != EOF){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				scanf("%d", &raw[i][j]);
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + raw[i][j];
			}
		}
		printf("%d\n", dp[m][n]);
	}
	return 0;
}