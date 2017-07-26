/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-09 16:44:06
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-09 17:22:31
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
const int N = 100010;
int dp[N][N];//表示由前j项组成的含i个字段的最大值，且最后一个字段以nun[j]结尾。
int a[N];
int perMax[N];

int n;
int m;

int DP(int n, int m)
{
	
}

int main(void)
{

	while(~scanf("%d %d", &m, &n)){
		for(int i=1;i<=n;i++){
			scanf("%d", &a[i]);
			perMax[i] = 0;
		}
		printf("%d\n", DP(n, m));
	}
    return 0;
}