/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-17 17:27:35
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-19 19:18:27
*/

//但是这道题，实际上用两个标记标记开头和结尾，每次剔除边上更小的数不就好了吗。。。
//

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

const int N = 3000;
int a[N];
int dp[N][N];//表示从i到j的区间中的最大值

int main(void)
{
	// INPUT_TEST;

	int n;
	int j;
	while(cin>>n){
		memset(dp, 0, sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d", &a[i]);
		}
		for(int i=1;i<=n;i++){
			dp[i][i] = a[i] * n;//按顺序从前端出队的值
		}
		
		for(int add=1;add<=n;add++){//从左端dp到右端
			for(int i=1;i+add<=n;i++){
				j = i+add;
				dp[i][j] = max(dp[i+1][j] + (n-add)*a[i], dp[i][j-1] + (n-add)*a[j]);//更长dp的状态由短的推出来
			}
		}
		printf("%d\n", dp[1][n]);
	}
	return 0;
}