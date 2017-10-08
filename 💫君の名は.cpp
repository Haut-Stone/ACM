/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
*
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-03 12:15:58
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-04 17:53:24
*/

#include <iostream>
using namespace std;
#define MAX 100

int vals[MAX];
int weis[MAX];
int dp[MAX][MAX];

int main() {
	int n, wei;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &weis[i], &vals[i]);
	}
	scanf("%d", &wei);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= wei; j++) {
			if (j - weis[i] > 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weis[i]] + vals[i]);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	printf("%d\n", dp[n][wei]);

	return 0;
}