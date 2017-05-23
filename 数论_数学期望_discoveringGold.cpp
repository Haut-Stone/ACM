/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-21 17:50:25
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-21 17:50:37
*/

//LightOJ 1030
//求期望值，具体的题解见印象笔记。
//该题的数学期望 = 每一点的概率 * 到该点的值

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

const int N = 10100;
const int INF = 99999999;

double dp[N];

int main(void)
{
	// INPUT_TEST;
	
	int T;
	int cas = 1;
	int n;
	int a[N];

	cin>>T;
	while(T--){
		cin>>n;
		memset(dp, 0, sizeof(dp));
		double sum = 0.0;

		for(int i=1;i<=n;i++){
			cin>>a[i];
		}

		dp[1] = 1;

		for(int i=1;i<=n;i++){
			int x = (n-i<6 ? n-i : 6);
			for(int j=1;j<=x;j++){
				dp[i+j] += dp[i]*1.0/x;
			}
			sum += dp[i] * a[i];
		}
			
		printf("Case %d: %.10f\n", cas++, sum);

	}
	return 0;
}