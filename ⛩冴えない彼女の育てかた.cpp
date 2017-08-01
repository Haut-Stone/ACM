/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-28 19:01:10
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-01 20:01:18
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
using namespace std;

const int N = 500100;
const int INF = 99999999;

int w[N];
int v[N];
int dp[N];

void solve(int n, int m)
{
	for(int i=0;i<N;i++){
		dp[i] = -INF;
	}
	dp[0] = 0;
	for(int i=1;i<=n;i++){
		for(int j=w[i];j<=m;j++){
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	if(dp[m] > 0){
		printf("%d\n", dp[m]);
	}else{
		printf("NO\n");
	}
}

int main(void)
{
	int T;
	int n, m;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		for(int i=1;i<=n;i++){
			scanf("%d%d", &w[i], &v[i]);
		}
		solve(n, m);
	}
	return 0;
}
