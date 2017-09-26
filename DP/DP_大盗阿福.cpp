/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-09-24 08:56:08
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-09-26 17:45:57
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

const int N = 100000 + 10;

int dp[N];
int n;
int solo;

int main(void)
{
	int T;
	scanf("%d", &T);
	while(T--){
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		if(n == 1){
			scanf("%d", &dp[0]);
			printf("%d\n", dp[0]);
			continue;
		}
		scanf("%d%d", &dp[0], &dp[1]);
		dp[1] = max(dp[0], dp[1]);
		for(int i=2;i<n;i++){
			scanf("%d", &solo);
			dp[i] = max(dp[i-1], dp[i-2]+solo);
		}
		printf("%d\n", dp[n-1]);
	}
	return 0;
}
