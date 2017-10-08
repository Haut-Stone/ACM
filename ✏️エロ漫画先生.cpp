/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-04 20:46:48
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-05 19:57:47
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

const int N = 10;

int dp[N];
int value[N];
int weight[N];
int cnt[N];



int main(void)
{
	int n, m;
	while(~scanf("%d%d", &n, &m)){
		memset(dp, 0, sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d", &value[i], &weight[i], &cnt[i]);
		}
		for(int i=1;i<=n;i++){
			for(int k=1;k<=cnt[i];k++){
				for(int j=m;j>=weight[i];j--){
					dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
				}
			}
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}