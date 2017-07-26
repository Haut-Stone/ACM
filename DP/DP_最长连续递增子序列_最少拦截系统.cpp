/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-15 20:52:09
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-15 20:53:04
*/

//HDU 1275
//其实分析完问题后，就是求最长连续递增子序列的长度


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

const int N = 3000;

int n;
int height[N];
int dp[N];

int main(void)
{	
	INPUT_TEST;
	while(cin>>n){
		for(int i=0;i<n;i++){
			scanf("%d", &height[i]);
			dp[i] = 1;
		}	
		for(int i=1;i<n;i++){
			for(int j=0;j<i;j++){
				if(height[i] > height[j]){
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		int ans = -1;
		for(int i=0;i<n;i++){
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}