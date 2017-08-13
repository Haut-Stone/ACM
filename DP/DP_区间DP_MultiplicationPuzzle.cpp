/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-12 11:05:13
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-12 11:06:38
*/

//区间dp的题还是主要要找出状态转移方乘。这一点还是比较烧脑子的。
//时间长了忘了就看看下面的题解吧。
//http://blog.csdn.net/libin56842/article/details/9747021

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
const int INF = 99999999;

int a[N];
int dp[N][N];

int main(void)
{
	int n;
	while(~scanf("%d", &n)){
		for(int i=1;i<=n;i++){
			scanf("%d", &a[i]);
		}
		memset(dp, 0, sizeof(dp));
		for(int k=2;k<n;k++){
			for(int i=2, j=i+k-1;j<=n;i++, j++){
				dp[i][j] = INF;
				for(int m=i;m<j;m++){
					dp[i][j] = min(dp[i][j], dp[i][m] + dp[m+1][j] + a[i-1]*a[m]*a[j]);
				}
			}
		}
		printf("%d\n", dp[2][n]);
	}
	return 0;
}