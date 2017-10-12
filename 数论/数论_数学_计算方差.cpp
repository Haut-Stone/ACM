/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-12 18:03:06
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-12 18:03:58
*/

//数据比较大，注意最大值，和数据类型
//https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1098

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
const long long INF = 0x3f3f3f3f3f3f3f3f;

int m, n;
int num[N];
long long sum[N];

int main(void)
{
	scanf("%d%d", &m, &n);
	sum[0] = 0;
	for(int i=1;i<=m;i++){
		scanf("%d", &num[i]);
	}
	sort(num+1, num+m+1);
	for(int i=1;i<=m;i++){
		sum[i] = sum[i-1] + num[i];
	}
	double ans = INF;
	for(int i=1;i<=m-n+1;i++){
		double temp = 0;
		double k = (sum[i+n-1] - sum[i-1]) * 1.0 / n;
		for(int j=0;j<n;j++){
			temp += (num[i+j] - k) * (num[i+j] - k);
		}
		ans = min(ans, temp);
	}
	printf("%lld\n", (long long)ans);
	return 0;
}

//
//
