/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-27 09:50:31
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-27 10:03:59
*/

//POJ 1159
//求当前字符串本身和其逆序的最长公共子序列

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

const int N = 5100;
char str1[N];
char str2[N];
int dp[2][N];
int len;

int LCS()
{
	memset(dp, 0, sizeof(dp));
	int e = 0;
	for(int i=1;i<=len;i++){
		e = 1-e;
		for(int j=1;j<=len;j++){
			if(str1[i] == str2[j]){
				dp[e][j] = dp[1-e][j-1] + 1;
			}else{
				dp[e][j] = max(dp[1-e][j], dp[e][j-1]);
 			}
		}
	}
	return dp[e][len];
}

int main(void)
{
	while(~scanf("%d", &len)){
		scanf("%s", str1+1);
		strcpy(str2+1, str1+1);
		reverse(str2+1, str2+len+1);
		int ans = LCS();
		printf("%d\n", len - ans);
	}
	return 0;
}