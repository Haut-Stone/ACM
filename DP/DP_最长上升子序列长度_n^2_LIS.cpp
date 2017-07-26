/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-16 18:02:36
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-17 17:23:14
*/

//POJ 2533
//输出最长递增子序列的长度。n^2 的复杂度

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

const int N = 1010;
int n;
int a[N];
int dp[N];//表示以第i个数结尾的最大子序列长度
int ans;
int iMax;
int maxLen;

int LIS()
{
	maxLen = 1;
	dp[1] = 1;
	for(int i=2;i<=n;i++){
		iMax = 0;
		for(int j=1;j<i;j++){//依次搜索前面的
			if(a[j] < a[i] && dp[j] > iMax){
				iMax = dp[j];
			}
			dp[i] = iMax + 1;
			if(maxLen < dp[i]){
				maxLen = dp[i];
			}
		}
	}
	return maxLen;
}

int main(void)
{
	// INPUT_TEST;

	while(~scanf("%d", &n)){
		memset(dp, 0, sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d", &a[i]);
		}
		ans = LIS();
		printf("%d\n", ans);
	}
	return 0;
}

