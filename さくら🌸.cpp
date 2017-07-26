/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-01-22 11:12:17
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-07-26 11:21:47
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

const int N = 400;

int dp[N][N];
int n;

int main(void)
{
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			scanf("%d", &dp[i][j]);
		}
	}

	for(int i=n-2;i>=0;i--){
		for(int j=i-1;j>=0;j--){
			dp[i][j] += max(dp[i+1][j], dp[i+1][j+1]);
		}
	}
	printf("%d\n", dp[0][0]);
}