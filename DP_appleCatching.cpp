/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-03 13:13:01
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-03 13:36:28
*/

//http://poj.org/problem?id=2385
//DP,找出状态转移方程即可

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
using namespace std;

#define INPUT_TEST freopen("in.txt", "r", stdin)

const int N = 1111;

int dp[N][N];//表示在第i分钟时，已经移动了j次后得到的苹果的数量
int a[N];

int main(void)
{
	// INPUT_TEST;

	int t;
	int w;
	while(~scanf("%d%d", &t, &w)){
		for(int i=1;i<=t;i++){
			scanf("%d", &a[i]);
		}

		//在第一棵树下
		if(a[1] == 1){
			dp[1][0] = 1;
			dp[1][1] = 0;
		}else{
			dp[1][0] = 0;
			dp[1][1] = 1;
		}

		for(int i=2;i<=t;i++){
			for(int j=0;j<=w;j++){
				if(j == 0){
					dp[i][j] = dp[i-1][j] + a[i]%2;//不走的话，就看当前的树这个时候掉不掉苹果
				}else{
					dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]);
					if(j%2+1 == a[i]) dp[i][j]++;
				}
			}
		}
		int ans = 0;
		for(int i=0;i<=w;i++){
			ans = max(ans, dp[t][i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}