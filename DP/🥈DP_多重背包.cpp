/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-08 19:35:38
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-08 20:00:38
*/

//https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1086
//背包问题v2，很有价值的一道题。

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

const int N = 500010;

struct Node
{
	int weight;
	int value;
	int number;
}a[N];

int n, m;
int w1, p1;
int dp[N];

int main(void)
{
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++){
		scanf("%d%d%d", &a[i].weight, &a[i].value, &a[i].number);
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=a[i].number;j=j<<1){
			w1 = j*a[i].weight;//像取苹果一样的二进制枚举
			p1 = j*a[i].value;
			for(int k=m;k>=w1;k--){
				dp[k] = max(dp[k], dp[k - w1] + p1);
			}
			a[i].number -= j;//已经处理过的情况就剪掉
		}
		w1 = a[i].number * a[i].weight;//这里是处理二进制中处理不到的多余部分
		p1 = a[i].number * a[i].value;
		for(int k=m;k>=w1;k--){
			dp[k] = max(dp[k], dp[k - w1] + p1);
		}
	}
	printf("%d\n", dp[m]);
	return 0;
}