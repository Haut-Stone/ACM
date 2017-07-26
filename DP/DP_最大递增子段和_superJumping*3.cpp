/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-13 15:57:10
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-13 15:58:40
*/

//HDU1087
//就是求一个最大上升子段和。

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

const int N = 4000;
const int INF = 99999999;

int n;
int ans;

int a[N];
int dp[N];

void init()
{
	memset(a, 0, sizeof(a));
	memset(dp, 0, sizeof(dp));
}

void read()
{
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}
}

int main(void)
{
	// INPUT_TEST;
	while(scanf("%d", &n), n != 0){
		init();
		read();
		for(int i=1;i<=n;i++){
			ans = -INF;
			for(int j=0;j<i;j++){
				if(a[i] > a[j]) ans = max(ans, dp[j]);//因为要求是上升子序列
			}
			dp[i] = ans + a[i];
		}

		ans = -INF;
		for(int i=0;i<=n;i++){
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}