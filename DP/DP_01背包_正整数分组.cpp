/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-07 14:26:50
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-07 14:27:55
*/

//哇，这么简单的题，我怎么还是看不出来意思呢。
//只要求到一半重量的最大价值就行了。简单的01背包问题。

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

const int N = 200;

int w[N];
int v[N];
int dp[N];
int sum;

int main(void)
{
	int n;
	while(~scanf("%d", &n)){
		sum = 0;
		for(int i=1;i<=n;i++){
			scanf("%d", &w[i]);
			v[i] = w[i];
			sum += w[i];
		}
		memset(dp, 0, sizeof(dp));
		int capacity = sum / 2;
		for(int i=1;i<=n;i++){
			for(int j=capacity;j>=w[i];j--){
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			}
		}
		printf("%d\n", abs(sum - dp[capacity] - dp[capacity]));
	}
	return 0;
}