/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-12 10:09:11
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-12 10:37:57
*/

//Light oj 1422
//区间dp，但是这里要注意从后向前遍历。
//这题的dp不是很懂，看下面的链接吧
//http://www.cnblogs.com/neopenx/p/4050003.html

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

const int N = 500;

int dp[N][N]; //表示第i到j天中要换的衣服的最小件数
int a[N];

int main(void)
{
	int T;
	int n;
	int cas = 1;

	scanf("%d", &T);
	while(T--){
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		for(int i=1;i<=n;i++){
			scanf("%d", &a[i]);
			dp[i][i] = 1;//初始条件
		}
		for(int s=n-1;s>=1;s--){//从后向前遍历
			for(int e=s+1;e<=n;e++){
				dp[s][e] = dp[s+1][e] + 1;
				for(int k=s;k<=e;k++){
					if(a[s] == a[k]) dp[s][e] = min(dp[s][e], dp[s+1][k-1] + dp[k][e]);
				}
			}
		}
		printf("Case %d: %d\n", cas++, dp[1][n]);
	}
	return 0;
}