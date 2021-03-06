/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-02 22:23:35
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-27 10:36:40
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

#define INPUT_TEST freopen("in.txt", "r", stdin)
const int N = 1000005;

int dp[N];
int power[25];
int n;

int main(void)
{
	// INPUT_TEST;

	power[0] = 1;
	for(int i=1;i<=24;i++){
		power[i] = power[i-1]<<1;//构造2的次方
	}

	while(~scanf("%d", &n)){
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(int i=0;i<=24 && power[i] <= n;i++){
			for(int j=power[i];j<=n;j++){
				dp[j] = (dp[j] + dp[j-power[i]]) % 1000000000;
			}
		}
		printf("%d\n", dp[n]);
	}
    return 0;
}