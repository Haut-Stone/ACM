/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-01-22 11:12:17
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-05-03 22:11:04
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

const int N = 1111;

int dp[N];

struct Node
{
	int l;
	int r;
	int v;
}a[N];


bool cmp(const Node &a, const Node &b)
{
	return a.l < b.l;
}

int main(void)
{
	INPUT_TEST;

	int n;
	int m;
	int r;
	scanf("%d%d%d", &n, &m, &r);
	for(int i=0;i<m;i++){
		scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].v);
	}
	sort(a, a+m, cmp);

	int ans = 0;
	for(int i=0;i<m;i++){
		int iMax = 0;
		for(int j=0;j<i;j++){
			if(a[j].r+r <= a[i].l && iMax < dp[j]){
				iMax = dp[j];
			}
		}
		dp[i] = iMax + a[i].v;
		ans = max(ans, dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}